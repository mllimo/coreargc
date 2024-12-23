#include <CoreARGC/TextureRef.hpp>

namespace CoreARGC {
   TextureRef::TextureRef(const std::weak_ptr<Texture2D>& reference)
      : _reference(reference)
   {}

   const Texture2D& TextureRef::Value() const {
      if (IsExpired())
         throw std::runtime_error("Texture value has expired");

      return *_reference.lock();
   }

   bool TextureRef::IsExpired() const {
      return _reference.expired();
   }
}
