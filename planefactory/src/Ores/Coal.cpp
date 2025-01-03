#include <CoreARGC/GameContext.hpp>

#include <Planefactory/Ores/Coal.hpp>

Coal::Coal() : CoreARGC::Item(Coal::TYPE) {
}

std::string_view Coal::GetType() const {
   return Coal::TYPE;
}

std::unique_ptr<CoreARGC::Entity> Coal::Clone() const {
   return std::make_unique<Coal>(*this);
}

void Coal::Start(CoreARGC::GameContext& ctx) {
   SetTexture(ctx.GetTexture(Coal::TYPE));
}

