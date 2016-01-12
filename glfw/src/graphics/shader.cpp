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
			glDeleteProgram(m_ID);
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

		void ShaderProgram::setUniform1(const std::string& name, bool value) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform1i(location,value);
		}
		void ShaderProgram::setUniform1(const std::string& name, int value) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform1i(location, value);
		}
		void ShaderProgram::setUniform1(const std::string& name, unsigned int value) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform1ui(location, value);
		}
		void ShaderProgram::setUniform1(const std::string& name, float value) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform1f(location, value);
		}
		void ShaderProgram::setUniform1(const std::string& name, double value) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform1f(location, (GLfloat)value);
		}
		void ShaderProgram::setUniform2(const std::string& name, float x, float y) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform2f(location, x,y);
		}
		void ShaderProgram::setUniform2(const std::string& name, const math::Vec2f& value) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform2f(location, value.x, value.y);
		}
		void ShaderProgram::setUniform3(const std::string& name, float x, float y, float z) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform3f(location, x, y, z);
		}
		void ShaderProgram::setUniform3(const std::string& name, float x, const math::Vec2f& yz) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform3f(location, x, yz.x, yz.y);
		}
		void ShaderProgram::setUniform3(const std::string& name, const math::Vec2f& xy, float z) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform3f(location, xy.x, xy.y, z);
		}
		void ShaderProgram::setUniform3(const std::string& name, const math::Vec3f& value) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform3f(location, value.x, value.y, value.z);
		}
		void ShaderProgram::setUniform4(const std::string& name, float x, float y, float z, float w) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform4f(location, x, y, z, w);
		}
		void ShaderProgram::setUniform4(const std::string& name, float x, const math::Vec2f& yz, float w) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform4f(location, x, yz.x, yz.y, w);
		}
		void ShaderProgram::setUniform4(const std::string& name, float x, float y, const math::Vec2f& zw) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform4f(location, x, y, zw.x, zw.y);
		}
		void ShaderProgram::setUniform4(const std::string& name, const math::Vec2f& xy, float z, float w) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform4f(location, xy.x, xy.y, z, w);
		}
		void ShaderProgram::setUniform4(const std::string& name, float x, const math::Vec3f& yzw) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform4f(location, x, yzw.x, yzw.y, yzw.z);
		}
		void ShaderProgram::setUniform4(const std::string& name, const math::Vec3f& xyz, float w) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform4f(location, xyz.x, xyz.y, xyz.z, w);
		}
		void ShaderProgram::setUniform4(const std::string& name, const math::Vec4f& xyzw) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniform4f(location, xyzw.x, xyzw.y, xyzw.z, xyzw.w);
		}

		void ShaderProgram::setUniformMat4(const std::string& name, const math::Mat4& value) {
			GLint location = getUniformLocation(name);
			if (location == -1)
			{
				return;
			}
			glUniformMatrix4fv(location,1,GL_FALSE, value.elements);
		}

		GLint ShaderProgram::getUniformLocation(std::string name) {
			GLint value = uniformCache[name];
			if (value != 0)
			{
				if (value == -1)
				{
					std::cout << "Uniform " << name << " not found in shader." << std::endl;
				}
				return uniformCache[name];
			}

			GLint result = glGetUniformLocation(m_ID, name.c_str());

			if (result == -1)
			{
				std::cout << "Uniform " << name << " not found in shader." << std::endl;
			}
			uniformCache[name] = result;

			return result;
		}
	}
}