#version 130

in vec3 vertexPosition;
in vec4 vertexColor;

out vec4 fragmentColor;
out vec4 transformed;

uniform mat4 translationMat;
uniform mat4 rotationMat;
uniform mat4 scaleMat;

void main(){
	gl_Position.xyzw = translationMat*rotationMat*scaleMat*vec4(vertexPosition, 1);

	fragmentColor = vertexColor;
}