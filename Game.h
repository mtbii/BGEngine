#pragma once
#include <glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <math.h>
#include "Log.h"
#include "Time.h"
#include "RenderUtils.h"
#include "Mesh.h"

   class Game
   {
   protected:
      bool _isRunning;

      string _title;
      int _width;
      int _height;

      SDL_Window* _window;
      SDL_GLContext _glContext;
      SDL_Renderer* _renderer;
      SDL_Surface* _screen;

      const int TARGET_FPS = 200;
      int GetFPS();
      void PrintFPS();

   public:
      Game();
      Game(string windowTitle, int width, int height);
      ~Game();

      virtual int Execute();
      virtual bool Init();
      virtual void OnEvent(SDL_Event* event);
      virtual void Update();
      virtual void Render();
      virtual void CleanUp();
   };