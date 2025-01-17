#pragma once

#include <raylib.h>
#include <raymath.h>

#include <CoreARGC/Math.hpp>
#include <CoreARGC_api.h>

namespace CoreARGC {
   class COREARGC_EXPORT Grid {
   public:
      Grid() = default;
      Grid(float width, float height, Vector2 origin = { 0.f, 0.f });

      void SetWidth(float width);
      void SetHeight(float height);

      float GetWidth() const;
      float GetHeight() const;
      Vector2 GetGridToWorld(Vector2i grid_position) const;
      Vector2i GetWorldToGrid(Vector2 world_position) const;
      Rectangle GetWorldTile(Vector2i grid_position) const;

   private:
      Vector2 _origin = {};
      float _width = 0.f;
      float _height = 0.f;
   };
}
