#include <CoreARGC/GameContext.hpp>

#include <Planefactory/Ores/Iron.hpp>

Iron::Iron() : CoreARGC::Item(Iron::TYPE) {
}

std::string_view Iron::GetType() const {
   return Iron::TYPE;
}

std::unique_ptr<CoreARGC::Entity> Iron::Clone() const {
   return std::make_unique<Iron>(*this);
}

void Iron::Start(CoreARGC::GameContext& ctx) {
   SetTexture(ctx.GetTexture(Iron::TYPE));
}
