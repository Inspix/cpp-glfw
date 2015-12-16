#version 330 core

layout (location = 0) in vec4 vertex;

uniform mat4 pr_matrix;
uniform mat4 v_matrix;
uniform mat4 m_matrix;

void main(){
	gl_Position = pr_matrix * v_matrix * m_matrix * vertex;
}