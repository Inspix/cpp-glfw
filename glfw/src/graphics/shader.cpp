#include "shader.h"

namespace inspix {
	namespace graphics {
		ShaderProgram::ShaderProgram(const char* vertexpath, const char* fragpath)
		{
			m_VertexSource = readFile(vertexpath);
			if (m_VertexSource.empty())
			{
				std::cout << "Shader source empty: " << vertexpath << std::endl;
				return;
			}			
			GLuint vertID = createShader(m_VertexSource, GL_VERTEX_SHADER);
			if (vertID == 0)
			{
				return;
			}
			m_FragSource = readFile(fragpath);
			if (m_FragSource.empty())
			{
				std::cout << "Shader source empty: " << fragpath << std::endl;
				return;
			}
			GLuint fragID = createShader(m_FragSource, GL_FRAGMENT_SHADER);
			if (fragID == 0)
			{
				glDeleteShader(vertID);
				return;
			}

			m_ID = glCreateProgram();
			glAttachShader(m_ID, vertID);
			glAttachShader(m_ID, fragID);

			glLinkProgram(m_ID);

			GLint status = 0;
			glGetProgramiv(m_ID, GL_LINK_STATUS, &status);
			if (status == GL_FALSE)
			{
				GLint length = 0;
				glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> infoLog(length);
				glGetProgramInfoLog(m_ID, length, &length, &infoLog[0]);
				std::cout << &infoLog[0] << std::endl;

				glDeleteProgram(m_ID);

				return;
			}

			glValidateProgram(m_ID);
			glGetProgramiv(m_ID, GL_VALIDATE_STATUS, &status);
			if (status == GL_FALSE)
			{
				GLint length = 0;
				glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> infoLog(length);
				glGetProgramInfoLog(m_ID, length, &length, &infoLog[0]);
				std::cout << &infoLog[0] << std::endl;
				glDeleteProgram(m_ID);
			}

			glDeleteShader(vertID);
			glDeleteShader(fragID);

		}

		ShaderProgram::~ShaderProgram()
		{
		}

		GLuint ShaderProgram::createShader(std::string source, GLenum type) {
			
			GLuint id = glCreateShader(type);
			const char* cSource = source.c_str();
			glShaderSource(id, 1, &cSource, nullptr);
			glCompileShader(id);

			GLint status = 0;
			glGetShaderiv(id, GL_COMPILE_STATUS, &status);
			if (status == GL_FALSE) {
				std::cout << "Failed to compile shader: " << (type == GL_FRAGMENT_SHADER ? "Fragment" : "Vertex") << std::endl;

				GLint length = 0;
				glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> log(length);
				glGetShaderInfoLog(id, length, &length, &log[0]);
				std::cout << &log[0] << std::endl;


				glDeleteShader(id);
				return 0;
			}
			return id;
		}
	}
}