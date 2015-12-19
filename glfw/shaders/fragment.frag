#version 330 core

layout (location = 0) out vec4 clr;

uniform vec2 light;
uniform float intensity;

in vec4 position;
in vec4 vColor;

void main(){
	float lenght = 1.0 / length(position.xy - light) * intensity;
	clr = vColor * lenght;
}
