#pragma once

#include <vector>
#include <unordered_map>

#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT CollisionSystem {
   public:
      static CollisionSystem& Instance();

      void Suscribe(Hitbox* entity);
      void Unsuscribe(Hitbox* entity);

      void DetectCollisions();
      void ResolveCollision(Hitbox* a, Hitbox* b);

   private:
      std::vector<Hitbox*> _suscribers;
      std::unordered_map<Hitbox*, std::vector<Hitbox*>> _current_collisions;

      CollisionSystem() = default;
   };
}
