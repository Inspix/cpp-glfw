#pragma once

#include "types.h"
#include "mathhelpers.h"
#include <iomanip>

namespace inspix {
	namespace math {
		struct Mat4 {

			union {
				float elements[16];
				Vec4f columns[4];
			};

			Mat4();
			Mat4(float diagonalValue);			

			Mat4& mul(const Mat4& other);
			Mat4& operator*=(const Mat4& other);
			friend Mat4 operator*(Mat4 left, const Mat4& right);
			static Mat4 identity();
			static Mat4 orthographic(float left, float right,float bottom, float top, float near, float far);
			static Mat4 perspective(float fov, float ratio, float near, float far);
			static Mat4 translation(float x, float y, float z);
			static Mat4 translation(const Vec3f& vector);
			static Mat4 rotation(float angle, float x, float y, float z);
			static Mat4 rotation(float angle, const Vec3f& axises);
			static Mat4 rotation(const Vec4f& values);
			static Mat4 scale(float x, float y, float z);
			static Mat4 scale(const Vec2f& xy, float z);
			static Mat4 scale(float x, const Vec2f& yz);
			static Mat4 scale(const Vec3f& value);

			std::string ToString();
		};
	}
}