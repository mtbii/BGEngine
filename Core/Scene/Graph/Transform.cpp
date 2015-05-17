#include "Transform.h"


Transform::Transform() :
dirtyTransformMatrix(true)
{
   SetTranslation(glm::vec3(0.0f));
   SetRotation(glm::vec3(0.0f));
   SetScale(glm::vec3(1.0f));
}

Transform::Transform(const glm::vec3& trans, const glm::quat& rot, const glm::vec3& scale) :
transformMatrix(1.0f),
dirtyTransformMatrix(false)
{
   SetTranslation(trans);
   SetRotation(rot);
   SetScale(scale);
}

Transform::Transform(const glm::mat4& transMat, const glm::mat4& rotMat, const glm::mat4& scaleMat) :
transformMatrix(1.0f),
dirtyTransformMatrix(false)
{
   SetTranslation(transMat);
   SetRotation(rotMat);
   SetScale(scaleMat);
}

Transform::~Transform()
{
}

glm::vec3 Transform::GetTranslation()
{
   return translation;
}

glm::quat Transform::GetRotation()
{
   return rotation;
}

glm::vec3 Transform::GetScale()
{
   return scale;
}

void Transform::SetTranslation(const glm::vec3& trans)
{
   this->translation = trans;
   this->translationMatrix = glm::translate(glm::mat4(1.0f), translation);
   dirtyTransformMatrix = true;
}

void Transform::SetTranslation(const glm::mat4& transMat)
{
   this->translationMatrix = transMat;
   this->translation = glm::vec3(translationMatrix*glm::vec4(glm::vec3(0.0f), 1.0f));
   dirtyTransformMatrix = true;
}

void Transform::SetRotation(const glm::quat& rot)
{
   this->rotation = rot;
   this->rotationMatrix = glm::mat4_cast(rotation);
   dirtyTransformMatrix = true;
}

void Transform::SetRotation(const glm::mat4& rotMat)
{
   this->rotationMatrix = rotMat;
   this->rotation = glm::quat_cast(rotationMatrix);
   dirtyTransformMatrix = true;
}

void Transform::SetRotation(const glm::vec3& rotation)
{
   this->rotation = glm::quat(rotation);
   this->rotationMatrix = glm::mat4_cast(this->rotation);
}

void Transform::SetRotation(const float& x, const float& y, const float& z)
{
   SetRotation(glm::vec3(x, y, z));
}

void Transform::SetScale(const glm::vec3& scale)
{
   this->scale = scale;
   this->scaleMatrix = glm::scale(glm::mat4(1.0f), this->scale);
   dirtyTransformMatrix = true;
}

void Transform::SetScale(const glm::mat4& scaleMat)
{
   this->scaleMatrix = scaleMat;
   this->scale = glm::vec3(scaleMatrix*glm::vec4(glm::vec3(1.0f), 1.0f));
   dirtyTransformMatrix = true;
}

glm::mat4 Transform::GetTranslationMatrix()
{
   return translationMatrix;
}

glm::mat4 Transform::GetRotationMatrix()
{
   return rotationMatrix;
}

glm::mat4 Transform::GetScaleMatrix()
{
   return scaleMatrix;
}

glm::mat4 Transform::GetTransformMatrix()
{
   if (dirtyTransformMatrix)
   {
      transformMatrix = GetTranslationMatrix()*GetRotationMatrix()* GetScaleMatrix();
      dirtyTransformMatrix = false;
   }
   return transformMatrix;
}

glm::vec4 Transform::TransformVector(const glm::vec4& inputVec)
{
   return GetTransformMatrix()*inputVec;
}

glm::mat4 Transform::TransformMatrix(const glm::mat4& inputMat)
{
   return GetTransformMatrix()*inputMat;
}