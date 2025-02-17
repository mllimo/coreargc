#include <CoreARGC/Component.hpp>

#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   Component::Component(Entity* owner)
      : _owner(owner) {
   }

   Component::~Component() {
   }

   Entity* Component::GetOwner() const {
      return _owner;
   }

}
