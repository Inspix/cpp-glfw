#pragma once

#include <GL/glew.h>
#include <vector>
#include <utils/fileutils.h>

namespace inspix {
	namespace graphics {

		class ShaderProgram {
		private:
			GLuint m_ID;
			std::string m_VertexSource,m_FragSource;
		public:
			ShaderProgram(const char* vertpath, const char* fragpath);
			virtual ~ShaderProgram();

			inline GLuint getId() const { return m_ID; }			
			inline std::string getVertSource() const { return m_VertexSource; }
			inline std::string getFragSource() const { return m_FragSource; }

		private:
			GLuint createShader(std::string source, GLenum type);
		};



	}
}