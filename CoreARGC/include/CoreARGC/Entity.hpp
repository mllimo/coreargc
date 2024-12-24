#pragma once

#include <string_view>
#include <cassert>

#include <CoreARGC/TextureRef.hpp>


namespace CoreARGC {
   class COREARGC_EXPORT GameContext;

   class COREARGC_EXPORT Entity {
   public:
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
      virtual void Logic(GameContext& ctx);

   private:
      Vector2 _position = {};
      Rectangle _hitbox = {}; //< x and y represent the offset relative to _position
      TextureRef _texture;
   };
}
