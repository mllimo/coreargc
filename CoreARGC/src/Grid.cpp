#include <cmath>

#include <CoreARGC/Grid.hpp>

namespace CoreARGC {
   Grid::Grid(float width, float height, Vector2 origin)
      : _width(width)
      , _height(height)
      , _origin(origin) {
   }

   void Grid::SetWidth(float width) {
      _width = width;
   }

   void Grid::SetHeight(float height) {
      _height = height;
   }

   float Grid::GetWidth() const {
      return _width;
   }

   float Grid::GetHeight() const {
      return _height;
   }

   Vector2 Grid::GetGridToWorld(Vector2i grid_position) const {
      Vector2 size = { grid_position.x * _width, grid_position.y * _height };
      Vector2 world_position = Vector2Add(_origin, size);
      return world_position;
   }

   Rectangle Grid::GetWorldTile(Vector2i grid_position) const {
      Rectangle rec;
      Vector2 size = { grid_position.x * _width, grid_position.y * _height };
      Vector2 world_position = Vector2Add(_origin, size);
      rec.width = _width;
      rec.height = _height;
      rec.x = world_position.x;
      rec.y = world_position.y;
      return rec;
   }

   Vector2i Grid::GetWorldToGrid(Vector2 world_position) const {
      Vector2i grid_position;
      Vector2 diff = Vector2Subtract(world_position, _origin);
      grid_position.x = std::floor(diff.x / _width);
      grid_position.y = std::floor(diff.y / _height);
      return grid_position;
   }

}
