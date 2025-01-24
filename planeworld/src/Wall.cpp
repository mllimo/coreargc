#include <CoreARGC/GameContext.hpp>

#include <Planeworld/Wall.hpp>

namespace Planeworld {

   void Wall::Start(CoreARGC::GameContext& ctx) {
      SetTexture(ctx.LoadTextureAs("assets/planeworld/Wood.png", Planeworld::Wall::TYPE));
   }

   std::string_view Wall::GetType() const {
      return Wall::TYPE;
   }

   std::unique_ptr<CoreARGC::Entity> Wall::Clone() const {
      return std::make_unique<Wall>(*this);
   }

   void Wall::Logic(CoreARGC::GameContext& ctx) {
   }

}
