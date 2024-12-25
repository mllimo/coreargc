#pragma once

#include <raylib.h>

namespace CoreARGC {
   class Hitbox {
   public:
      Hitbox() = default;
      Hitbox(Vector2* parent_position, Rectangle box);
      
      void SetSize(Vector2 size);
      void SetBox(Rectangle box);
      void SetOffset(Vector2 offset);
      void SetParentPosition(Vector2* parent_position);

      Vector2 GetSize() const;
      Vector2 GetOffset() const;
      Rectangle GetWorldRectangle() const;

      bool CollideWith(const Hitbox& other) const;

   private:
      Rectangle _box; //< { offset, dimensions }
      Vector2* _parent_position = nullptr; //< reference
   };
}
