#include "math/Vec3.h"

namespace inspix {
	namespace math {

		Vec3::Vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		Vec3::Vec3(const float& value) {
			x = value;
			y = value;
			z = value;
		}

		Vec3::Vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vec3& Vec3::add(const Vec3& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}
		Vec3& Vec3::sub(const Vec3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}
		Vec3& Vec3::mul(const Vec3& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}
		Vec3& Vec3::div(const Vec3& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}
		Vec3& Vec3::mul(const float& scalar) {
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}
		Vec3& Vec3::div(const float& scalar) {
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}		

		void Vec3::set(const float& x, const float& y, const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vec3& Vec3::operator+=(const Vec3 & other)
		{
			return add(other);
		}

		Vec3& Vec3::operator-=(const Vec3& other) {
			return sub(other);
		}

		Vec3& Vec3::operator*=(const Vec3& other) {
			return mul(other);
		}

		Vec3& Vec3::operator/=(const Vec3& other) {
			return div(other);
		}

		Vec3& Vec3::operator*=(const float& scalar) {
			return mul(scalar);
		}

		Vec3& Vec3::operator/=(const float& scalar) {
			return div(scalar);
		}

		Vec3 operator+(Vec3 left, const Vec3& right) {
			return left.add(right);
		}

		Vec3 operator-(Vec3 left, const Vec3& right) {
			return left.sub(right);
		}

		Vec3 operator*(Vec3 left, const Vec3& right) {
			return left.mul(right);
		}

		Vec3 operator/(Vec3 left, const Vec3& right) {
			return left.div(right);
		}

		bool operator==(const Vec3& left, const Vec3& other) {
			return left.x == other.x && left.y == other.y;
		}

		bool operator!=(const Vec3& left, const Vec3& other) {
			return !(left == other);
		}

		std::string Vec3::ToString() const
		{
			std::ostringstream ss;
			ss << *this;
			return ss.str();			
		}

		std::ostream& operator<<(std::ostream& stream, const Vec3& vec) {
			stream << "Vec3[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
			return stream;
		}
	}
}