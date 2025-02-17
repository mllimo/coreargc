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

      bool a_is_static = a->GetIsStatic();
      bool b_is_static = b->GetIsStatic();

      if (overlapX < overlapY) {
         if (a_position.x < b_position.x) {
            if (!a_is_static) a_position.x -= overlapX;
            if (!b_is_static) b_position.x += overlapX;
         }
         else {
            if (!a_is_static) a_position.x += overlapX;
            if (!b_is_static) b_position.x -= overlapX;
         }
      }
      else {
         if (a_position.y < b_position.y) {
            if (!a_is_static) a_position.y -= overlapY;
            if (!b_is_static) b_position.y += overlapY;
         }
         else {
            if (!a_is_static) a_position.y += overlapY;
            if (!b_is_static) b_position.y -= overlapY;
         }
      }

      if (!a_is_static) a->GetOwner()->SetPosition(a_position);
      if (!b_is_static) b->GetOwner()->SetPosition(b_position);
   }

   const std::vector<Hitbox*>& CollisionSystem::GetAllCollisionsFor(const Entity& entity) {
      const Hitbox* hb = entity.GetComponent<Hitbox>();
      auto it = _current_collisions.find(const_cast<CoreARGC::Hitbox*>(hb));
      if (it == _current_collisions.end()) return {};
      return it->second;
   }

}
