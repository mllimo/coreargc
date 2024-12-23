#pragma once

#include <raylib.h>
#include <raymath.h>

#include <CoreARGC/Math.hpp>

namespace CoreARGC {
   class Grid {
   public:
      Grid(float width, float height, Vector2 origin = { 0.f, 0.f });

      float GetWidth() const;
      float GetHeight() const;
      Vector2 GetGridToWorld(Vector2i grid_position) const;
      Vector2i GetWorldToGrid(Vector2 world_position) const;
      Rectangle GetWorldTile(Vector2i grid_position) const;

   private:
      Vector2 _origin;
      float _width;
      float _height;
   };
}
