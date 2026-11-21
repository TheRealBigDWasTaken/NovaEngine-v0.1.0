#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 2) in vec2 aUV;

uniform mat4 uTransform;
uniform mat4 uView;
uniform mat4 uProjection;

out vec2 vUV;

void main(){
	gl_Position = uProjection * uView * uTransform * vec4(aPos, 0, 1);
	vUV = aUV;
}