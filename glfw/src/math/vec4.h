#pragma once

#include <iostream>
#include <sstream>
namespace inspix {
	namespace math {

		template<typename T>
		struct Vec4 {			
			
			union {
				T values[4];
				struct {
					T x, y, z, w;
				};
				struct {
					T r, g, b, a;
				};
			};

			Vec4<T>() = default;
			Vec4<T>(const T& value);
			Vec4<T>(const T& x, const T& y,const T& z, const T& w);

			inline Vec2<T> xy() const { return Vec2<T>(x, y); }
			inline Vec2<T> yz() const { return Vec2<T>(y, z); }
			inline Vec2<T> xz() const { return Vec2<T>(x, z); }

			inline Vec3<T> xyz() const { return Vec3<T>(x, y, z); }
			inline Vec3<T> yzw() const { return Vec3<T>(y, z , w); }
			


			Vec4<T>& add(const Vec4<T>& other);
			Vec4<T>& sub(const Vec4<T>& other);
			Vec4<T>& mul(const Vec4<T>& other);
			Vec4<T>& mul(const T& other);
			Vec4<T>& div(const Vec4<T>& other);
			Vec4<T>& div(const T& other);
			T magnitude();
			T dot(const Vec4<T>& other);
			Vec4<T>& normalize();

			static Vec4<T> normalized(const Vec4<T>& vec);
			static T dot(const Vec4<T>& lhs, const Vec4<T>& rhs);

			Vec4<T> operator-() const;
			Vec4<T>& operator+=(const Vec4<T>& other);
			Vec4<T>& operator-=(const Vec4<T>& other);
			Vec4<T>& operator*=(const Vec4<T>& other);
			Vec4<T>& operator/=(const Vec4<T>& other);
			Vec4<T>& operator*=(const T& scalar);
			Vec4<T>& operator/=(const T& scalar);

			
			friend Vec4 operator+(Vec4 left, const Vec4& right) {
				return left.add(right);
			}

			friend Vec4 operator-(Vec4 left, const Vec4& right) {
				return left.sub(right);
			}

			friend Vec4 operator*(Vec4 left, const Vec4& right) {
				return left.mul(right);
			}

			friend Vec4 operator/(Vec4 left, const Vec4& right) {
				return left.div(right);
			}

			friend bool operator==(const Vec4& left, const Vec4& other) {
				return left.x == other.x && left.y == other.y;
			}

			friend bool operator!=(const Vec4& left, const Vec4& other) {
				return !(left == other);
			}

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vec4& vec) {
				const char* name = typeid(vec).name();
				if (strstr(name, "char"))
				{
					stream << name << std::endl << "[" << (int)vec.x << ", " << (int)vec.y << ", " << (int)vec.z << ", " << (int)vec.w << "]";
				}
				else
				{
					stream << name <<  std::endl << "[" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << "]";
				}
				return stream;
			}


		};

		/*---------------- Constructors --------------*/

		template<typename T>
		Vec4<T>::Vec4(const T& value) {
			x = value;
			y = value;
			z = value;
			w = value;
		}

		template<typename T>
		Vec4<T>::Vec4(const T& x, const T& y, const T& z, const T& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		
		/*---------------- METHODS ----------------*/

		template<typename T>
		Vec4<T>& Vec4<T>::add(const Vec4<T>& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		template<typename T>
		Vec4<T>& Vec4<T>::sub(const Vec4<T>& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}

		template<typename T>
		Vec4<T>& Vec4<T>::mul(const Vec4<T>& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}

		template<typename T>
		Vec4<T>& Vec4<T>::div(const Vec4<T>& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}
		
		template<typename T>
		Vec4<T>& Vec4<T>::mul(const T& scalar) {
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;
			return *this;
		}

		template<typename T>
		Vec4<T>& Vec4<T>::div(const T& scalar) {
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;
			return *this;
		}

		template<typename T>
		T Vec4<T>::dot(const Vec4<T>& other) {
			return x * other.x + y * other.y + z * other.z + w * other.w;
		}

		template<typename T>
		T Vec4<T>::dot(const Vec4<T>& lhs, const Vec4<T>& rhs) {
			return lhs.dot(rhs);
		}

		template<typename T>
		T Vec4<T>::magnitude() {
			return sqrt(sqr(x) + sqr(y) + sqr(z) + sqr(w));
		}

		template<typename T>
		Vec4<T>& Vec4<T>::normalize() {
			T length = magnitude();
			x /= length;
			y /= length;
			z /= length;
			w /= length;

			return *this;
		}

		template<typename T>
		Vec4<T> Vec4<T>::normalized(const Vec4<T>& vec) {
			T length = vec.magnitude();

			return vec / length;
		}
		/*------------------ OPERATORS -----------------*/

		template<typename T>
		Vec4<T> Vec4<T>::operator-() const {
			return Vec4<T>(-x, -y, -z, -w);
		}

		template<typename T>
		Vec4<T>& Vec4<T>::operator+=(const Vec4<T> & other)
		{
			return add(other);
		}

		template<typename T>
		Vec4<T>& Vec4<T>::operator-=(const Vec4<T>& other) {
			return sub(other);
		}

		template<typename T>
		Vec4<T>& Vec4<T>::operator*=(const Vec4<T>& other) {
			return mul(other);
		}

		template<typename T>
		Vec4<T>& Vec4<T>::operator/=(const Vec4<T>& other) {
			return div(other);
		}

		template<typename T>
		Vec4<T>& Vec4<T>::operator*=(const T& scalar) {
			return mul(scalar);
		}

		template<typename T>
		Vec4<T>& Vec4<T>::operator/=(const T& scalar) {
			return div(scalar);
		}

		
		
		template<typename T>
		std::string Vec4<T>::ToString() const
		{
			std::ostringstream ss;
			ss << *this;
			return ss.str();
		}		
	}
}