#include <stdexcept>
#include <iostream>
#include <chrono>

#include <raylib.h>
#include <raymath.h>

#include <CoreARGC/Entity.hpp>
#include <CoreARGC/TextureSource.hpp>
#include <CoreARGC/Grid.hpp>
#include <CoreARGC/GameContext.hpp>

#include <Planeworld/Character.hpp>

int main() {

   CoreARGC::GameContext ctx;
   ctx.grid = CoreARGC::Grid(50, 50);

   CoreARGC::Vector2i screen_size = { 1000, 1000 };
   InitWindow(screen_size.x, screen_size.y, "Planeworld");
 
   ctx.LoadTextureAs("assets/planeworld/Dirt.png", "Dirt");
   ctx.LoadTextureAs("assets/planeworld/Wood.png", "Wood");
   ctx.LoadTextureAs("assets/planeworld/Stone.png", "Stone");
   ctx.LoadTextureAs("assets/planeworld/Leave.png", "Leave");

   auto player = ctx.CreateEntity<Planeworld::Character>();
   player.lock()->AddComponent(CoreARGC::Hitbox({0, 0, 50, 50}));

   ctx.camera.target = { 0, 0 };
   ctx.camera.rotation = 0;
   ctx.camera.zoom = 1.f;
   ctx.camera.offset = { 0, 0 };

   while (not WindowShouldClose()) {

      //if (IsKeyDown(KEY_A))
      //   ctx.camera.target.x -= 200 * GetFrameTime();
      //if (IsKeyDown(KEY_D))
      //   ctx.camera.target.x += 200 * GetFrameTime();
      //if (IsKeyDown(KEY_W))
      //   ctx.camera.target.y -= 200 * GetFrameTime();
      //if (IsKeyDown(KEY_S))
      //   ctx.camera.target.y += 200 * GetFrameTime();

      ctx.Update();

      BeginDrawing();
      ClearBackground(WHITE);
      DrawFPS(40, 40);
      BeginMode2D(ctx.camera);

      ctx.Show();

      EndMode2D();
      EndDrawing();
   }

   CloseWindow();
   return 0;
}
