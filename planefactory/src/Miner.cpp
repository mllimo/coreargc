#include <iostream>

#include <CoreARGC/GameContext.hpp>

#include <planefactory/Miner.hpp>
#include <Planefactory/Ore.hpp>

Miner::Miner(float mining_rate)
   : _mining_rate(mining_rate) {
   _mining_timer.SetDuration(1.f);
}

void Miner::Start(CoreARGC::GameContext& ctx) {
   if (not _mining_timer.IsInitialize()) {
      _mining_timer.SetCallback([this, &ctx]() {
         Extract(ctx);
         });
   }
}

void Miner::Logic(CoreARGC::GameContext& ctx) {
   _mining_timer.Update();
}

void Miner::Extract(CoreARGC::GameContext& ctx) {
   std::vector<std::weak_ptr<Entity>> collisions = ctx.GetCollidingEntities(*this, Ore::TYPE);
   float extract_per_entity = _mining_rate / collisions.size();
   float total_extracted = 0.f;

   for (auto& ore_ptr : collisions) {
      Ore& ore = static_cast<Ore&>(*ore_ptr.lock());
      float extracted = ore.Mine(extract_per_entity);
      total_extracted += extracted;
   }

   std::clog << "Total extracted: " << total_extracted << '\n';
}


