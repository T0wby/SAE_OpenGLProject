#version 330 core

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

out vec4 fragColor;

in vec3 vertexColor;
in vec3 Normal;
in vec3 fragPos;
in vec2 uvCoord;

uniform sampler2D texture1;
uniform vec3 ambientLight;
uniform vec3 camPosition;
uniform Material material;
uniform Light light;

void main()
{
    // Ambient
    //vec3 ambient = vec3(0.1f, 0.1f, 0.1f);
    vec3 ambient = light.ambient * material.ambient; 
    
    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - fragPos);
    float diffImpact = max(dot(norm, lightDir), 0.0); // if angle between both above 90 we take 0 instead
    vec3 diffuse = light.diffuse * (diffImpact * material.diffuse);
    
    // Specular
    //float specularStrength = 0.5f;
    vec3 viewDir = normalize(camPosition - fragPos); // Direction of our Camera to the current fragment
    vec3 reflectDir = reflect(-lightDir, norm); // Direction of the reflected light
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);
    
    // Result
    vec3 resultColor = (ambient + diffuse + specular); // Alternatively we could add the vertex color

    fragColor = texture(texture1, uvCoord)* vec4(resultColor, 1.0);
}