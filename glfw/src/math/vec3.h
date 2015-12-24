#pragma once

#include <iostream>
#include <sstream>
namespace inspix {
	namespace math {

		template<typename T>
		struct Vec3 {

			union {
				T values[3];
				struct {
					T x, y, z;
				};
				struct {
					T r, g, b;
				};
			};


			Vec3<T>();
			Vec3<T>(const T& value);
			Vec3<T>(const T& x, const T& y, const T& z);

			Vec3<T>& add(const Vec3<T>& other);
			Vec3<T>& sub(const Vec3<T>& other);
			Vec3<T>& mul(const Vec3<T>& other);
			Vec3<T>& mul(const T& other);
			Vec3<T>& div(const Vec3<T>& other);
			Vec3<T>& div(const T& other);
			void set(const T& x, const T& y, const T& z);

			Vec3<T>& operator+=(const Vec3<T>& other);
			Vec3<T>& operator-=(const Vec3<T>& other);
			Vec3<T>& operator*=(const Vec3<T>& other);
			Vec3<T>& operator/=(const Vec3<T>& other);
			Vec3<T>& operator*=(const T& scalar);
			Vec3<T>& operator/=(const T& scalar);

			friend Vec3 operator+(Vec3 left, const Vec3& right) {
				return left.add(right);
			}

			friend Vec3 operator-(Vec3 left, const Vec3& right) {
				return left.sub(right);
			}
			friend Vec3 operator*(Vec3 left, const Vec3& right) {
				return left.mul(right);
			}

			friend Vec3 operator/(Vec3 left, const Vec3& right) {
				return left.div(right);
			}

			friend bool operator==(const Vec3& left, const Vec3& other) {
				return left.x == other.x && left.y == other.y;
			}

			friend bool operator!=(const Vec3& left, const Vec3& other) {
				return !(left == other);
			}

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vec3& vec) {
				const char* name = typeid(vec).name();
				if (strstr(name, "char"))
				{
					stream << name << std::endl << "[" << (int)vec.x << ", " << (int)vec.y << ", " << (int)vec.z << "]";
				}
				else
				{
					stream << name << std::endl << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
				}
				return stream;
			}


		};

		template<typename T>
		Vec3<T>::Vec3()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		template<typename T>
		Vec3<T>::Vec3(const T& value) {
			x = value;
			y = value;
			z = value;
		}

		template<typename T>
		Vec3<T>::Vec3(const T& x, const T& y, const T& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		template<typename T>
		Vec3<T>& Vec3<T>::add(const Vec3<T>& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		template<typename T>
		Vec3<T>& Vec3<T>::sub(const Vec3<T>& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		template<typename T>
		Vec3<T>& Vec3<T>::mul(const Vec3<T>& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		template<typename T>
		Vec3<T>& Vec3<T>::div(const Vec3<T>& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		template<typename T>
		Vec3<T>& Vec3<T>::mul(const T& scalar) {
			x *= scalar;
			y *= scalar;
			z *= scalar;
			return *this;
		}

		template<typename T>
		Vec3<T>& Vec3<T>::div(const T& scalar) {
			x /= scalar;
			y /= scalar;
			z /= scalar;
			return *this;
		}
		
		template<typename T>
		void Vec3<T>::set(const T& x, const T& y, const T& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		template<typename T>
		Vec3<T>& Vec3<T>::operator+=(const Vec3<T> & other)
		{
			return add(other);
		}

		template<typename T>
		Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& other) {
			return sub(other);
		}

		template<typename T>
		Vec3<T>& Vec3<T>::operator*=(const Vec3<T>& other) {
			return mul(other);
		}

		template<typename T>
		Vec3<T>& Vec3<T>::operator/=(const Vec3<T>& other) {
			return div(other);
		}

		template<typename T>
		Vec3<T>& Vec3<T>::operator*=(const T& scalar) {
			return mul(scalar);
		}

		template<typename T>
		Vec3<T>& Vec3<T>::operator/=(const T& scalar) {
			return div(scalar);
		}

		

		template<typename T>
		std::string Vec3<T>::ToString() const
		{
			std::ostringstream ss;
			ss << *this;
			return ss.str();
		}
	}
}