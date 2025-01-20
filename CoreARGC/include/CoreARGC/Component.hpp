#pragma once

#include <memory>
#include <string_view>

namespace CoreARGC {
   class Entity;

   class Component {
   public:
      Component() = default;
      Component(Entity* owner);
      Component(const Component& other);
      Component(Component&&) = default;

      virtual ~Component();

      void SetOwner(Entity* owner);

      Entity* GetOwner() const;
      virtual std::string_view GetType() const = 0;

      virtual std::unique_ptr<Component> Clone() const = 0;

   private:
      Entity* _owner = nullptr;
   };
}
