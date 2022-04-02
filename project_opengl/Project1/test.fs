#version 330 core
in vec3 oPos;
out vec4 color;
in vec2 oaTextrue;
in vec3 oaColor;
uniform sampler2D Textrue1;
uniform sampler2D Textrue2;
uniform float mixer = 1.0;
void main(){
	color = mix(texture(Textrue1,oaTextrue),texture(Textrue2,oaTextrue),mixer);
}