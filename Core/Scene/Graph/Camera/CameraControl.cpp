#include "Camera.h"

FPSControl::FPSControl(Camera* camera) : CameraControl(camera){}
FPSControl::~FPSControl(){}

void FPSControl::Update(){

}

ArcBallControl::ArcBallControl(Camera* camera) : CameraControl(camera){}
ArcBallControl::~ArcBallControl(){}

void ArcBallControl::Update(){

}