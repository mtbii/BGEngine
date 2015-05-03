#include "Game.h"
using namespace Engine;

Game::Game() :
_isRunning(false),
_window(nullptr),
_screen(nullptr),
_renderer(nullptr),
_title("3D Engine"),
_height(480),
_width(640)
{
}

Game::Game(string title, int width, int height){
   this->_title = title;
   this->_height = height;
   this->_width = width;
}

Game::~Game()
{
   _window = nullptr;
   _screen = nullptr;
   _renderer = nullptr;
}

bool Game::init(){
   if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
      error("Cannot initialize SDL!");
      return false;
   }

   if ((_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE)) == nullptr)
   {
      error("Cannot create SDL window!");
      return false;
   }

   if ((_screen = SDL_GetWindowSurface(_window)) == nullptr)
   {
      error("Cannot get window surface!");
      return false;
   }

   return true;
}

int Game::execute(){
   if (init() == false){
      return -1;
   }

   int unprocessedTime = 0;
   const int frameTime = round(1000.0 / TARGET_FPS);
   bool mustRender = false;
   _isRunning = true;
   SDL_Event event;
   Time::delta();

   while (_isRunning){
      while (SDL_PollEvent(&event)){
         onEvent(&event);
      }

      while (unprocessedTime > frameTime)
      {
         update();
         unprocessedTime -= frameTime;
         mustRender = true;
      }

      if (mustRender)
      {
         render();
         mustRender = false;

#if DEBUG
         printFPS();
#endif
      }
      else
      {
         SDL_Delay(2);
      }

      unprocessedTime += Time::delta();
   }

   cleanup();
   return 0;
}

void Game::update(){

}

void Game::render(){
   SDL_FillRect(_screen, nullptr, SDL_MapRGB(_screen->format, 0xFF, 0xFF, 0xFF));
   SDL_UpdateWindowSurface(_window);
}

void Game::onEvent(SDL_Event* event){
   if (event->type == SDL_QUIT){
      _isRunning = false;
   }
}

void Game::cleanup(){
   SDL_DestroyWindow(_window);
   SDL_Quit();
}

int Game::getFPS(){
   static const int FRAME_LIMIT = 8;
   static long frameTimes[FRAME_LIMIT];
   static int currentIndex = 0;
   static int lastTime = Time::getTime();

   long currentTime = Time::getTime();
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

void Game::printFPS(){
   int time = getFPS();
   cout << time << "FPS" << endl;
}
