#pragma once

#include <string_view>

#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT Item {
   public:
      Item(const Item& other);
      Item(Item&& other) = default;
      Item(std::string_view id, const Entity& entity_prototype);

      void CopyFrom(const Item& other);

      std::string_view GetID() const;
      const Entity& GetEntity() const;

      Item& operator=(const Item& other);
      Item& operator=(Item&& other) = default;

   private:
      std::string _id;
      std::unique_ptr<Entity> _prototype;
   };
}
