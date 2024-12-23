#pragma once

#include <CoreARGC/Entity.hpp>

class Ore : public CoreARGC::Entity {
public:
   Ore(float amount);

   float GetAmount() const;

   // return the amount mined
   float Mine(float amount);

protected:
   float _amount;
};
