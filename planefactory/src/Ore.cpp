#include <CoreARGC/GameContext.hpp>

#include <Planefactory/Ore.hpp>


Ore::Ore(float amount)
   : _amount(amount) {

}

float Ore::GetAmount() const {
   return _amount;
}

std::string_view Ore::GetType() const {
   return Ore::TYPE;
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
