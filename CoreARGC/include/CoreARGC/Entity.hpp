#pragma once

#include <string_view>
#include <cassert>
#include <unordered_set>

#include <CoreARGC/Component.hpp>
#include <CoreARGC/TextureRef.hpp>
#include <CoreARGC/Hitbox.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT GameContext;
   class COREARGC_EXPORT Component;

   class COREARGC_EXPORT Entity {
   public:
      Entity() = default;
      Entity(const Entity&);
      Entity(Entity&&) = default;

      virtual ~Entity();

      void SetVisible(bool is_visible);
      void SetActivated(bool is_enable);
      virtual void SetPosition(Vector2 position);
      void SetTexture(const TextureRef& texture);
      void AddComponent(const Component& component);

      bool GetVisible() const;
      bool GetActivated() const;
      Vector2 GetPosition() const;
      template <typename TComponent> TComponent* GetComponent();
      template <typename TComponent> const TComponent* GetComponent() const;

      virtual std::string_view GetType() const = 0;
      virtual std::unique_ptr<Entity> Clone() const = 0;

      virtual void CopyFrom(const Entity& other);

      void Show() const;
      void Update();
      virtual void Start();

   protected:
      virtual void Draw() const;
      virtual void Logic();

   private:
      Entity* _owner;
      std::list<std::weak_ptr<Entity>> _childs;
      std::list<std::unique_ptr<Component>> _components;

      Vector2 _position = {};
      TextureRef _texture;
      bool _visible = true;
      bool _activated = true;
   };

   template <typename TComponent>
   TComponent* Entity::GetComponent() {
      for (auto& component : _components) {
         if (component->GetType() == TComponent::TYPE)
            return static_cast<TComponent*>(component.get());
      }
      return nullptr;
   }

   template <typename TComponent>
   const TComponent* Entity::GetComponent() const {
      for (auto& component : _components) {
         if (component->GetType() == TComponent::TYPE)
            return static_cast<TComponent*>(component.get());
      }
      return nullptr;
   }

}
