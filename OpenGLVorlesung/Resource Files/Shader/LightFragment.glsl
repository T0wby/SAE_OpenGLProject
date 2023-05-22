#version 330 core

out vec4 fragColor;

in vec3 vertexColor;
in vec2 uvCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 ambientLight;

void main()
{
    fragColor = vec4(vertexColor, 1.0);
}