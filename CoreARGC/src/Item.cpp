#include <CoreARGC/Item.hpp>

namespace CoreARGC {

   Item::Item(std::string_view id, const Entity& entity_prototype)
      : _id(id)
      , _prototype(entity_prototype.Clone()) {
   }

   Item::Item(const Item& other) {
      CopyFrom(other);
   }

   void Item::CopyFrom(const Item& other) {
      _id = other._id;
      _prototype = other._prototype->Clone();
   }

   Item& Item::operator=(const Item& other) {
      CopyFrom(other);
      return *this;
   }

   std::string_view Item::GetID() const {
      return _id;
   }

   const Entity& Item::GetEntity() const {
      assert(_prototype == nullptr && "null prototype");
      return *_prototype;
   }


}

