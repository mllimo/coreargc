#pragma once

#include <chrono>

#include <functional>

namespace CoreARGC {
   class Timer {
   public:
      Timer() = default;

      void SetDuration(float duration_seconds);
      void SetCallback(const std::function<void()>& callback);

      bool IsInitialize() const;

      void Update();

   private:
      float _duration_seconds = 0;
      float _elapsed_time_seconds = 0;
      std::function<void()> _callback;
   };
}
