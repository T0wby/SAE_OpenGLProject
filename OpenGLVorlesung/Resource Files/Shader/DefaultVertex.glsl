#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
out vec3 vertexColor;

uniform mat4 camMatrix;
uniform mat4 transform;

void main()
{
    gl_Position = camMatrix * transform * vec4(position, 1.0);
    vertexColor = color;
}