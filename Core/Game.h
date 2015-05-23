#pragma once
#include <glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <math.h>
#include "../Utilities/Log.h"
#include "../Utilities/Time.h"
#include "../Utilities/RenderUtils.h"
#include <IL/il.h>
#include <IL/ilut.h>
#include "Input.h"
#include "Window.h"

class Game
{
protected:
   bool _isRunning;
   Window window;

   int targetFps;
   int GetFPS();
   void PrintFPS();
   void RequestQuit();

public:
   Game(Window& window, const int& fps);
   ~Game();

   virtual int Execute();
   virtual bool Init();
   virtual void OnEvent(SDL_Event* event);
   virtual void Update();
   virtual void Render();
   virtual void CleanUp();
};