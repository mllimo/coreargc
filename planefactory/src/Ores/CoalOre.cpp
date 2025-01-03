#include <Planefactory/Ores/CoalOre.hpp>
#include <CoreARGC/GameContext.hpp>

std::string_view CoalOre::GetType() const {
   return CoalOre::TYPE;
}

std::unique_ptr<CoreARGC::Item> CoalOre::GetDropItem() const {
   auto coal = std::make_unique<Coal>();
   coal->SetHitbox({ .width = 30, .height = 30 });
   return coal;
}

std::unique_ptr<CoreARGC::Entity> CoalOre::Clone() const {
   return std::make_unique<CoalOre>(*this);
}

void CoalOre::Start(CoreARGC::GameContext& ctx) {
   SetTexture(ctx.GetTexture(CoalOre::TYPE));
}
