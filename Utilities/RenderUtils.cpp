#include "RenderUtils.h"

void RenderUtils::ClearScreen(){
   //TODO: Stencil buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderUtils::InitGraphics(){
   /* Set SDL_GL attributes. */
   SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

   glClearColor(0.0f, 0.1f, 0.8f, 1.0f);

   //glFrontFace(GL_CW);
   //glCullFace(GL_BACK);
   //glEnable(GL_CULL_FACE);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   //TODO: Depth clamp for later

   glEnable(GL_FRAMEBUFFER_SRGB);
}