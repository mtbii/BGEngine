#pragma once

namespace Engine
{
   namespace Math
   {
#include <math.h>
      class Vector2f
      {
      public:
         Vector2f(float x, float y);
         ~Vector2f();

         float length();
         float dot(Vector2f v);
         Vector2f normalize();

         Vector2f rotateDegrees(float angleInDegrees);
         Vector2f rotate(float angle);

         friend Vector2f operator+(const Vector2f& vec1, const Vector2f& vec2);
         friend Vector2f operator-(const Vector2f& vec1);
         friend Vector2f operator-(const Vector2f& vec1, const Vector2f& vec2);

         void setX(float x);
         float getX();
         void setY(float y);
         float getY();
      private:
         float x;
         float y;
      };
   }
}
