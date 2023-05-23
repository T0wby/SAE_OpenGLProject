#version 330 core
struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

out vec4 fragColor;

in vec3 vertexColor;
in vec3 Normal;
in vec2 uvCoord;

uniform sampler2D texture1;
uniform Light light;

void main()
{
    fragColor = vec4(vertexColor * light.diffuse, 1.0);
}