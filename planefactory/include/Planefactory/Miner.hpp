#pragma onces

#include <CoreARGC/Entity.hpp>
#include <CoreARGC/Timer.hpp>

class Miner : public CoreARGC::Entity {
public:
   Miner(float mining_rate);

   void Start(CoreARGC::GameContext& ctx) override;
   void Logic(CoreARGC::GameContext& ctx) override;

private:
   float _mining_rate;
   CoreARGC::Timer _mining_timer;

   void Extract(CoreARGC::GameContext& ctx);
};
