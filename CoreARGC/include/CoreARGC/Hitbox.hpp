#pragma once

#include <raylib.h>

#include <CoreARGC/Component.hpp>

namespace CoreARGC {
   class Hitbox : public Component {
   public:
      static constexpr const char* TYPE = "Hitbox";

      using Component::Component;

      Hitbox(Rectangle box);
      ~Hitbox() override = default;

      void SetSize(Vector2 size);
      void SetBox(Rectangle box);
      void SetOffset(Vector2 offset);

      Vector2 GetSize() const;
      Vector2 GetOffset() const;
      Rectangle GetWorldRectangle() const;
      std::string_view GetType() const override;

      std::unique_ptr<Component> Clone() const override;

      bool CollideWith(const Hitbox& other) const;

   private:
      Rectangle _box; //< { offset, dimensions }
   };
}
