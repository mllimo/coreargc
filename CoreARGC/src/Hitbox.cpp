#include <CoreARGC/Hitbox.hpp>
#include <CoreARGC/Entity.hpp>


namespace CoreARGC {

   Hitbox::Hitbox(Rectangle box) 
      : Component() 
      , _box(box) {

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

   Vector2 Hitbox::GetSize() const {
      return { _box.width, _box.height };
   }

   Vector2 Hitbox::GetOffset() const {
      return { _box.x, _box.y };
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

   std::unique_ptr<Component> Hitbox::Clone() const {
      return std::make_unique<Hitbox>(*this);
   }

   bool Hitbox::CollideWith(const Hitbox& other) const {
      return CheckCollisionRecs(GetWorldRectangle(), other.GetWorldRectangle());
   }
}
