#pragma once
#include <glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <math.h>
#include "Log.h"
#include "Time.h"
#include "RenderUtils.h"
#include "Model3D.h"
//#include "Input.h"
#include "Window.h"

class Game
{
protected:
   bool _isRunning;
   Window window;

   const int TARGET_FPS = 60;
   int GetFPS();
   void PrintFPS();
   void RequestQuit();

public:
   Game(Window& window);
   ~Game();

   virtual int Execute();
   virtual bool Init();
   virtual void OnEvent(SDL_Event* event);
   virtual void Update();
   virtual void Render();
   virtual void CleanUp();
};