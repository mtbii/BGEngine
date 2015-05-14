#pragma once

#include<glew.h>
#include<string>
#include "Utilities.h"
#include<SDL.h>
#include<SDL_opengl.h>

class Window
{
private:
   void CreateGameWindow(std::string title, int width, int height);

public:
   Window();
   Window(const std::string& title, const int& width, const int& height);
   ~Window();

   std::string title;
   int width;
   int height;
   SDL_Window* sdl_window;
   SDL_GLContext glContext;
};

