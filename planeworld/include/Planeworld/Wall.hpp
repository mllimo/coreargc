#pragma once

#include <string>

#include <CoreARGC/Entity.hpp>

namespace Planeworld {
   class Wall : public CoreARGC::Entity {
   public:
      static constexpr const char* TYPE = "Wall";

      void Start(CoreARGC::GameContext& ctx) override;

      virtual std::string_view GetType() const override;
      virtual std::unique_ptr<Entity> Clone() const override;

   protected:
      virtual void Logic(CoreARGC::GameContext& ctx) override;
   };
}
