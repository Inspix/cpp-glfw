#pragma once

#include <application.h>
#include "graphics/shader.h"
#include "graphics/drawables/drawable2d.h"

using namespace inspix;
using namespace graphics;
using namespace math;
class Game : public inspix::Application {

	
private:
	ShaderProgram* m_Shader;
	input::Input* m_Input;
	Mat4 m_ProjectionMatrix;
	Vec2f m_light;
	float m_Intensity = 1;

public:
	Game();
	~Game();

	void update() override;
	void updateInput();
	void run() override;
	void init() override;

};