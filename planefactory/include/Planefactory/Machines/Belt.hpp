#pragma once

#include <array>

#include <CoreARGC/Item.hpp>
#include <CoreARGC/Direction.hpp>

class Belt : public CoreARGC::Item {
public:
   static constexpr const char* TYPE = "Belt";
   static const unsigned BUFFER_SIZE = 9;

   Belt();

   std::string_view GetType() const override;
   std::unique_ptr<CoreARGC::Entity> Clone() const override;

   void CopyFrom(const CoreARGC::Entity& other) override;

protected:
   void Logic(CoreARGC::GameContext& ctx) override;

private:
   float _velocity;
   std::array<std::weak_ptr<Entity>, BUFFER_SIZE> _left_buffer;
   std::array<std::weak_ptr<Entity>, BUFFER_SIZE> _right_buffer;
   CoreARGC::Direction _direction;
};
