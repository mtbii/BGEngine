#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/quaternion.hpp>
#include<glm/gtx/quaternion.hpp>
#include<glm/gtc/matrix_transform.hpp>

class Transform
{
public:
   Transform();
   Transform(const glm::vec3& trans, const glm::quat& rot, const glm::vec3& scale);
   Transform(const glm::mat4& transMat, const glm::mat4& rotMat, const glm::mat4& scaleMat);
   ~Transform();

   glm::vec3 GetTranslation();
   glm::quat GetRotation();
   glm::vec3 GetScale();

   void SetTranslation(const glm::vec3& trans);
   void SetRotation(const glm::quat& rot);
   void SetScale(const glm::vec3& scale);

   void SetTranslation(const glm::mat4& transMat);
   void SetRotation(const glm::mat4& rotMat);
   void SetRotation(const glm::vec3& eulerAngles);
   void SetRotation(const float& x, const float& y, const float& z);
   void SetScale(const glm::mat4& scaleMat);

   glm::mat4 GetTranslationMatrix();
   glm::mat4 GetRotationMatrix();
   glm::mat4 GetScaleMatrix();

   glm::mat4 GetTransformMatrix();
   glm::vec4 TransformVector(const glm::vec4& inputVec);
   glm::mat4 TransformMatrix(const glm::mat4& inputMat);

private:
   bool dirtyTransformMatrix;
   glm::vec3 translation;
   glm::quat rotation;
   glm::vec3 scale;

   glm::mat4 translationMatrix;
   glm::mat4 rotationMatrix;
   glm::mat4 scaleMatrix;
   glm::mat4 transformMatrix;
};

