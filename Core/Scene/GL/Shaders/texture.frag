#version 130

in vec2 uv;
out vec4 color;

uniform sampler2D texUnit;

void main(){
   color = texture2D(texUnit, uv);
}