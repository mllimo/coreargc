#include <CoreARGC/Rigid.hpp>
#include <CoreARGC/PhysicsSystem.hpp>

namespace CoreARGC {
   Rigid::Rigid(Entity* owner) : Component(owner) {
      PhysicsSystem::Instance().Suscribe(this);
   }

   Rigid::~Rigid() {
      PhysicsSystem::Instance().Unsuscribe(this);
   }

   void Rigid::AddForce(Vector2 force) {
      _force = Vector2Add(force, _force);
   }

   void Rigid::SetMass(float mass) {
      _mass = mass;
   }

   void Rigid::SetGravity(Vector2 gravity) {
      _gravity = gravity;
   }

   void Rigid::SetFriction(float friction) {
      _friction = friction;
   }

   float Rigid::GetMass() const {
      return _mass;
   }

   float Rigid::GetFriction() const {
      return _friction;
   }

   Vector2 Rigid::GetGravity() const {
      return _gravity;
   }

   Vector2 Rigid::GetVelocity() const {
      return _velocity;
   }

   std::string_view Rigid::GetType() const {
      return Rigid::TYPE;
   }

   std::unique_ptr<Component> Rigid::Clone(Entity* new_owner) const {
      Rigid component(*this);
      component._owner = new_owner;
      return std::make_unique<Rigid>(std::move(component));
   }

}
