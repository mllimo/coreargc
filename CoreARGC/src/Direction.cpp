#include <CoreARGC/Direction.hpp>

namespace CoreARGC {
   Vector2 DirectionToVector(Direction direction) {
      switch (direction) {
      case CoreARGC::Direction::UP:
         return UP_VECTOR;
      case CoreARGC::Direction::RIGHT:
         return RIGHT_VECTOR;
      case CoreARGC::Direction::DOWN:
         return DOWN_VECTOR;
      case CoreARGC::Direction::LEFT:
         return LEFT_VECTOR;
      }

      return Vector2{};
   }
}
