#pragma once

namespace Engine
{
   namespace Math
   {
      class Matrix4f
      {
      public:
         Matrix4f();
         ~Matrix4f();

         void init();
         friend Matrix4f operator*(const Matrix4f& matrix1, const Matrix4f& matrix2);
         friend Matrix4f operator*(float scale, const Matrix4f& matrix);
         friend Matrix4f operator*(const Matrix4f& matrix, float scale);
      };
   }
}

