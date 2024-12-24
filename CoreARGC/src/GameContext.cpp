#include <CoreARGC/GameContext.hpp>

namespace CoreARGC {
   void GameContext::DestroyEntity(Entity* to_destroy) {
      _entities_to_remove.emplace_back(to_destroy);
   }

   void GameContext::Logic() {
      for (auto& pair : _entities) {
         for (auto& entity : pair.second) {
            entity->Logic(*this);
         }
      }

      RemoveEntities();
   }

   void GameContext::Draw() const {
      for (auto& pair : _entities) {
         for (auto& entity : pair.second) {
            entity->Draw();
         }
      }
   }

   std::vector<std::weak_ptr<Entity>> GameContext::GetCollidingEntities(const Entity& entity, std::string_view type) {
      std::vector<std::weak_ptr<Entity>> collisions;

      auto it = _entities.find(type.data());
      if (it == _entities.end())
         return {};

      for (auto& current_entity : it->second) {
         if (entity.CollideWhith(*current_entity)) {
            collisions.emplace_back(current_entity);
         }
      }

      return collisions;
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
