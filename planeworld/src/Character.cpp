#include <CoreARGC/GameContext.hpp>
#include <CoreARGC/CollisionSystem.hpp>
#include <CoreARGC/Rigid.hpp>

#include <Planeworld/Character.hpp>
#include <Planeworld/Wall.hpp>

#include <iostream>


namespace Planeworld {

   void Character::Start() {
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
      auto rigid = GetComponent<CoreARGC::Rigid>();
      auto collisions = CoreARGC::CollisionSystem::Instance().GetAllCollisionsFor(*this);

      if (IsKeyDown(KEY_A))
         rigid->AddForce({ -500, 0 });
      if (IsKeyDown(KEY_D))
         rigid->AddForce({ 500, 0 });
      if (IsKeyDown(KEY_W))
         rigid->AddForce({ 0, -500 });
      if (IsKeyDown(KEY_S))
         rigid->AddForce({ 0, 500 });

   }

}
