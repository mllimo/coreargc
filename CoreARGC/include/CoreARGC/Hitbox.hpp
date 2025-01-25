#pragma once

#include <raylib.h>

#include <CoreARGC/Component.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT Hitbox : public Component {
   public:
      static constexpr const char* TYPE = "Hitbox";

      using Component::Component;

      Hitbox(Entity* owner);
      ~Hitbox() override;

      float Left() const;
      float Right() const;
      float Top() const;
      float Bottom() const;

      void SetSize(Vector2 size);
      void SetBox(Rectangle box);
      void SetOffset(Vector2 offset);
      void SetIsStatic(bool static_mode);

      bool GetIsStatic() const;
      Vector2 GetSize() const;
      Vector2 GetOffset() const;
      Vector2 GetPosition() const;
      Rectangle GetWorldRectangle() const;
      std::string_view GetType() const override;

      std::unique_ptr<Component> Clone(Entity* new_owner) const override;

      bool CollideWith(const Hitbox& other) const;

   private:
      Rectangle _box; //< { offset, dimensions }
      bool _is_static = false; //< in collision resolution an static object can't be move
   };
}
