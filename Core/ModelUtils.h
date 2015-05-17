#pragma once

#include <vector>
#include "Scene/GL/Model3D.h"
#include "../Utilities/Log.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class ModelUtils
{
public:
   static std::vector<Model3D*> LoadModel(const std::string& filePath);
};

