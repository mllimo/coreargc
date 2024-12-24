#include <CoreARGC/Stack.hpp>

namespace CoreARGC {
   Stack::Stack(unsigned limit, const Item& prototype)
      : _items_limit(limit)
      , _items(0)
      , _prototype(prototype) {
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
      return _prototype;
   }

   unsigned Stack::GetCountItems() const {
      return _items;
   }

   unsigned Stack::GetLimitItems() const {
      return _items_limit;
   }
}
