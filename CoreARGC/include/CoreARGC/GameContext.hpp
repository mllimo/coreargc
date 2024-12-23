#pragma once

#include <unordered_map>
#include <deque>

#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   class GameContext {
   public:
      Camera2D camera;

      void DestroyEntity(Entity* to_destroy);

      template <typename EntityType, typename ...ARGS>
      std::weak_ptr<Entity> CreateEntity(ARGS&&... args) {
         static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType debe heredar de Entity");

         auto entity = std::make_shared<EntityType>(std::forward<ARGS>(args)...);
         _entities[entity->GetType().data()].emplace_back(entity);
         return std::weak_ptr<Entity>(entity);
      }

      void Draw() const;

   private:
      std::unordered_map<std::string, std::deque<std::shared_ptr<Entity>>> _entities;
      std::deque<Entity*> _entities_to_remove;
   };
}
