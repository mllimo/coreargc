#include <CoreARGC/Entity.hpp>

namespace CoreARGC {

   Entity::Entity(const Entity& other) {
      CopyFrom(other);
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

   void Entity::AddComponent(const Component& component) {
      auto clone = component.Clone();
      clone->SetOwner(this);
      _components.push_back(std::move(clone));
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

   void Entity::CopyFrom(const Entity& other) {
      for (const std::unique_ptr<Component>& component : other._components) {
         auto cloned = component->Clone();
         cloned->SetOwner(this);
      }

      _position = other._position;
      _texture = other._texture;
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

      Vector2 size = GetComponent<Hitbox>()->GetSize(); // TODO: Remove this dependency
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
