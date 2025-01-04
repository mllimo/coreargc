#include <CoreARGC/GameContext.hpp>

#include <Planefactory/Machines/Belt.hpp>

Belt::Belt()
   : CoreARGC::Item(Belt::TYPE)
   , _velocity(10.f)
   , _direction(CoreARGC::Direction::RIGHT) {

}

std::string_view Belt::GetType() const {
   return Belt::TYPE;
}

std::unique_ptr<CoreARGC::Entity> Belt::Clone() const {
   return std::make_unique<Belt>(*this);
}

void Belt::CopyFrom(const CoreARGC::Entity& other) {
   Item::CopyFrom(other);
   auto& casted = static_cast<const Belt&>(other);
   _velocity = casted._velocity;
   _direction = casted._direction;
}

void Belt::Logic(CoreARGC::GameContext& ctx) {
   Vector2 direction_vector = CoreARGC::DirectionToVector(_direction);
   Vector2 velocity_vector = Vector2Scale(direction_vector, _velocity * GetFrameTime());

   std::vector<std::weak_ptr<Entity>> collisions = ctx.GetCollisionsFor(*this);

   for (auto& element : collisions) {
      if (std::shared_ptr<Entity> entity_ptr = element.lock()) {
         entity_ptr->SetPosition(Vector2Add(entity_ptr->GetPosition(), velocity_vector));
      }
   }
}
