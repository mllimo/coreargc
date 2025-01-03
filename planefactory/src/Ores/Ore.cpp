#include <CoreARGC/GameContext.hpp>

#include <Planefactory/Ores/Ore.hpp>


Ore::Ore(float amount)
   : _amount(amount) {

}

float Ore::GetAmount() const {
   return _amount;
}

std::string_view Ore::GetType() const {
   return Ore::TYPE;
}

void Ore::CopyFrom(const Entity& other) {
   Entity::CopyFrom(other);
   const Ore& casted = static_cast<const Ore&>(other);
   _amount = casted._amount;
}

float Ore::Mine(float amount) {
   if (_amount < amount) {
      float mined = _amount;
      _amount = 0;
      return mined;
   }

   _amount -= amount;
   return amount;
}

void Ore::Logic(CoreARGC::GameContext& ctx) {
   if (_amount == 0) {
      ctx.DestroyEntity(this);
   }
}
