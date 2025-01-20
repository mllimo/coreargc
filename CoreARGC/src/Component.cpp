#include <CoreARGC/Component.hpp>

#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   Component::Component(Entity* owner)
      : _owner(owner) {
   }

   Component::Component(const Component& other) {
   }

   Component::~Component() {
   }

   void Component::SetOwner(Entity* owner) {
      _owner = owner;
   }

   Entity* Component::GetOwner() const {
      return _owner;
   }

}
