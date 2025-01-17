#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   Entity::Entity() {
      _hitbox.SetParentPosition(&_position);
   }

   void Entity::SetVisible(bool is_visible) {
      _visible = is_visible;
   }

   void Entity::SetActivated(bool is_enable) {
      _activated = is_enable;
   }

   void Entity::SetPosition(Vector2 position) {
      _position = position;
   }

   void Entity::SetTexture(const TextureRef& texture) {
      _texture = texture;
   }

   void Entity::SetHitbox(const Rectangle& rectangle) {
      _hitbox.SetBox(rectangle);
   }

   bool Entity::GetVisible() const {
      return _visible;
   }

   bool Entity::GetActivated() const {
      return _activated;
   }

   Vector2 Entity::GetPosition() const {
      return _position;
   }

   const Hitbox& Entity::GetHitbox() const {
      return _hitbox;
   }

   void Entity::CopyFrom(const Entity& other) {
      _position = other._position;
      _hitbox = other._hitbox;
      _texture = other._texture;
   }

   bool Entity::CollideWhith(const Entity& other) const {
      return _hitbox.CollideWith(other._hitbox);
   }

   void Entity::Show() const {
      if (not _visible) return;
      Draw();
   }

   void Entity::Update(GameContext& ctx) {
      if (not _activated) return;
      Logic(ctx);
   }

   void Entity::Draw() const {
      if (not _visible) return;

      Vector2 size = _hitbox.GetSize();
      DrawTexturePro(
         _texture.Value(),                             // Textura (desbloqueada desde weak_ptr)
         { 0, 0, (float)_texture.Value().width, (float)_texture.Value().height }, // Fuente: toda la textura
         { _position.x, _position.y, size.x, size.y },            // Destino: tamaño 30x30
         { 0, 0 },                                 // Origen: el punto central de la textura (15,15 para centrarla)
         0.0f,                                       // Rotación
         WHITE                                       // Color
      );
   }

   void Entity::Start(GameContext& ctx) {
   }

   void Entity::Logic(GameContext& ctx) {
   }
}
