#include <CoreARGC/Item.hpp>

namespace CoreARGC {

   Item::Item(std::string_view id)
      : _id(id) {
   }

   void Item::CopyFrom(const Entity& other) {
      Entity::CopyFrom(other);
      const Item& casted = static_cast<const Item&>(other);
      _id = casted._id;
   }

   std::string_view Item::GetID() const {
      return _id;
   }

}

