#pragma once

#include <GL/glew.h>
#include <vector>
#include <utils/fileutils.h>
#include <unordered_map>
#include "math/maths.h"

namespace inspix {
	namespace graphics {

		class ShaderProgram {
		private:
			GLuint m_ID;
			std::string m_VertexSource,m_FragSource;
			std::unordered_map<std::string, GLint> uniformCache;
		public:
			ShaderProgram(const char* vertpath, const char* fragpath);
			virtual ~ShaderProgram();

			void setUniform1(const std::string& name, const bool& value);
			void setUniform1(const std::string& name, const int& value);
			void setUniform1(const std::string& name, const unsigned int& value);
			void setUniform1(const std::string& name, const float& value);
			void setUniform1(const std::string& name, const double& value);
			void setUniform2(const std::string& name, const float& x, const float& y);
			void setUniform2(const std::string& name, const math::Vec2f& value);
			void setUniform3(const std::string& name, const float& x, const float& y, const float& z);
			void setUniform3(const std::string& name, const float& x, const math::Vec2f& yz);
			void setUniform3(const std::string& name, const math::Vec2f& xy, const float& z);
			void setUniform3(const std::string& name, const math::Vec3f& value);
			void setUniform4(const std::string& name, const float& x, const float& y, const float& z, const float& w);
			void setUniform4(const std::string& name, const float& x, const math::Vec2f& yz, const float& w);
			void setUniform4(const std::string& name, const float& x, const float& y, const math::Vec2f& zw);
			void setUniform4(const std::string& name, const math::Vec2f& xy,const float& z, const float& w);
			void setUniform4(const std::string& name, const float& x, const math::Vec3f& yzw);
			void setUniform4(const std::string& name, const math::Vec3f& xyz, const float& w);
			void setUniform4(const std::string& name, const math::Vec4f& xyzw);
			void setUniformMat4(const std::string& name, const math::Mat4& value);

			inline GLuint getId() const { return m_ID; }			
			inline std::string getVertSource() const { return m_VertexSource; }
			inline std::string getFragSource() const { return m_FragSource; }

		private:
			GLint getUniformLocation(std::string name);
			GLuint createShader(std::string source, GLenum type);
		};



	}
}