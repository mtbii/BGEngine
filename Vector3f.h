#pragma once

namespace Engine
{
   namespace Math
   {
#include <math.h>
      class Vector3f
      {
      public:
         Vector3f(float x, float y, float z);
         ~Vector3f();

         float length();
         float dot(Vector3f v);
         Vector3f cross(Vector3f v);
         Vector3f normalize();

         Vector3f rotateDegrees(Vector3f axis, float angleInDegrees);
         Vector3f rotate(Vector3f axis, float angle);

         friend Vector3f operator+(const Vector3f& vec1, const Vector3f& vec2);
         friend Vector3f operator+(const Vector3f& vec1, float offset);

         friend Vector3f operator-(const Vector3f& vec1);
         friend Vector3f operator-(const Vector3f& vec1, const Vector3f& vec2);
         friend Vector3f operator-(const Vector3f& vec1, float offset);

         friend Vector3f operator*(const Vector3f& vec1, const Vector3f& vec2);
         friend Vector3f operator*(float scale, const Vector3f vec1);
         friend Vector3f operator*(const Vector3f vec1, float scale);

         friend Vector3f operator/(const Vector3f& vec1, const Vector3f& vec2);
         friend Vector3f operator/(const Vector3f& vec2, float scale);
         
         void setX(float x);
         float getX();
         void setY(float y);
         float getY();
         void setZ(float z);
         float getZ();
      private:
         float x;
         float y;
         float z;
      };
   }
}
