#include "scenenode.h"
#define TEST
namespace inspix {
	namespace graphics {

		SceneNode::SceneNode()
			:m_parent(nullptr)
			,m_children()
			,m_local()
		{
#ifdef TEST
			std::cout << "SceneNode created!" << std::endl;
#endif
		}

		SceneNode::~SceneNode() {
			m_parent = nullptr;
			m_children.clear();
#ifdef TEST
			std::cout << "SceneNode deleted!" << std::endl;
#endif
		}

		void SceneNode::update(float delta) {
			updateCurrent(delta);
			updateChildren(delta);
		}

		void SceneNode::render(const Transform& t) {
#ifdef TEST
			std::cout << "SceneNode rendered!" << std::endl;
#endif
			renderCurrent(t);
			renderChildren(t);
		}

		SceneNode& SceneNode::addChild(std::unique_ptr<SceneNode> node) {
			node->m_parent = this;
			SceneNode& ref = *node;
			m_children.push_back(std::move(node));

			return ref;
		}

		std::unique_ptr<SceneNode> SceneNode::detachChild(const SceneNode& node) {

			using Itr = std::vector<std::unique_ptr<SceneNode>>::iterator;
			for (
				Itr found = m_children.begin(); found != m_children.end(); ++found)
			{
				if (found->get() == &node)
				{
					std::unique_ptr<SceneNode> result = std::move(*found);
					result->m_parent = nullptr;
					m_children.erase(found);
					
					return result;
				}
			}

			return nullptr;
			
		}

		Transform& SceneNode::getGlobal(){
			if (m_parent == nullptr)
			{
				return m_local;
			}

			auto parent = m_parent;
			while (parent->getParent() != nullptr)
				parent = parent->getParent();			
			
			return parent->getLocal();
		}

		void SceneNode::renderChildren(const Transform& t) {
			for (std::unique_ptr<SceneNode> &node : m_children)
				node->render(t);
		}

		void SceneNode::updateChildren(float delta) {
			for (std::unique_ptr<SceneNode> &node : m_children)
				node->update(delta);
		}

	}
}