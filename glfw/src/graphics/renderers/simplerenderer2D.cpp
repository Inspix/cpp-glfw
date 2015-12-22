#include "simplerenderer2D.h"


namespace inspix{
	namespace graphics {
		SimpleRenderer2D::SimpleRenderer2D(ShaderProgram& shader) : m_Shader(shader){}


		SimpleRenderer2D::~SimpleRenderer2D() {}

		void SimpleRenderer2D::submit(const Drawable2D* drawable) {
			m_Drawables.push_back(drawable);
		}

		void SimpleRenderer2D::render() {
			glUseProgram(m_Shader.getId());
			while (!m_Drawables.empty()) {
				const Drawable2D* current = m_Drawables.front();
				
				current->getVao()->bind();
				current->getIbo()->bind();

				m_Shader.setUniformMat4("ml_matrix", current->getTransform());
				glDrawElements(GL_TRIANGLES, current->getIbo()->getCount(), GL_UNSIGNED_INT, NULL);

				current->getIbo()->unbind();
				current->getVao()->unbind();

				m_Drawables.pop_front();
			}
		}
	}
}

