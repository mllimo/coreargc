#include <CoreARGC/GameContext.hpp>

#include <Planeworld/Character.hpp>
#include <Planeworld/Wall.hpp>
#include <Planeworld/Object.hpp>

#include <iostream>


namespace Planeworld {

   void Character::Start() {
      _force = {};
      _static_force = GRAVITY;
      SetTexture(
         CoreARGC::GameContext::Instance().
         LoadTextureAs("assets/planeworld/Character.png", Planeworld::Character::TYPE)
      );
   }

   std::string_view Character::GetType() const {
      return Character::TYPE;
   }

   std::unique_ptr<CoreARGC::Entity> Character::Clone() const {
      return std::make_unique<Character>(*this);
   }

   void Character::Logic() {
      _force = {};
      Vector2 position = GetPosition();

      if (IsKeyDown(KEY_A))
         _force.x -= 200;
      if (IsKeyDown(KEY_D))
         _force.x += 200;
      if (IsKeyDown(KEY_W))
         _force.y -= 200;
      if (IsKeyDown(KEY_S))
         _force.y += 200;

      //SetPosition(position);
      position = Vector2Add(position, Vector2Scale(_force, GetFrameTime()));
      SetPosition(position);

   }

}
