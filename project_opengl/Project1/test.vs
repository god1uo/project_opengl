#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTextrue;
out vec3 oaColor;
out vec2 oaTextrue;
void main(){
	gl_Position = vec4(aPos, 1.0);
	oaColor = aColor;
	oaTextrue = aTextrue;
}