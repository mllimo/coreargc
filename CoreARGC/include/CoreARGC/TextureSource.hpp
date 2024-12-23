#pragma once

#include <CoreARGC/TextureRef.hpp>

namespace CoreARGC {
   class TextureSource {
   public:
      TextureSource(const std::string& texture_path);

      ~TextureSource();

      TextureRef GetRef() const;

   private:
      std::shared_ptr<Texture2D> _texture_ptr;
   };
}
