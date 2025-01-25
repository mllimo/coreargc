#include <stdexcept>
#include <iostream>
#include <chrono>

#include <raylib.h>
#include <raymath.h>

#include <CoreARGC/Entity.hpp>
#include <CoreARGC/TextureSource.hpp>
#include <CoreARGC/Grid.hpp>
#include <CoreARGC/GameContext.hpp>
#include <CoreARGC/Rigid.hpp>

#include <Planeworld/Character.hpp>
#include <Planeworld/Wall.hpp>
#include <Planeworld/Object.hpp>


int main() {

   CoreARGC::GameContext& ctx = CoreARGC::GameContext::Instance();
   ctx.grid = CoreARGC::Grid(50, 50);

   CoreARGC::Vector2i screen_size = { 1000, 1000 };
   InitWindow(screen_size.x, screen_size.y, "Planeworld");

   ctx.LoadTextureAs("assets/planeworld/Dirt.png", "Dirt");
   ctx.LoadTextureAs("assets/planeworld/Stone.png", "Stone");
   ctx.LoadTextureAs("assets/planeworld/Leave.png", "Leave");

   auto player = ctx.CreateEntity<Planeworld::Character>();
   player.lock()->SetPosition({ 500, 500 });
   player.lock()->AddComponent<CoreARGC::Hitbox>();
   player.lock()->AddComponent<CoreARGC::Rigid>();

   auto player_hitbox = player.lock()->GetComponent<CoreARGC::Hitbox>();
   player_hitbox->SetSize({ 50, 50 });

   auto ground_hitbox = ctx.CreateEntity<Planeworld::Object>();
   ground_hitbox.lock()->SetPosition({ 0, 50 });
   ground_hitbox.lock()->AddComponent<CoreARGC::Hitbox>();

   auto ground_hitbox_box = ground_hitbox.lock()->GetComponent<CoreARGC::Hitbox>();
   ground_hitbox_box->SetIsStatic(true);
   ground_hitbox_box->SetSize({ 50, 10 });

   player.lock()->AddChild(ground_hitbox);

   auto wall = ctx.CreateEntity<Planeworld::Wall>();
   wall.lock()->SetPosition({ 600, 500 });
   wall.lock()->AddComponent<CoreARGC::Hitbox>();
   auto wall_hb = wall.lock()->GetComponent<CoreARGC::Hitbox>();
   wall_hb->SetIsStatic(true);
   wall_hb->SetSize({ 50, 50 });


   auto wall2 = ctx.CreateEntity<Planeworld::Wall>();
   wall2.lock()->SetPosition({ 400, 500 });
   wall2.lock()->AddComponent<CoreARGC::Hitbox>();
   auto wall2_hb = wall2.lock()->GetComponent<CoreARGC::Hitbox>();
   wall2_hb->SetIsStatic(true);
   wall2_hb->SetSize({ 50, 50 });

   auto wall3 = ctx.CreateEntity<Planeworld::Wall>();
   wall3.lock()->SetPosition({ 500, 700 });
   wall3.lock()->AddComponent<CoreARGC::Hitbox>();
   auto wall3_hb = wall3.lock()->GetComponent<CoreARGC::Hitbox>();
   wall3_hb->SetIsStatic(true);
   wall3_hb->SetSize({ 50, 50 });

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
