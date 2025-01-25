#include <CoreARGC/Hitbox.hpp>
#include <CoreARGC/Entity.hpp>
#include <CoreARGC/CollisionSystem.hpp>


namespace CoreARGC {

   Hitbox::Hitbox(Entity* owner)
      : Component(owner)
      , _box() {
      CollisionSystem::Instance().Suscribe(this);
   }

   Hitbox::~Hitbox() {
      CollisionSystem::Instance().Unsuscribe(this);
   }

   float Hitbox::Left() const {
      return GetPosition().x;
   }

   float Hitbox::Right() const {
      return GetPosition().x + GetSize().x;
   }

   float Hitbox::Top() const {
      return GetPosition().y;
   }

   float Hitbox::Bottom() const {
      return GetPosition().y + GetSize().y;
   }

   void Hitbox::SetSize(Vector2 size) {
      _box.width = size.x;
      _box.height = size.y;
   }

   void Hitbox::SetBox(Rectangle box) {
      _box = box;
   }

   void Hitbox::SetOffset(Vector2 offset) {
      _box.x = offset.x;
      _box.y = offset.y;
   }

   void Hitbox::SetIsStatic(bool static_mode) {
      _is_static = static_mode;
   }

   bool Hitbox::GetIsStatic() const {
      return _is_static;
   }

   Vector2 Hitbox::GetSize() const {
      return { _box.width, _box.height };
   }

   Vector2 Hitbox::GetOffset() const {
      return { _box.x, _box.y };
   }

   Vector2 Hitbox::GetPosition() const {
      return Vector2Add(GetOffset(), GetOwner()->GetPosition());
   }

   Rectangle Hitbox::GetWorldRectangle() const {
      Rectangle world_rec = _box;
      Vector2 owner_position = GetOwner()->GetPosition();
      world_rec.x = owner_position.x + _box.x;
      world_rec.y = owner_position.y + _box.y;
      return world_rec;
   }

   std::string_view Hitbox::GetType() const {
      return Hitbox::TYPE;
   }

   std::unique_ptr<Component> Hitbox::Clone(Entity* new_owner) const {
      Hitbox component(*this);
      component._owner = new_owner;
      return std::make_unique<Hitbox>(std::move(component));
   }

   bool Hitbox::CollideWith(const Hitbox& other) const {
      return CheckCollisionRecs(GetWorldRectangle(), other.GetWorldRectangle());
   }
}
