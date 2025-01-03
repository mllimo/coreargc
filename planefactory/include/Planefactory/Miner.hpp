#pragma once

#include <CoreARGC/Entity.hpp>
#include <CoreARGC/Timer.hpp>
#include <CoreARGC/Direction.hpp>

class Miner : public CoreARGC::Entity {
public:
   static constexpr const char* TYPE = "Miner";

public:
   Miner(float mining_rate);

   void CopyFrom(const Entity& other) override;
   std::string_view GetType() const override;
   std::unique_ptr<Entity> Clone() const override;

   void Start(CoreARGC::GameContext& ctx) override;
   void Logic(CoreARGC::GameContext& ctx) override;

private:
   float _mining_rate;
   CoreARGC::Timer _mining_timer;
   CoreARGC::Direction _output_drop_direction;

   Vector2 OutputPosition();
   void Extract(CoreARGC::GameContext& ctx);
};
