#include <CoreARGC/Hitbox.hpp>

namespace CoreARGC {
   Hitbox::Hitbox(Vector2* parent_position, Rectangle box)
      : _parent_position(parent_position)
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

   void Hitbox::SetParentPosition(Vector2* parent_position) {
      _parent_position = parent_position;
   }

   Vector2 Hitbox::GetSize() const {
      return { _box.width, _box.height };
   }

   Vector2 Hitbox::GetOffset() const {
      return { _box.x, _box.y };
   }

   Rectangle Hitbox::GetWorldRectangle() const {
      Rectangle world_rec = _box;
      world_rec.x = _parent_position->x + _box.x;
      world_rec.y = _parent_position->y + _box.y;
      return world_rec;
   }

   bool Hitbox::CollideWith(const Hitbox& other) const {
      return CheckCollisionRecs(GetWorldRectangle(), other.GetWorldRectangle());
   }
}
