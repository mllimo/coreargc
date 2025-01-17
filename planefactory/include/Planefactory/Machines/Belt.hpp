#pragma once

#include <CoreARGC/Item.hpp>
#include <CoreARGC/Direction.hpp>

class Belt : public CoreARGC::Item {
public:
   static constexpr const char* TYPE = "Belt";

   Belt();

   std::string_view GetType() const override;
   std::unique_ptr<CoreARGC::Entity> Clone() const override;

   void CopyFrom(const CoreARGC::Entity& other) override;

protected:
   void Logic(CoreARGC::GameContext& ctx) override;

private:
   float _velocity;
   CoreARGC::Direction _direction;
};
