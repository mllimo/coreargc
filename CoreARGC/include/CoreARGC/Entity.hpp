#pragma once

#include <string_view>

#include <CoreARGC/TextureRef.hpp>


namespace CoreARGC {
   class GameContext;

   class Entity {
   public:
      virtual ~Entity();

      void SetPosition(Vector2 position);
      void SetTexture(const TextureRef& texture);

      Vector2 GetPosition() const;
      virtual std::string_view GetType() const;

      virtual void Logic(GameContext& ctx);
      virtual void Draw() const;

   private:
      Vector2 _position;
      Rectangle _hitbox;
      TextureRef _texture;
   };
}
