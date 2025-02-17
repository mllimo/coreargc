#include <raylib.h>

#include <CoreARGC/PhysicsSystem.hpp>
#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   PhysicsSystem& PhysicsSystem::Instance() {
      static PhysicsSystem var;
      return var;
   }

   void PhysicsSystem::Suscribe(Rigid* rigid) {
      _suscribers.push_back(rigid);
   }

   void PhysicsSystem::Unsuscribe(Rigid* rigid) {
      auto it = std::remove(_suscribers.begin(), _suscribers.end(), rigid);
      if (it != _suscribers.end()) {
         _suscribers.erase(it, _suscribers.end());
      }
   }

   void PhysicsSystem::Update() {
      float deltaTime = GetFrameTime();

      for (Rigid* rigid : _suscribers) {
         // a = F / m
         rigid->_acceleration = Vector2Add(rigid->_acceleration, Vector2Scale(rigid->_force, 1.0f / rigid->_mass));
         rigid->_acceleration = Vector2Add(rigid->_acceleration, rigid->_gravity);

         // v += a * deltaTime
         Vector2 deltaVelocity = Vector2Scale(rigid->_acceleration, deltaTime);
         rigid->_velocity = Vector2Add(rigid->_velocity, deltaVelocity);

         // with friction: v *= (1 - friction)
         rigid->_velocity = Vector2Scale(rigid->_velocity, 1.0f - rigid->_friction);

         Vector2 position = rigid->GetOwner()->GetPosition();
         Vector2 displacement = Vector2Scale(rigid->_velocity, deltaTime);
         position = Vector2Add(position, displacement);
         rigid->GetOwner()->SetPosition(position);

         rigid->_force = { 0.0f, 0.0f };
      }
   }
}
