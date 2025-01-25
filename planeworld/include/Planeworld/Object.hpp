#pragma once

#include <string>

#include <CoreARGC/Entity.hpp>

namespace Planeworld {
   class Object : public CoreARGC::Entity {
   public:
      static constexpr const char* TYPE = "Object";

      virtual std::string_view GetType() const override;
      virtual std::unique_ptr<Entity> Clone() const override;
   };
}
