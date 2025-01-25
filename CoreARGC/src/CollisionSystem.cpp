#include <CoreARGC/CollisionSystem.hpp>

namespace CoreARGC {
   CollisionSystem& CollisionSystem::Instance() {
      static CollisionSystem instance;
      return instance;
   }

   void CollisionSystem::Suscribe(Hitbox* hitbox) {
      _suscribers.push_back(hitbox);
   }

   void CollisionSystem::Unsuscribe(Hitbox* hitbox) {
      auto it = std::remove(_suscribers.begin(), _suscribers.end(), hitbox);
      if (it != _suscribers.end()) {
         _suscribers.erase(it, _suscribers.end());
      }
   }

   void CollisionSystem::DetectCollisions() {
      _current_collisions.clear();

      for (auto itA = _suscribers.begin(); itA != _suscribers.end(); ++itA) {
         auto itB = itA;
         ++itB; // avoid comparisons with itself

         for (; itB != _suscribers.end(); ++itB) {
            Hitbox* a = *itA;
            Hitbox* b = *itB;

            if (a->CollideWith(*b)) {
               _current_collisions[a].push_back(b);
               _current_collisions[b].push_back(a);
               ResolveCollision(a, b);
            }

         }
      }
   }

   void CollisionSystem::ResolveCollision(Hitbox* a, Hitbox* b) {
      float overlapX = std::min(a->Right() - b->Left(), b->Right() - a->Left());
      float overlapY = std::min(a->Bottom() - b->Top(), b->Bottom() - a->Top());

      Vector2 a_position = a->GetPosition();
      Vector2 b_position = b->GetPosition();

      if (overlapX < overlapY) {
         if (a_position.x < b_position.x) {
            a_position.x -= overlapX / 2;
            b_position.x += overlapX / 2;
         }
         else {
            a_position.x += overlapX / 2;
            b_position.x -= overlapX / 2;
         }
      }
      else {
         if (a_position.y < b_position.y) {
            a_position.y -= overlapY / 2;
            b_position.y += overlapY / 2;
         }
         else {
            a_position.y += overlapY / 2;
            b_position.y -= overlapY / 2;
         }
      }

      a->GetOwner()->SetPosition(a_position);
      b->GetOwner()->SetPosition(b_position);
   }
}
