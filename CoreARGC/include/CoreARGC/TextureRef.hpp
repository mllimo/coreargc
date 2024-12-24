#pragma once

#include <memory>
#include <stdexcept>
#include <string>

#include <raylib.h>
#include <raymath.h>

#include <CoreARGC_api.h>

namespace CoreARGC {
   class COREARGC_EXPORT TextureRef {
   public:
      TextureRef() = default;
      TextureRef(const std::weak_ptr<Texture2D>& reference);

      const Texture2D& Value() const;

      bool IsExpired() const;

   private:
      std::weak_ptr<Texture2D> _reference;
   };
}
