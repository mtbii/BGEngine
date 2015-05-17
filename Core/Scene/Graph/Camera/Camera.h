#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
protected:
   glm::mat4 viewMatrix;
   glm::mat4 projectionMatrix;

public:
   virtual void Update() = 0;
   inline glm::mat4 GetVPMatrix()
   {
      Update();
      return projectionMatrix*viewMatrix;
   }
};

class CameraControl
{
private:
   Camera* controlledCamera;

public:
   inline CameraControl(Camera* camera){ controlledCamera = camera; }
   virtual void Update() = 0;
};

class ArcBallControl : public CameraControl
{
public:
   ArcBallControl(Camera* camera);
   ~ArcBallControl();
   virtual void Update();
};

class FPSControl : public CameraControl
{
public:
   FPSControl(Camera* camera);
   ~FPSControl();
   virtual void Update();
};

