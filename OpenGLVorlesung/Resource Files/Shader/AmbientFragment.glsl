#version 330 core

out vec4 fragColor;

in vec3 vertexColor;
in vec3 Normal;
in vec3 fragPos;
in vec2 uvCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 ambientLight;
uniform vec3 lightColor;
uniform vec3 lightPos;

void main()
{
    //vec3 ambient = vec3(0.1f, 0.1f, 0.1f);
    float ambient = 0.5f; 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diffImpact = max(dot(norm, lightDir), 0.0); // if angle between both above 90 we take 0 instead
    vec3 diffuse = diffImpact * lightColor;
    vec3 resultColor = (ambient + diffuse) * vertexColor;

    //fragColor = texture(texture1, uvCoord)* vec4(resultColor, 1.0);
    fragColor = vec4(resultColor, 1.0);
}