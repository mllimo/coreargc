#include <CoreARGC/TextureSource.hpp>

namespace CoreARGC {
   TextureSource::TextureSource(const std::filesystem::path& texture_path)
      : _texture_ptr(std::make_shared<Texture2D>(LoadTexture(texture_path.string().c_str()))) {
   }

   TextureSource::~TextureSource() {
      if (_texture_ptr)
         UnloadTexture(*_texture_ptr);
   }

   TextureRef TextureSource::GetRef() const {
      if (not _texture_ptr)
         return TextureRef(); // expired
      return TextureRef(_texture_ptr);
   }
}