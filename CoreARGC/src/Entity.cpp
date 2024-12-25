#include <CoreARGC/Entity.hpp>

namespace CoreARGC {
   Entity::Entity() {
      _hitbox.SetParentPosition(&_position);
   }

   Entity::~Entity() {
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

   Vector2 Entity::GetPosition() const {
      return _position;
   }

   std::string_view Entity::GetType() const {
      return "Entity";
   }

   void Entity::CopyFrom(const Entity& other) {
      _position = other._position;
      _hitbox = other._hitbox;
      _texture = other._texture;
   }

   std::unique_ptr<Entity> Entity::Clone() const {
      return std::make_unique<Entity>(*this);
   }

   bool Entity::CollideWhith(const Entity& other) const {
      return _hitbox.CollideWith(other._hitbox);
   }

   void Entity::Draw() const {
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
