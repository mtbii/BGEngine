#pragma once
#include <math.h>
#include "Vector3f.h"

namespace Engine
{
   namespace Math
   {

      class Quaternion
      {
      public:
         Quaternion();
         Quaternion(float x, float y, float z, float w);
         ~Quaternion();

         float length();
         Quaternion normalize();
         Quaternion conjugate();
         Quaternion dot(Quaternion q);
         Quaternion cross(Quaternion q);

         float getX();
         void setX(float x);
         float getY();
         void setY(float y);
         float getZ();
         void setZ(float z);
         float getW();
         void setW(float w);
         
         friend Quaternion operator*(Quaternion q1, Quaternion q2);
         friend Quaternion operator*(Quaternion q1, Vector3f v1);

      private:
         float x;
         float y;
         float z;
         float w;
      };
   }
}
