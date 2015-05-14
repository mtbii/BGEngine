#include "Window.h"


Window::Window()
{
}

Window::Window(const std::string& title, const int& width, const int& height) :
title(title),
width(width),
height(height)
{
   CreateGameWindow(title, width, height);
}


Window::~Window()
{
   SDL_GL_DeleteContext(glContext);
   SDL_DestroyWindow(sdl_window);
   SDL_Quit();
}

void Window::CreateGameWindow(std::string title, int width, int height)
{
   if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
      error("Cannot initialize SDL!");
      throw new exception("Failed to initialize SDL");
   }

   sdl_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
   if (sdl_window == nullptr)
   {
      error("Cannot create SDL window!");
      throw new exception("Failed to create SDL window");
   }

   glContext = SDL_GL_CreateContext(sdl_window);
   if (glContext == nullptr){
      error("Cannot create OpenGL context!");
      throw new exception("Failed to create OpenGL context");
   }

   glewExperimental = GL_TRUE;
   GLenum errorCode = glewInit();
   if (errorCode != GLEW_OK){
      error("Error initializing GLEW");
      throw new exception("Failted to initialize GLEW");
   }

   RenderUtils::InitGraphics();

   SDL_GL_SetSwapInterval(1);
}
