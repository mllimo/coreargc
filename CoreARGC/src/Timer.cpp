#include <CoreARGC/Timer.hpp>

#include <raylib.h>

namespace CoreARGC {
   void Timer::SetDuration(float duration_seconds) {
      _duration_seconds = duration_seconds;
   }

   void Timer::SetCallback(const std::function<void()>& callback) {
      _callback = callback;
   }

   bool Timer::IsInitialize() const {
      return (bool)_callback;
   }

   void Timer::Update() {
      _elapsed_time_seconds += GetFrameTime();
      if (_elapsed_time_seconds >= _duration_seconds) {
         _callback();
         _elapsed_time_seconds = 0.f;
      }
   }

}
