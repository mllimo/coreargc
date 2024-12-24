#include <CoreARGC/GameContext.hpp>

#include <planefactory/Miner.hpp>
#include <Planefactory/Ore.hpp>

Miner::Miner(float mining_rate)
   : _mining_rate(mining_rate) {
}

void Miner::Logic(CoreARGC::GameContext& ctx) {
   std::vector<std::weak_ptr<Entity>> collisions = ctx.GetCollidingEntities(*this, Ore::TYPE);
}
