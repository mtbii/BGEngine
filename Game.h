#pragma once

#include <SDL.h>
#include <math.h>
#include "Log.h"
#include "Time.h"

namespace Engine
{
   class Game
   {
   private:
      bool _isRunning;

      string _title;
      int _width;
      int _height;

      SDL_Window* _window;
      SDL_Surface* _screen;
      SDL_Renderer* _renderer;

      const int TARGET_FPS = 200;
      int getFPS();
      void printFPS();

   public:
      Game();
      Game(string windowTitle, int width, int height);
      ~Game();

      int execute();
      bool init();
      void onEvent(SDL_Event* event);
      void update();
      void render();
      void cleanup();
   };
}