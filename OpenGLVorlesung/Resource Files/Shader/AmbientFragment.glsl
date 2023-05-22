#version 330 core

out vec4 fragColor;

in vec3 vertexColor;
in vec2 uvCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 ambientLight;
uniform vec3 lightColor;

void main()
{
    //vec3 ambient = vec3(0.1f, 0.1f, 0.1f);
    float ambient = 0.5f;
    vec3 resultColor = ambient * vertexColor;

    fragColor = texture(texture1, uvCoord)* vec4(resultColor, 1.0);
}