#include "Texture.h"


Texture::Texture() :
texId(0),
glImgId(0)
{
}

Texture::~Texture()
{
   if (glImgId)
   {
      glDeleteTextures(1, &glImgId);
   }
}

void Texture::Init(const std::string& filePath)
{
   ilGenImages(1, &texId); /* Generation of one image name */
   ilBindImage(texId); /* Binding of image name */
   bool success = ilLoadImage((const ILstring)filePath.c_str()); /* Loading of image "image.jpg" */
   if (success) /* If no error occured: */
   {
      success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE); /* Convert every colour component into
                                                          unsigned byte. If your image contains alpha channel you can replace IL_RGB with IL_RGBA */
      if (!success)
      {
         /* Error occured */
         fatal("Error loading texture file: %s", filePath.c_str());
      }

      glGenTextures(1, &glImgId); /* Texture name generation */
      glBindTexture(GL_TEXTURE_2D, glImgId); /* Binding of texture name */
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear
                                                                        interpolation for magnification filter */
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear
                                                                        interpolation for minifying filter */
      glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
         ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
         ilGetData()); /* Texture specification */
   }
   else
   {
      /* Error occured */
      fatal("Error loading texture file: %s", filePath.c_str());
   }
   ilDeleteImages(1, &texId); /* Because we have already copied image data into texture data
                              we can release memory used by image. */
}

void Texture::Bind()
{
   glBindTexture(GL_TEXTURE_2D, glImgId);
}

void Texture::Unbind()
{
   glBindTexture(GL_TEXTURE_2D, 0);
}