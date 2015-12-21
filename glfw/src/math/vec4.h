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

			Vec4<T>& add(const Vec4<T>& other);
			Vec4<T>& sub(const Vec4<T>& other);
			Vec4<T>& mul(const Vec4<T>& other);
			Vec4<T>& mul(const T& other);
			Vec4<T>& div(const Vec4<T>& other);
			Vec4<T>& div(const T& other);

			Vec4<T>& operator+=(const Vec4<T>& other);
			Vec4<T>& operator-=(const Vec4<T>& other);
			Vec4<T>& operator*=(const Vec4<T>& other);
			Vec4<T>& operator/=(const Vec4<T>& other);
			Vec4<T>& operator*=(const T& scalar);
			Vec4<T>& operator/=(const T& scalar);

			friend Vec4<T> operator+(Vec4<T> left, const Vec4<T>& right);
			friend Vec4<T> operator-(Vec4<T> left, const Vec4<T>& right);
			friend Vec4<T> operator*(Vec4<T> left, const Vec4<T>& right);
			friend Vec4<T> operator/(Vec4<T> left, const Vec4<T>& right);

			friend bool operator==(const Vec4<T>& left, const Vec4<T>& other);
			friend bool operator!=(const Vec4<T>& left, const Vec4<T>& other);

			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vec4<T>& vec);


		};

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
		Vec4<T> operator+(Vec4<T> left, const Vec4<T>& right) {
			return left.add(right);
		}

		template<typename T>
		Vec4<T> operator-(Vec4<T> left, const Vec4<T>& right) {
			return left.sub(right);
		}

		template<typename T>
		Vec4<T> operator*(Vec4<T> left, const Vec4<T>& right) {
			return left.mul(right);
		}

		template<typename T>
		Vec4<T> operator/(Vec4<T> left, const Vec4<T>& right) {
			return left.div(right);
		}

		template<typename T>
		bool operator==(const Vec4<T>& left, const Vec4<T>& other) {
			return left.x == other.x && left.y == other.y;
		}

		template<typename T>
		bool operator!=(const Vec4<T>& left, const Vec4<T>& other) {
			return !(left == other);
		}

		template<typename T>
		std::string Vec4<T>::ToString() const
		{
			std::ostringstream ss;
			ss << *this;
			return ss.str();
		}

		template<typename T>
		std::ostream& operator<<(std::ostream& stream, const Vec4<T>& vec) {
			stream << "Vec4<T>[" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << "]";
			return stream;
		}
	}
}