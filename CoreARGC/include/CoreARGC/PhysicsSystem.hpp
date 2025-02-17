#pragma once

#include <vector>
#include <unordered_map>

#include <CoreARGC/Rigid.hpp>

namespace CoreARGC {
   class COREARGC_EXPORT PhysicsSystem {
   public:
      static PhysicsSystem& Instance();

      void Suscribe(Rigid* entity);
      void Unsuscribe(Rigid* entity);

      void Update();

   private:
      std::vector<Rigid*> _suscribers;

      PhysicsSystem() = default;
   };
}
