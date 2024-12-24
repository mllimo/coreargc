#pragma once

#include <CoreARGC/Item.hpp>

namespace CoreARGC {
   // Stack represent a stack of a prototype. It can't be recycled
   class COREARGC_EXPORT Stack {
   public:
      Stack(unsigned limit, const Item& prototype);

      // returns number of ACTION items
      unsigned AddItems(unsigned items);
      unsigned RemoveItems(unsigned items);

      const Item& GetItem() const;
      unsigned GetCountItems() const;
      unsigned GetLimitItems() const;

   private:
      unsigned _items_limit;
      unsigned _items;
      Item _prototype;
   };
}
