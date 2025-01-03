#pragma once

#include <string_view>

#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT Item : public Entity {
   public:
      Item(std::string_view id);

      std::string_view GetID() const;

      virtual void CopyFrom(const Entity& other) override;

   private:
      std::string _id;
   };
}
