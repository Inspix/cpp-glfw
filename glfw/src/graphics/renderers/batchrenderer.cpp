#include "batchrenderer.h"

namespace inspix {
	namespace graphics {
		BatchRenderer::BatchRenderer() {

		}
		BatchRenderer::~BatchRenderer() {
			delete m_IBO;

			glDeleteBuffers(1, &m_VertexDataBuffer);
		}

		void BatchRenderer::submit(const Drawable2D* drawable) {

		}
		void BatchRenderer::render() {

		}
		void BatchRenderer::begin() {

		}
		void BatchRenderer::end() {

		}
	}
}