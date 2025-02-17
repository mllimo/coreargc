#include <CoreARGC/GameContext.hpp>
#include <CoreARGC/CollisionSystem.hpp>
#include <CoreARGC/PhysicsSystem.hpp>

namespace CoreARGC {
   GameContext& GameContext::Instance() {
      static GameContext ctx;
      return ctx;
   }

   void GameContext::DestroyEntity(Entity* to_destroy) {
      _entities_to_remove.emplace_back(to_destroy);
   }

   std::weak_ptr<Entity> GameContext::CreateEntity(Entity* entity) {
      std::shared_ptr<Entity> clone;
      clone.reset(entity);
      clone->Start();

      _entities[clone->GetType().data()].emplace_back(clone);
      return clone;
   }

   std::weak_ptr<Entity> GameContext::CreateEntity(const Entity& entity) {
      std::shared_ptr<Entity> clone = entity.Clone();
      clone->Start();

      _entities[entity.GetType().data()].emplace_back(clone);
      return clone;
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

      auto found = _textures.find(id);
      if (found != _textures.end()) {
         return found->second.GetRef();
      }

      TextureSource& source = _textures[id] = std::move(TextureSource(path));
      return source.GetRef();
   }

   void GameContext::Update() {

      PhysicsSystem::Instance().Update();

      CollisionSystem::Instance().DetectCollisions();

      for (auto& pair : _entities) {
         for (auto& entity : pair.second) {
            entity->Update();
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

}
