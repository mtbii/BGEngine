#pragma once
#include "glew.h"

struct Point{
   Point() : x(0), y(0){};
   Point(int _x, int _y){
      x = _x;
      y = _y;
   }

   int x;
   int y;
};

struct Position{
   Position() : x(0), y(0), z(0){};
   Position(float _x, float _y, float _z)
   {
      x = _x;
      y = _y;
      z = _z;
   }

   float x;
   float y;
   float z;
};

struct Color{
   Color() : r(0), g(0), b(0), a(0){};
   Color(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a)
   {
      r = _r;
      g = _g;
      b = _b;
      a = _a;
   }

   Color(int _r, int _g, int _b, int _a)
   {
      r = _r;
      g = _g;
      b = _b;
      a = _a;
   }

   Color(double _r, double _g, double _b, double _a)
   {
      r = (GLubyte)(255 * _r);
      g = (GLubyte)(255 * _g);
      b = (GLubyte)(255 * _b);
      a = (GLubyte)(255 * _a);
   }

   Color(float _r, float _g, float _b, float _a)
   {
      r = (GLubyte)(255 * _r);
      g = (GLubyte)(255 * _g);
      b = (GLubyte)(255 * _b);
      a = (GLubyte)(255 * _a);
   }

   GLubyte r;
   GLubyte g;
   GLubyte b;
   GLubyte a;
};

struct Vertex{
   Vertex(){};
   Vertex(Position pos, Color col)
   {
      position = pos;
      color = col;
   }

   Position position;
   Color color;

   static const int POSITION_SIZE = 3;
   static const int COLOR_SIZE = 4;
};