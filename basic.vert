#version 130

in vec3 vertexPosition;
in vec4 vertexColor;

out vec4 fragmentColor;
out vec4 transformed;

uniform mat4 mvpMat;

void main(){
	gl_Position.xyzw = mvpMat*vec4(vertexPosition, 1);

	fragmentColor = vertexColor;
}