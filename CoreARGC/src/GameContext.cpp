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
}
