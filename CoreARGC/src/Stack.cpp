#include <CoreARGC/Stack.hpp>

namespace CoreARGC {
   Stack::Stack(const Item& prototype)
      : _items_limit(100)
      , _items(0)
      , _prototype(static_cast<Item*>(prototype.Clone().release())) {
   }

   Stack::Stack(unsigned limit, const Item& prototype)
      : _items_limit(limit)
      , _items(0)
      , _prototype(static_cast<Item*>(prototype.Clone().release())) {
   }

   unsigned Stack::AddItems(unsigned items) {
      unsigned possible_to_add = _items_limit - _items;

      if (items <= possible_to_add) {
         _items += items;
         return items;
      }

      _items += possible_to_add;
      return possible_to_add;
   }

   unsigned Stack::RemoveItems(unsigned items) {
      if (items <= _items) {
         _items -= items;
         return items;
      }

      unsigned removed = _items;
      _items = 0;
      return removed;
   }

   const Item& Stack::GetItem() const {
      assert(_prototype != nullptr);
      return *_prototype;
   }

   unsigned Stack::GetCountItems() const {
      return _items;
   }

   unsigned Stack::GetLimitItems() const {
      return _items_limit;
   }
}
