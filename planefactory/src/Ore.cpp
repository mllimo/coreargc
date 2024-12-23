#include <Planefactory/Ore.hpp>

Ore::Ore(float amount)
   : _amount(amount) {

}

float Ore::GetAmount() const {
   return _amount;
}

float Ore::Mine(float amount) {
   if (_amount < amount) {
      _amount = 0;
      return abs(_amount - amount);
   }

   _amount -= amount;
   return amount;
}
