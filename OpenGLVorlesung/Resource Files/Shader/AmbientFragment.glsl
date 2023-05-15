#version 330 core

out vec4 fragColor;

in vec3 vertexColor;
in vec2 uvCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 ambientLight;

void main()
{
    vec3 ambient = vec3(0.5f, 0.5f, 0.5f);

    vec3 lighting = ambient;
    vec3 modelColor = vec3(0.75f, 0.75f, 0.75f);
    vec3 resultColor = ambient * modelColor;

    fragColor = texture(texture1, uvCoord)* vec4(resultColor, 1.0);
}