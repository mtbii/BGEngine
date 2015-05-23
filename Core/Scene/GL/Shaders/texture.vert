#version 130

in vec3 vertexPosition;
in vec2 vertexUV;

out vec2 uv;

uniform mat4 mvpMat;

void main(){
   gl_Position.xyzw = mvpMat*vec4(vertexPosition, 1);
   uv = vertexUV;
}