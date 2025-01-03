#pragma once

#include <filesystem>

#include <CoreARGC/TextureRef.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT TextureSource {
   public:
      TextureSource() = default; // TODO: Generar Setter
      TextureSource(TextureSource&&) = default;
      TextureSource(const TextureSource&) = default;
      TextureSource(const std::filesystem::path& texture_path);

      ~TextureSource();

      TextureSource& operator=(TextureSource&&) = default;
      TextureSource& operator=(const TextureSource&) = default;

      TextureRef GetRef() const;

   private:
      std::shared_ptr<Texture2D> _texture_ptr;
   };
}
