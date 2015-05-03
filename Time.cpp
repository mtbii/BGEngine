#include "Time.h"

/***
Returns current time in milliseconds
***/
long Time::getTime(){
   return SDL_GetTicks();
}

/***
Returns the time difference between the current time
and the last time that delta was called.
***/
long Time::delta(){
   static long lastTime = SDL_GetTicks();
   long currentTime = SDL_GetTicks();
   long deltaTime = currentTime - lastTime;
   lastTime = currentTime;
   return deltaTime;
}
