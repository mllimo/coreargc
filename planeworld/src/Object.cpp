#include <CoreARGC/GameContext.hpp>

#include <Planeworld/Object.hpp>

namespace Planeworld {

   std::string_view Object::GetType() const {
      return Object::TYPE;
   }

   std::unique_ptr<CoreARGC::Entity> Object::Clone() const {
      return std::make_unique<Object>(*this);
   }

}
