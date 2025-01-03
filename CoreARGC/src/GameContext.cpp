#include <CoreARGC/GameContext.hpp>

namespace CoreARGC {
   void GameContext::DestroyEntity(Entity* to_destroy) {
      _entities_to_remove.emplace_back(to_destroy);
   }

   std::weak_ptr<Entity> GameContext::CreateEntity(Entity* entity) {
      std::shared_ptr<Entity> clone;
      clone.reset(entity);
      clone->Start(*this);

      _entities[clone->GetType().data()].emplace_back(clone);
      return clone;
   }

   std::weak_ptr<Entity> GameContext::CreateEntity(const Entity& entity) {
      std::shared_ptr<Entity> clone = entity.Clone();
      clone->Start(*this);

      _entities[entity.GetType().data()].emplace_back(clone);
      return clone;
   }

   std::vector<std::weak_ptr<Entity>> GameContext::GetCollisionsFor(const Entity& entity) const {
      auto it = _current_collisions.find(&entity);
      if (it != _current_collisions.end()) {
         return it->second;
      }
      return {};
   }

   TextureRef GameContext::GetTexture(const std::string& id) {
      auto found = _textures.find(id);
      if (found == _textures.end())
         throw std::runtime_error("Texture with id: " + id + " doesn't exist");

      return found->second.GetRef();
   }

   TextureRef GameContext::LoadTextureAs(const std::filesystem::path& path, const std::string& id) {
      if (not std::filesystem::exists(path))
         throw std::runtime_error("Texture path: " + path.string() + " doesn't exist");

      assert(_textures.find(id) == _textures.end() && "Repeated texture");
      TextureSource& source = _textures[id] = std::move(TextureSource(path));
      return source.GetRef();
   }

   void GameContext::Update() {

      _current_collisions.clear();

      DetectCollisions();

      for (auto& pair : _entities) {
         for (auto& entity : pair.second) {
            entity->Update(*this);
         }
      }

      RemoveEntities();
   }

   void GameContext::Show() const {
      for (auto& pair : _entities) {
         for (auto& entity : pair.second) {
            entity->Show();
         }
      }
   }

   void GameContext::RemoveEntities() {
      for (Entity* entity_to_remove : _entities_to_remove) {
         for (auto& pair : _entities) {
            auto& entity_list = pair.second;

            auto it = std::remove_if(entity_list.begin(), entity_list.end(),
               [&entity_to_remove](const std::shared_ptr<Entity>& entity) {
                  return entity.get() == entity_to_remove;
               });

            if (it != entity_list.end()) {
               entity_list.erase(it, entity_list.end());
            }
         }
      }

      _entities_to_remove.clear();
   }

   void GameContext::DetectCollisions() {
      for (const auto& [type1, entities1] : _entities) {
         for (const auto& entity1 : entities1) {
            for (const auto& [type2, entities2] : _entities) {
               for (const auto& entity2 : entities2) {
                  if (entity1 != entity2 && entity1->CollideWhith(*entity2)) {
                     _current_collisions[entity1.get()].emplace_back(entity2);
                     _current_collisions[entity2.get()].emplace_back(entity1);
                  }
               }
            }
         }
      }
   }

}
