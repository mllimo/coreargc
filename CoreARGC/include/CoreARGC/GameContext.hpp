#pragma once

#include <unordered_map>
#include <deque>

#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT GameContext {
   public:
      Camera2D camera;

      void DestroyEntity(Entity* to_destroy);

      template <typename EntityType, typename ...ARGS>
      std::weak_ptr<Entity> CreateEntity(ARGS&&... args) {
         static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType debe heredar de Entity");

         auto entity = std::make_shared<EntityType>(std::forward<ARGS>(args)...);
         entity->Start(*this);

         _entities[entity->GetType().data()].emplace_back(entity);
         return std::weak_ptr<Entity>(entity);
      }

      void Logic();
      void Draw() const;
      std::vector<std::weak_ptr<Entity>> GetCollidingEntities(const Entity& entity, std::string_view type);

   private:
      std::unordered_map<std::string, std::deque<std::shared_ptr<Entity>>> _entities;
      std::deque<Entity*> _entities_to_remove;

      void RemoveEntities();
   };
}
