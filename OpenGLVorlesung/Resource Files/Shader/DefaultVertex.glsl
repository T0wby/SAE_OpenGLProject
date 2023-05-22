#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec2 uv;
out vec3 vertexColor;
out vec3 Normal;
out vec2 uvCoord;

uniform mat4 transform;
uniform mat4 camMatrix;

void main()
{
    gl_Position = camMatrix * transform * vec4(position, 1.0);
    vertexColor = color;
    Normal = normal;
    uvCoord = uv;
}