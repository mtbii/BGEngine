#pragma once

#include<SDL.h>
#include<map>
#include "Vertex.h"

class Input
{
public:
   static void Update(SDL_Event* event);
   static bool IsKeyDown(const SDL_Keycode& key);
   static bool IsKeyUp(const SDL_Keycode& key);
   static bool IsMouseButtonDown(const Uint8& btn);
   static bool IsMouseButtonUp(const Uint8& btn);
   static Point GetMousePosition();
   static Uint8 GetMouseClickCount();

private:
   static std::map<SDL_Keycode, bool> keyStatus;
   static Uint16 modifierKeyStatus;
   static struct MouseState{
      Uint8 numClicks;
      std::map<Uint8, bool> buttonStates;
      Point mousePosition;
   } lastMouseState;
};

