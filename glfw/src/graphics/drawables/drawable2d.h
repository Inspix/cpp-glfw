#pragma once

#include "../shader.h"
#include "../buffers/vertexarray.h"
#include "../buffers/buffer.h"
#include "../buffers/indexBuffer.h"
#include "../color.h"
#include "math/quaternion.h"

namespace inspix {
	namespace graphics {
			
		class Drawable2D {
		protected:
			static GLuint indicies[6];
			Color m_Color;
			math::Mat4 m_Transform;
			math::Vec3f vertecies[4];
			VertexArray* m_Vao;
			IndexBuffer* m_Ibo;
		public:
			math::Vec3f Position;
			math::Vec2f Size;
			math::Quaternion Rotation;

			Drawable2D(const math::Vec3f& position, const math::Vec2f& size, const Color& color);
			virtual ~Drawable2D();

			void recalculateTransform();
			inline VertexArray* getVao() const { return m_Vao; }
			inline const math::Vec3f* getVertecies() const { return vertecies; }
			inline const IndexBuffer* getIbo() const { return m_Ibo; }
			inline const Color& getColor() const { return m_Color; }
			inline const math::Mat4& getTransform() const { return m_Transform; }

		};


	}
}