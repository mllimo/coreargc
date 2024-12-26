#include <stdexcept>
#include <iostream>
#include <chrono>

#include <raylib.h>
#include <raymath.h>

#include <CoreARGC/Entity.hpp>
#include <CoreARGC/TextureSource.hpp>
#include <CoreARGC/Grid.hpp>
#include <CoreARGC/GameContext.hpp>

#include <Planefactory/Ore.hpp>
#include <Planefactory/Miner.hpp>

int main() {

   CoreARGC::GameContext ctx;
   CoreARGC::Grid grid(30, 30);

   Rectangle hitbox = {
      .width = 30,
      .height = 30
   };

   Rectangle miner_hitbox = {
      .width = 60,
      .height = 60
   };

   CoreARGC::Vector2i screen_size = { 1000, 1000 };
   InitWindow(screen_size.x, screen_size.y, "Planefactory");

   const CoreARGC::TextureSource COAL_ORE_TEX("assets/placed/coal_ore.png");
   const CoreARGC::TextureSource MINER_TEX("assets/placed/miner.png");

   ctx.camera.target = { 0, 0 };
   ctx.camera.rotation = 0;
   ctx.camera.zoom = 1.f;
   ctx.camera.offset = { 0, 0 };

   while (not WindowShouldClose()) {

      if (IsKeyDown(KEY_A))
         ctx.camera.target.x -= 200 * GetFrameTime();
      if (IsKeyDown(KEY_D))
         ctx.camera.target.x += 200 * GetFrameTime();
      if (IsKeyDown(KEY_W))
         ctx.camera.target.y -= 200 * GetFrameTime();
      if (IsKeyDown(KEY_S))
         ctx.camera.target.y += 200 * GetFrameTime();

      CoreARGC::Vector2i grid_position = grid.GetWorldToGrid(GetScreenToWorld2D(GetMousePosition(), ctx.camera));
      Rectangle mouse_tile = grid.GetWorldTile(grid_position);
      //std::clog << grid_position.x << "|" << grid_position.y << std::endl;

      if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
         auto new_entity = ctx.CreateEntity<Ore>(100.f).lock();
         new_entity->SetPosition(grid.GetGridToWorld(grid_position));
         new_entity->SetTexture(COAL_ORE_TEX.GetRef());
         new_entity->SetHitbox(hitbox);
      }

      if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {
         auto new_entity = ctx.CreateEntity<Miner>(20.f).lock();
         new_entity->SetPosition(grid.GetGridToWorld(grid_position));
         new_entity->SetTexture(MINER_TEX.GetRef());
         new_entity->SetHitbox(miner_hitbox);
      }

      ctx.Logic();

      BeginDrawing();
      ClearBackground(WHITE);
      DrawFPS(40, 40);
      BeginMode2D(ctx.camera);

      ctx.Draw();

      DrawRectangleRec(mouse_tile, Color{255, 0, 0, 100});

      EndMode2D();
      EndDrawing();
   }

   CloseWindow();
   return 0;
}
