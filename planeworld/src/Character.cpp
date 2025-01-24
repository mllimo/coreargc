#include <CoreARGC/GameContext.hpp>

#include <Planeworld/Character.hpp>
#include <Planeworld/Wall.hpp>


namespace Planeworld {

   void Character::Start() {
      _force = {};
      _static_force = GRAVITY;
      SetTexture(
         CoreARGC::GameContext::Instance().
         LoadTextureAs("assets/planeworld/Character.png", Planeworld::Character::TYPE)
      );
   }

   void Character::SetPosition(Vector2 position) {
      Vector2 original_pos = GetPosition();
      Entity::SetPosition(position);
      if (CoreARGC::GameContext::Instance().CheckCollisionWith(*this, Wall::TYPE)) {
         Entity::SetPosition(original_pos);
      }
   }

   std::string_view Character::GetType() const {
      return Character::TYPE;
   }

   std::unique_ptr<CoreARGC::Entity> Character::Clone() const {
      return std::make_unique<Character>(*this);
   }

   void Character::Logic() {
      Vector2 position = GetPosition();

      if (IsKeyDown(KEY_A))
         position.x -= 200 * GetFrameTime();
      if (IsKeyDown(KEY_D))
         position.x += 200 * GetFrameTime();
      if (IsKeyPressed(KEY_SPACE))
         _force = Vector2Add(_force, JUMP);

      SetPosition(position);

      position = GetPosition();

      _force = Vector2Add(_force, _static_force);
      if (_force.x > 1000) _force.x = 1000.f;
      if (_force.x < -1000) _force.x = -1000.f;
      if (_force.y > 1000) _force.y = 1000.f;
      if (_force.y < -1000) _force.y = -1000.f;

      position = Vector2Add(position, Vector2Scale(_force, GetFrameTime()));

      SetPosition(position);
   }

}
