#pragma once

#include <string_view>
#include <cassert>

#include <CoreARGC/TextureRef.hpp>
#include <CoreARGC/Hitbox.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT GameContext;

   class COREARGC_EXPORT Entity {
   public:
      Entity();
      virtual ~Entity() = default;

      void SetVisible(bool is_visible);
      void SetActivated(bool is_enable);
      void SetPosition(Vector2 position);
      void SetTexture(const TextureRef& texture);
      void SetHitbox(const Rectangle& rectangle);

      bool GetVisible() const;
      bool GetActivated() const;
      Vector2 GetPosition() const;
      const Hitbox& GetHitbox() const;

      virtual std::string_view GetType() const = 0;
      virtual std::unique_ptr<Entity> Clone() const = 0;

      virtual void CopyFrom(const Entity& other);
      virtual bool CollideWhith(const Entity& other) const;

      void Show() const;
      void Update(GameContext& ctx);
      virtual void Start(GameContext& ctx);

   protected:
      virtual void Draw() const;
      virtual void Logic(GameContext& ctx);

   private:
      Hitbox _hitbox;
      Vector2 _position = {};
      TextureRef _texture;
      bool _visible = true;
      bool _activated = true;
   };
}
