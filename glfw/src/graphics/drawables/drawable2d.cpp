#include "drawable2d.h"

namespace inspix {
	namespace graphics {

		GLuint Drawable2D::indicies[6] = { 0, 1, 2, 2, 3, 0};

		Drawable2D::Drawable2D(const math::Vec3f& position, const math::Vec2f& size, const Color& color) :
			Position(position),Size(size),m_Color(color)
		{
			m_Vao = new VertexArray();
			GLfloat vertecies[] = {
				0, 0, 0,
				0, 1, 0,
				1, 1, 0,
				1, 0, 0
			};

			GLuint colors[] = {
				color.abgr,
				color.abgr,
				color.abgr,
				color.abgr
			};

			Buffer* vbo = new Buffer(vertecies, 4 * 3, 3);
			Buffer* cbo = new Buffer(colors, 4, 4);

			m_Vao->addBuffer(vbo, 0);
			m_Vao->addBuffer(cbo, 1,GL_TRUE);

			m_Ibo = new IndexBuffer(Drawable2D::indicies, 6);
			recalculateTransform();

		}
		Drawable2D::~Drawable2D() {
			delete m_Vao;
			delete m_Ibo;
		}
		
		void Drawable2D::recalculateTransform() {
			m_Transform = math::Mat4::translation(Position) * Rotation.toMatrix4() * math::Mat4::scale(Size, 1.0f);

			vertecies[0] = m_Transform * math::Vec3f(0);
			vertecies[1] = m_Transform * math::Vec3f(0, 1, 0);
			vertecies[2] = m_Transform * math::Vec3f(1, 1, 0);
			vertecies[3] = m_Transform * math::Vec3f(1, 0, 0);
		}
	}
}