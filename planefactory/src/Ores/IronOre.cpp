#include <CoreARGC/GameContext.hpp>

#include <Planefactory/Ores/IronOre.hpp>

std::string_view IronOre::GetType() const {
   return IronOre::TYPE;
}

std::unique_ptr<CoreARGC::Item> IronOre::GetDropItem() const {
   auto iron = std::make_unique<Iron>();
   iron->SetHitbox({ .width = 30, .height = 30 });
   return iron;
}

std::unique_ptr<CoreARGC::Entity> IronOre::Clone() const {
   return std::make_unique<IronOre>(*this);
}

void IronOre::Start(CoreARGC::GameContext& ctx) {
   SetTexture(ctx.GetTexture(IronOre::TYPE));
}
