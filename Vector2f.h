#pragma once
#include <math.h>

namespace Engine
{
   namespace Math
   {
      class Vector2f
      {
      public:
         Vector2f();
         Vector2f(float x, float y);
         ~Vector2f();

         float length();
         float dot(Vector2f v);
         Vector2f normalize();

         Vector2f rotateDegrees(float angleInDegrees);
         Vector2f rotate(float angle);

         friend Vector2f operator+(const Vector2f& vec1, const Vector2f& vec2);
         friend Vector2f operator+(const Vector2f& vec1, float offset);

         friend Vector2f operator-(const Vector2f& vec1);
         friend Vector2f operator-(const Vector2f& vec1, const Vector2f& vec2);
         friend Vector2f operator-(const Vector2f& vec1, float offset);

         friend Vector2f operator*(const Vector2f& vec1, const Vector2f& vec2);
         friend Vector2f operator*(float scale, const Vector2f vec1);
         friend Vector2f operator*(const Vector2f vec1, float scale);

         friend Vector2f operator/(const Vector2f& vec1, const Vector2f& vec2);
         friend Vector2f operator/(const Vector2f& vec2, float scale);

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
