#pragma onces

#include <CoreARGC/Entity.hpp>

class Miner : public CoreARGC::Entity {
public:
   Miner(float mining_rate);

   void Logic(CoreARGC::GameContext& ctx) override;

private:
   float _mining_rate;
};
