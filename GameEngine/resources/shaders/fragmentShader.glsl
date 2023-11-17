#version 330 core

out vec4 fragColour;

in vec2 texCoord;

uniform sampler2D pixels;

void main()
{
	fragColour = texture(pixels, texCoord);
}