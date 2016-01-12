#pragma once

#include "types.h"
#include "mathhelpers.h"
#include "quaternion.h"
#include <iomanip>

namespace inspix {
	namespace math {
		struct Mat4 {

			union {
				float elements[16];
				Vec4f columns[4];
				struct {
					float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
				};
			};

			Mat4();
			Mat4(float diagonalValue);			

			Mat4& mul(const Mat4& other);
			Vec3f mul(const Vec3f& other);
			Mat4& operator*=(const Mat4& other);
			float operator[](size_t index) const;
			float& operator[](size_t index);
			float get(size_t row, size_t col) const;
			float& get(size_t row, size_t col);
			friend Mat4 operator*(Mat4 left, const Mat4& right);
			friend Vec3f operator*(Mat4 left, const Vec3f& right);
			static Mat4 identity();
			static Mat4 orthographic(float left, float right,float bottom, float top, float near, float far);
			static Mat4 perspective(float fov, float ratio, float near, float far);
			static Mat4 translation(float x, float y, float z);
			static Mat4 translation(const Vec3f& vector);
			static Mat4 rotation(float angle, float x, float y, float z);
			static Mat4 rotation(float angle, const Vec3f& axises);
			static Mat4 rotation(const Vec4f& values);
			static Mat4 rotation(const Quaternion& q, const Vec3f& point);
			static Mat4 scale(float x, float y, float z);
			static Mat4 scale(const Vec2f& xy, float z);
			static Mat4 scale(float x, const Vec2f& yz);
			static Mat4 scale(const Vec3f& value);

			std::string ToString() const;
			friend std::ostream& operator << (std::ostream& os, const Mat4& mat);
		
		};
	}
}