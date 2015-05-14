#include "Input.h"

std::map<SDL_Keycode, bool> Input::keyStatus;
Uint16 Input::modifierKeyStatus;
Input::MouseState Input::lastMouseState;

void Input::Update(SDL_Event* event)
{
   if (event->type == SDL_KEYDOWN)
   {
      keyStatus[event->key.keysym.sym] = true;
      modifierKeyStatus = event->key.keysym.mod;
   }
   else if (event->type == SDL_KEYUP)
   {
      keyStatus[event->key.keysym.sym] = false;
      modifierKeyStatus = event->key.keysym.mod;
   }
   else if (event->type == SDL_MOUSEBUTTONDOWN)
   {
      lastMouseState.numClicks = event->button.clicks;
      lastMouseState.mousePosition = Point(event->button.x, event->button.y);
      lastMouseState.buttonStates[event->button.button] = true;
   }
   else if (event->type == SDL_MOUSEBUTTONUP)
   {
      lastMouseState.numClicks = event->button.clicks;
      lastMouseState.mousePosition = Point(event->button.x, event->button.y);
      lastMouseState.buttonStates[event->button.button] = false;
   }
}

bool Input::IsKeyDown(const SDL_Keycode& key)
{
   return keyStatus[key];
}

bool Input::IsKeyUp(const SDL_Keycode& key)
{
   return !keyStatus[key];
}

bool Input::IsMouseButtonDown(const Uint8& btn)
{
   return lastMouseState.buttonStates[btn];
}

bool Input::IsMouseButtonUp(const Uint8& btn)
{
   return !lastMouseState.buttonStates[btn];
}

Point Input::GetMousePosition()
{
   return lastMouseState.mousePosition;
}

Uint8 Input::GetMouseClickCount()
{
   return lastMouseState.numClicks;
}