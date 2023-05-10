#version 330 core

out vec4 fragColor;

in vec3 vertexColor;
in vec2 uvCoord;

uniform sampler2D ourTexture;

void main()
{
     fragColor = texture(ourTexture, uvCoord)* vec4(vertexColor, 1.0);;
}