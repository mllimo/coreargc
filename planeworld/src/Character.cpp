#include <CoreARGC/GameContext.hpp>

#include <Planeworld/Character.hpp>
#include <Planeworld/Wall.hpp>


namespace Planeworld {

   void Character::Start(CoreARGC::GameContext& ctx) {
      _ctx = &ctx;
      SetTexture(ctx.LoadTextureAs("assets/planeworld/Character.png", Planeworld::Character::TYPE));
   }

   void Character::SetPosition(Vector2 position) {
      Vector2 original_pos = GetPosition();
      Entity::SetPosition(position);
      if (_ctx->CheckCollisionWith(*this, Wall::TYPE)) {
         Entity::SetPosition(original_pos);
      }
   }

   std::string_view Character::GetType() const {
      return Character::TYPE;
   }

   std::unique_ptr<CoreARGC::Entity> Character::Clone() const {
      return std::make_unique<Character>(*this);
   }

   void Character::Logic(CoreARGC::GameContext& ctx) {
      Vector2 position = GetPosition();

      if (IsKeyDown(KEY_A))
         position.x -= 200 * GetFrameTime();
      if (IsKeyDown(KEY_D))
         position.x += 200 * GetFrameTime();

      SetPosition(position);

      position = GetPosition();
      position.y += GRAVITY.y * GetFrameTime();

      SetPosition(position);
   }

}
