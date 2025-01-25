#pragma once

#include <string>

#include <CoreARGC/Entity.hpp>
#include <Planeworld/Object.hpp>

namespace Planeworld {
   class Character : public CoreARGC::Entity {
   public:
      static constexpr const char* TYPE = "Character";
      Object* ground_hitbox = nullptr;

      void Start() override;

      virtual std::string_view GetType() const override;
      virtual std::unique_ptr<Entity> Clone() const override;

   protected:
      static constexpr Vector2 GRAVITY = { 0.f, 2.18f };
      static constexpr Vector2 JUMP = { 0.f, -3000.f };

      Vector2 _force;
      Vector2 _static_force;
      bool _on_the_floor = false;

      virtual void Logic() override;
   };
}
