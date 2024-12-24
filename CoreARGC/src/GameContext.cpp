#include <CoreARGC/GameContext.hpp>

namespace CoreARGC {
   void GameContext::DestroyEntity(Entity* to_destroy) {
      _entities_to_remove.emplace_back(to_destroy);
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

}
