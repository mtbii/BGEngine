#include "Game.h"

Game::Game(Window& window)
{
   this->window = window;
}

Game::~Game()
{
}

bool Game::Init(){

   if (window.glContext == nullptr)
   {
      return false;
   }
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
         //SDL_Delay(1);
      }

      unprocessedTime += Time::Delta();
   }

   CleanUp();
   return 0;
}

void Game::Update(){

}

void Game::Render(){
   SDL_GL_SwapWindow(window.sdl_window);
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
