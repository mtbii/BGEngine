#include "Game.h"

Game::Game() :
_isRunning(false),
_window(nullptr),
_title("3D Engine"),
_height(480),
_width(640)
{
}

Game::Game(string title, int width, int height){
   Game();
   this->_title = title;
   this->_height = height;
   this->_width = width;
}

Game::~Game()
{
   _window = nullptr;
}

bool Game::Init(){
   if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
      error("Cannot initialize SDL!");
      return false;
   }

   _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
   if (_window == nullptr)
   {
      error("Cannot create SDL window!");
      return false;
   }

   _glContext = SDL_GL_CreateContext(_window);
   if (_glContext == nullptr){
      error("Cannot create OpenGL context!");
      return false;
   }
   
   glewExperimental = GL_TRUE;
   GLenum errorCode = glewInit();
   if (errorCode != GLEW_OK){
      error("Error initializing GLEW");
   }

   RenderUtils::InitGraphics();

   SDL_GL_SetSwapInterval(1);
   return true;
}

int Game::Execute(){
   if (this->Init() == false){
      return -1;
   }

   int unprocessedTime = 0;
   const int frameTime = (int)round(1000.0 / TARGET_FPS);
   bool mustRender = false;
   _isRunning = true;
   SDL_Event event;
   Time::Delta();

   while (_isRunning){
      while (SDL_PollEvent(&event)){
         OnEvent(&event);
      }

      while (unprocessedTime > frameTime)
      {
         Update();
         unprocessedTime -= frameTime;
         mustRender = true;
      }

      if (mustRender)
      {
         Render();
         mustRender = false;

#if DEBUG
         PrintFPS();
#endif
      }
      else
      {
         SDL_Delay(1);
      }

      unprocessedTime += Time::Delta();
   }

   CleanUp();
   return 0;
}

void Game::Update(){

}

void Game::Render(){
   SDL_GL_SwapWindow(_window);
   RenderUtils::ClearScreen();
}

void Game::OnEvent(SDL_Event* event){
   Input::Update(event);
   if (event->type == SDL_QUIT){
      RequestQuit();
   }
}

void Game::RequestQuit()
{
   _isRunning = false;
}

void Game::CleanUp(){
   SDL_GL_DeleteContext(_glContext);
   SDL_DestroyWindow(_window);
   SDL_Quit();
}

int Game::GetFPS(){
   static const int FRAME_LIMIT = 32;
   static long frameTimes[FRAME_LIMIT];
   static int currentIndex = 0;
   static int lastTime = Time::GetTime();

   long currentTime = Time::GetTime();
   long delta = currentTime - lastTime;
   if (delta == 0)
   {
      delta = 1;
   }

   frameTimes[currentIndex] = delta;
   currentIndex = (currentIndex + 1) % FRAME_LIMIT;

   long totalTime = 0;
   for (int i = 0; i < FRAME_LIMIT; i++){
      totalTime += frameTimes[i];
   }

   lastTime = currentTime;

   long avgTime = totalTime / FRAME_LIMIT;

   if (avgTime > 0)
   {
      return 1000 / avgTime;
   }
   return TARGET_FPS;
}

void Game::PrintFPS(){
   int time = GetFPS();
   cout << time << "FPS" << endl;
}
