#version 330 core

out vec4 fragColor;

in vec3 vertexColor;
in vec2 uvCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    //fragColor = mix(texture(texture1, uvCoord), texture(texture2, uvCoord), 0.2)* vec4(vertexColor, 1.0);
    //fragColor = texture(texture1, uvCoord)* vec4(vertexColor, 1.0);
    fragColor = vec4(vertexColor, 1.0);
}