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
      virtual ~Entity();

      void SetPosition(Vector2 position);
      void SetTexture(const TextureRef& texture);
      void SetHitbox(const Rectangle& rectangle);

      Vector2 GetPosition() const;
      virtual std::string_view GetType() const;

      virtual void CopyFrom(const Entity& other);
      virtual std::unique_ptr<Entity> Clone() const;
      virtual bool CollideWhith(const Entity& other) const;

      virtual void Draw() const;
      virtual void Start(GameContext& ctx);
      virtual void Logic(GameContext& ctx);

   private:
      Hitbox _hitbox;
      Vector2 _position = {};
      TextureRef _texture;
   };
}
