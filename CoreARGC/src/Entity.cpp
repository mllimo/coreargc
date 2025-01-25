#include <CoreARGC/Entity.hpp>
#include <CoreARGC/GameContext.hpp>

namespace CoreARGC {

   Entity::Entity(const Entity& other) {
      CopyFrom(other);
   }

   Entity::~Entity() {
      for (auto& child : _childs) {
         if (auto ptr = child.lock()) {
            GameContext::Instance().DestroyEntity(ptr.get());
         }
      }
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
      auto clone = component.Clone(this);
      _components.push_back(std::move(clone));
   }

   void Entity::AddChild(const std::weak_ptr<Entity>& entity) {
      if (auto ptr = entity.lock()) {
         ptr->_parent = this;
         _childs.push_back(entity);
      }
   }

   bool Entity::GetVisible() const {
      return _visible;
   }

   bool Entity::GetActivated() const {
      return _activated;
   }

   Vector2 Entity::GetPosition() const {
      if (_parent) {
         return Vector2Add(_position, _parent->GetPosition());
      }

      return _position;
   }

   void Entity::CopyFrom(const Entity& other) {
      for (const std::unique_ptr<Component>& component : other._components) {
         auto cloned = component->Clone(this);
      }

      _position = other._position;
      _texture = other._texture;
   }

   void Entity::Show() const {
      if (not _visible) return;
      Draw();
   }

   void Entity::Update() {
      if (not _activated) return;
      Logic();
   }

   void Entity::Draw() const {
      Vector2 position = GetPosition();
      Vector2 size = GetComponent<Hitbox>()->GetSize(); // TODO: Remove this dependency
      if (_texture.IsExpired()) {
         DrawRectangleRec({ position.x, position.y, size.x, size.y }, BLACK);
      }
      else {
         DrawTexturePro(
            _texture.Value(),                             // Textura (desbloqueada desde weak_ptr)
            { 0, 0, (float)_texture.Value().width, (float)_texture.Value().height }, // Fuente: toda la textura
            { position.x, position.y, size.x, size.y },            // Destino: tamaño 30x30
            { 0, 0 },                                 // Origen: el punto central de la textura (15,15 para centrarla)
            0.0f,                                       // Rotación
            WHITE                                       // Color
         );
      }
   }

   void Entity::Start() {
   }

   void Entity::Logic() {
   }
}
