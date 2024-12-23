#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   Entity::~Entity() {
   }

   void Entity::SetPosition(Vector2 position) {
      _position = position;
   }

   void Entity::SetTexture(const TextureRef& texture) {
      _texture = texture;
   }

   Vector2 Entity::GetPosition() const {
      return _position;
   }

   std::string_view Entity::GetType() const {
      return "Entity";
   }

   void Entity::Logic(GameContext& ctx) {
   }

   void Entity::Draw() const {
      DrawTexturePro(
         _texture.Value(),                             // Textura (desbloqueada desde weak_ptr)
         { 0, 0, (float)_texture.Value().width, (float)_texture.Value().height }, // Fuente: toda la textura
         { _position.x, _position.y, 30, 30 },            // Destino: tamaño 30x30
         { 0, 0 },                                 // Origen: el punto central de la textura (15,15 para centrarla)
         0.0f,                                       // Rotación
         WHITE                                       // Color
      );
   }
}
