#pragma once

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include <iomanip>

namespace inspix {
	namespace math {
		struct Mat4 {

			float elements[16];

			Mat4();
			Mat4(float diagonalValue);
			

			Mat4& mul(const Mat4& other);
			Mat4& operator*=(const Mat4& other);
			friend Mat4 operator*(Mat4 left, const Mat4& right);

			static Mat4 identity();
			static Mat4 orthographic(float left, float right,float bottom, float top, float near, float far);
			static Mat4 perspective(float fov, float ratio, float near, float far);
			static Mat4 translation(float x, float y, float z);
			static Mat4 translation(const Vec3& vector);
			static Mat4 rotation(float angle, float x, float y, float z);
			static Mat4 rotation(float angle, const Vec3& axises);
			static Mat4 rotation(const Vec4& values);
			static Mat4 scale(float x, float y, float z);
			static Mat4 scale(const Vec3& value);

			std::string ToString();
		};
	}
}