#include "Matrix4f.h"
using namespace Engine::Math;

Matrix4f Matrix4f::identity(){
   Matrix4f m;

   for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
         if (i == j){
            m(i,j) = 1;
         }
         else
         {
            m(i,j) = 0;
         }
      }
   }

   return m;
}

Matrix4f::Matrix4f()
{
   clear();
}

Matrix4f::~Matrix4f()
{
}

void Matrix4f::clear(){
   for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
         this->data[i][j] = 0;
      }
   }
}

float Matrix4f::operator()(int i, int j) const{
   return data[i][j];
}

float& Matrix4f::operator()(int i, int j){
   return data[i][j];
}

Matrix4f Engine::Math::operator + (const Matrix4f& matrix1, const Matrix4f& matrix2){
   Matrix4f m;
   for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
         m(i,j) = matrix1(i,j) + matrix2(i,j);
      }
   }
   return m;
}

Matrix4f Engine::Math::operator - (const Matrix4f& matrix1, const Matrix4f& matrix2){
   Matrix4f m;
   for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
         m(i, j) = matrix1(i, j) - matrix2(i, j);
      }
   }
   return m;
}

Matrix4f Engine::Math::operator - (const Matrix4f& matrix){
   return -1 * matrix;
}

Matrix4f Engine::Math::operator*(const Matrix4f& matrix1, const Matrix4f& matrix2){
   Matrix4f m;
   for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; i++){
         for (int k = 0; k < 4; k++){
            m(i, j) += matrix1(i, k) * matrix2(k, j);
         }
      }
   }
   return m;
}

Matrix4f Engine::Math::operator*(float scale, const Matrix4f& matrix){
   Matrix4f m;
   for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; i++){
         m(i, j) = scale*matrix(i, j);
      }
   }
   return m;
}

Matrix4f Engine::Math::operator*(const Matrix4f& matrix, float scale){
   return scale*matrix;
}

