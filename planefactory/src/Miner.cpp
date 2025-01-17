#include <iostream>

#include <CoreARGC/GameContext.hpp>
#include <CoreARGC/Stack.hpp>

#include <planefactory/Miner.hpp>
#include <Planefactory/Ores/Ore.hpp>


Miner::Miner(float mining_rate)
   : _mining_rate(mining_rate)
   , _output_drop_direction(CoreARGC::Direction::RIGHT) {
   _mining_timer.SetDuration(1.f);
}

void Miner::CopyFrom(const Entity& other) {
   Entity::CopyFrom(other);
   auto casted = static_cast<const Miner&>(other);
   _mining_rate = casted._mining_rate;
   _mining_timer.SetDuration(casted._mining_timer.GetDuration());
   _output_drop_direction = casted._output_drop_direction;
}

std::string_view Miner::GetType() const {
   return Miner::TYPE;
}

std::unique_ptr<CoreARGC::Entity> Miner::Clone() const {
   return std::make_unique<Miner>(*this);
}

void Miner::Start(CoreARGC::GameContext& ctx) {
   SetTexture(ctx.GetTexture(GetType().data()));

   if (not _mining_timer.IsInitialize()) {
      _mining_timer.SetCallback([this, &ctx]() {
         Extract(ctx);
         });
   }
}

void Miner::Logic(CoreARGC::GameContext& ctx) {
   _mining_timer.Update();
}

Vector2 Miner::OutputPosition() {
   const Vector2 position = GetPosition();
   const Vector2 size = GetHitbox().GetSize();
   const Vector2 half_size = Vector2Scale(size, 0.5f);

   switch (_output_drop_direction) {
   case CoreARGC::Direction::UP:
      //    x
      // =====
      // |   |
      // |   |
      // =====
      return { position.x + half_size.x, position.y + CoreARGC::UP_VECTOR.y };

   case CoreARGC::Direction::RIGHT:
      // =====
      // |   |
      // |   |x
      // =====
      return { position.x + size.x, position.y + half_size.y };

   case CoreARGC::Direction::DOWN:
      // =====
      // |   |
      // |   |
      // =====
      //    x
      return { position.x + half_size.x, position.y + size.y };

   case CoreARGC::Direction::LEFT:
      // =====
      // |   |
      //x|   |
      // =====
      return { position.x + CoreARGC::LEFT_VECTOR.x, position.y + half_size.y };
   }

   return position;
}

void Miner::Extract(CoreARGC::GameContext& ctx) {
   std::vector<std::shared_ptr<Ore>> colliding_with_ores;

   const auto& collisions = ctx.GetCollisionsFor(*this);

   for (const auto& entity_ptr : collisions) {
      if (auto ore_ptr = std::dynamic_pointer_cast<Ore>(entity_ptr.lock())) {
         colliding_with_ores.push_back(ore_ptr);
      }
   }

   if (colliding_with_ores.empty()) {
      return;
   }

   float extract_per_entity = _mining_rate / colliding_with_ores.size();
   float total_extracted = 0.f;

   for (const auto& ore_ptr : colliding_with_ores) {
      if (ore_ptr) {
         float extracted = ore_ptr->Mine(extract_per_entity);

         Vector2 output_pos = OutputPosition();
         CoreARGC::Vector2i output_pos_grid = ctx.grid.GetWorldToGrid(output_pos);
         output_pos = ctx.grid.GetGridToWorld(output_pos_grid);

         std::unique_ptr<CoreARGC::Item> item = ore_ptr->GetDropItem();
         item->SetPosition(output_pos);
         ctx.CreateEntity(item.release());

         //CoreARGC::Stack drop_stack(item);
         //drop_stack.AddItems(extracted);

         total_extracted += extracted;
      }
   }

   std::clog << "Total extracted: " << total_extracted << '\n';
}


