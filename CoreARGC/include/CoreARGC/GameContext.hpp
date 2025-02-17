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
      std::weak_ptr<EntityType> CreateEntity(ARGS&&... args);
      std::weak_ptr<Entity> CreateEntity(Entity* entity); //< Get the ownership
      std::weak_ptr<Entity> CreateEntity(const Entity& entity);
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

      void RemoveEntities();
   };

   template <typename EntityType, typename ...ARGS>
   std::weak_ptr<EntityType> GameContext::CreateEntity(ARGS&&... args) {
      static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType debe heredar de Entity");

      auto entity = std::make_shared<EntityType>(std::forward<ARGS>(args)...);
      entity->Start();

      _entities[entity->GetType().data()].emplace_back(entity);
      return entity;
   }
}
