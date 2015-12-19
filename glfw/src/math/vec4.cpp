#include "math/Vec4.h"

namespace inspix {
	namespace math {

		Vec4::Vec4(const float& value) {
			x = value;
			y = value;
			z = value;
			w = value;
		}

		Vec4::Vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vec4& Vec4::add(const Vec4& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}
		Vec4& Vec4::sub(const Vec4& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}
		Vec4& Vec4::mul(const Vec4& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}
		Vec4& Vec4::div(const Vec4& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}
		Vec4& Vec4::mul(const float& scalar) {
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}
		Vec4& Vec4::div(const float& scalar) {
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		Vec4& Vec4::operator+=(const Vec4 & other)
		{
			return add(other);
		}

		Vec4& Vec4::operator-=(const Vec4& other) {
			return sub(other);
		}

		Vec4& Vec4::operator*=(const Vec4& other) {
			return mul(other);
		}

		Vec4& Vec4::operator/=(const Vec4& other) {
			return div(other);
		}

		Vec4& Vec4::operator*=(const float& scalar) {
			return mul(scalar);
		}

		Vec4& Vec4::operator/=(const float& scalar) {
			return div(scalar);
		}

		Vec4 operator+(Vec4 left, const Vec4& right) {
			return left.add(right);
		}

		Vec4 operator-(Vec4 left, const Vec4& right) {
			return left.sub(right);
		}

		Vec4 operator*(Vec4 left, const Vec4& right) {
			return left.mul(right);
		}

		Vec4 operator/(Vec4 left, const Vec4& right) {
			return left.div(right);
		}

		bool operator==(const Vec4& left, const Vec4& other) {
			return left.x == other.x && left.y == other.y;
		}

		bool operator!=(const Vec4& left, const Vec4& other) {
			return !(left == other);
		}

		std::string Vec4::ToString() const
		{
			std::ostringstream ss;
			ss << *this;
			return ss.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vec4& vec) {
			stream << "Vec4[" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << "]";
			return stream;
		}
	}
}