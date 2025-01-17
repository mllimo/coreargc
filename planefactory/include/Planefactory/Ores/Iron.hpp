#pragma once

#include <CoreARGC/Item.hpp>

class Iron : public CoreARGC::Item {
public:
   static constexpr const char* TYPE = "Iron";

   Iron();

   std::string_view GetType() const override;

   std::unique_ptr<CoreARGC::Entity> Clone() const override;

   void Start(CoreARGC::GameContext& ctx) override;
};
