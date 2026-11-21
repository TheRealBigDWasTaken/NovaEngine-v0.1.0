#version 330 core

uniform sampler2D uTexture;
uniform vec3 uColor;

out vec4 FragColor;

in vec2 vUV;

void main()
{
    FragColor = texture(uTexture, vUV) * vec4(uColor, 1.0);
}