#include "ModelUtils.h"
using namespace std;

std::vector<Model3D*> ModelUtils::LoadModel(const std::string& filePath)
{
   Assimp::Importer importer;
   const aiScene* scene = importer.ReadFile(filePath,
      aiProcessPreset_TargetRealtime_MaxQuality | aiProcess_OptimizeGraph | aiProcess_PreTransformVertices);

   if (scene == nullptr){
      fatal("Failed to load model file: %s\n%s", filePath.c_str(), importer.GetErrorString());
   }

   vector<Model3D*> models;

   for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; meshIndex++)
   {
      Model3D* model = new Model3D();
      vector<Vertex> vertices;
      vector<unsigned short> indices;
      aiMesh* mesh = scene->mMeshes[meshIndex];
      if (mesh->HasPositions())
      {
         for (unsigned int i = 0; i < mesh->mNumVertices; i++)
         {
            aiVector3D v = mesh->mVertices[i];
            aiColor4D c = aiColor4D((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0f);
            if (mesh->HasVertexColors(i))
            {
               c = *mesh->mColors[i];
            }

            vertices.push_back(Vertex(Position(v.x, v.y, v.z), Color(c.r, c.g, c.b, c.a)));
         }
      }
      if (mesh->HasFaces())
      {
         for (unsigned int i = 0; i < mesh->mNumFaces; i++)
         {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
            {
               indices.push_back(face.mIndices[j]);
            }
         }
      }

      model->Init();
      model->SetVertices(vertices, indices);
      models.push_back(model);
   }
   return models;
}