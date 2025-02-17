#pragma once

#include <raymath.h>

#include <CoreARGC/Component.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT Rigid : public Component {
   public:
      static constexpr const char* TYPE = "Rigid";

      friend class PhysicsSystem;
      using Component::Component;

      Rigid(Entity* owner);
      ~Rigid();

      void AddForce(Vector2 force);

      void SetMass(float mass);
      void SetGravity(Vector2 gravity);
      void SetFriction(float friction);

      float GetMass() const;
      float GetFriction() const;
      Vector2 GetGravity() const;
      Vector2 GetVelocity() const;

      std::string_view GetType() const override;
      std::unique_ptr<Component> Clone(Entity* new_owner) const override;

   private:
      float _mass = 1.f;
      float _friction = 0.0015f;
      Vector2 _force = {};
      Vector2 _velocity = {};
      Vector2 _gravity = {};
      Vector2 _acceleration = {};
   };
}
