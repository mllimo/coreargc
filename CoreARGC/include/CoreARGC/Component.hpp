#pragma once

#include <memory>
#include <string_view>

namespace CoreARGC {
   class Entity;

   class Component {
   public:
      Component(Entity* owner);
      Component(Component&&) = default;

      virtual ~Component();

      Entity* GetOwner() const;
      virtual std::string_view GetType() const = 0;

      virtual std::unique_ptr<Component> Clone(Entity* new_owner) const = 0;

   protected:
      Entity* _owner = nullptr;

      Component(const Component&) = default;

   };
}
