#version 130

in vec4 fragmentColor;
out vec4 color;

uniform float time;

void main(){
   float timeFactor = sin(time / 100.0);   
	color = clamp(vec4(fragmentColor.r*0.1*timeFactor, fragmentColor.g*timeFactor, fragmentColor.b*4.0*timeFactor, 1.0), 0.0, 1.0);
}