#pragma once

#include <unordered_map>
#include <deque>
#include <filesystem>

#include <CoreARGC/Entity.hpp>
#include <CoreARGC/Grid.hpp>
#include <CoreARGC/TextureSource.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT GameContext {
   public:
      Camera2D camera;
      Grid grid;

      static GameContext& Instance();

      // Create and destroy entities
      void DestroyEntity(Entity* to_destroy);
      template <typename EntityType, typename ...ARGS>
      std::weak_ptr<Entity> CreateEntity(ARGS&&... args);
      std::weak_ptr<Entity> CreateEntity(Entity* entity); //< Get the ownership
      std::weak_ptr<Entity> CreateEntity(const Entity& entity);
      //

      // Collision system
      std::vector<std::weak_ptr<Entity>> GetCollisionsFor(const Entity& entity) const;
      bool CheckCollisionWith(const Entity& entity, const std::string& type) const;
      //

      // Textures in memory
      TextureRef GetTexture(const std::string& id);
      TextureRef LoadTextureAs(const std::filesystem::path& path, const std::string& id);
      //

      // Game loop
      void Update();
      void Show() const;
      //

   protected:
      GameContext() = default;

   private:
      std::deque<Entity*> _entities_to_remove;
      std::unordered_map<std::string, TextureSource> _textures;
      std::unordered_map<std::string, std::deque<std::shared_ptr<Entity>>> _entities;
      std::unordered_map<const Entity*, std::vector<std::weak_ptr<Entity>>> _current_collisions;

      void RemoveEntities();
      void DetectCollisions();
      void DetectCollisionFor(const Entity& entity);
   };

   template <typename EntityType, typename ...ARGS>
   std::weak_ptr<Entity> GameContext::CreateEntity(ARGS&&... args) {
      static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType debe heredar de Entity");

      auto entity = std::make_shared<EntityType>(std::forward<ARGS>(args)...);
      entity->Start();

      DetectCollisionFor(*entity);
      _entities[entity->GetType().data()].emplace_back(entity);
      return entity;
   }
}
