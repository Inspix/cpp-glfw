#pragma once

#include <iostream>
#include <sstream>
namespace inspix {
	namespace math {
		
		template<class T>
		struct Vec2 {

			union {
				T values[2];
				struct {
					T x, y;
				};
			};


			Vec2<T>();
			Vec2<T>(const T& value);
			Vec2<T>(const T& x, const T& y);

			Vec2<T>& add(const Vec2& other);
			Vec2<T>& sub(const Vec2& other);
			Vec2<T>& mul(const Vec2& other);
			Vec2<T>& mul(const T& other);
			Vec2<T>& div(const Vec2& other);
			Vec2<T>& div(const T& other);

			Vec2<T>& operator+=(const Vec2<T>& other);
			Vec2<T>& operator-=(const Vec2<T>& other);
			Vec2<T>& operator*=(const Vec2<T>& other);
			Vec2<T>& operator/=(const Vec2<T>& other);
			Vec2<T>& operator*=(const T& scalar);
			Vec2<T>& operator/=(const T& scalar);

			friend Vec2 operator+(Vec2 left, const Vec2& right) {
				return left.add(right);
			}
						
			friend Vec2 operator-(Vec2 left, const Vec2& right) {
				return left.sub(right);
			}

			friend Vec2 operator*(Vec2 left, const Vec2& right) {
				return left.mul(right);
			}
			
			friend Vec2 operator/(Vec2 left, const Vec2& right) {
				return left.div(right);
			}

			friend bool operator==(const Vec2<T>& left, const Vec2<T>& other) {
				return left.x == other.x && left.y == other.y;
			}

			friend bool operator!=(const Vec2<T>& left, const Vec2<T>& other) {
				return !(left == other);
			}


			std::string ToString() const;

			friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
				const char* name = typeid(vec).name();
				if (strstr(name, "char"))
				{
					stream << name << std::endl << "[" << (int)vec.x << ", " << (int)vec.y << "]";
				}
				else
				{
					stream << name << std::endl << "[" << vec.x << ", " << vec.y << "]";
				}
				return stream;
			}


		};

		template <typename T>
		Vec2<T>::Vec2()
		{
			x = 0;
			y = 0;
		}

		template <typename T>
		Vec2<T>::Vec2(const T& value) {
			x = value;
			y = value;
		}

		template <typename T>
		Vec2<T>::Vec2(const T& x, const T& y)
		{
			this->x = x;
			this->y = y;
		}

		template <typename T>
		Vec2<T>& Vec2<T>::add(const Vec2<T>& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		template <typename T>
		Vec2<T>& Vec2<T>::sub(const Vec2<T>& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}

		template <typename T>
		Vec2<T>& Vec2<T>::mul(const Vec2<T>& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}

		template <typename T>
		Vec2<T>& Vec2<T>::div(const Vec2<T>& other) {
			x /= other.x;
			y /= other.y;
			return *this;
		}

		template <typename T>
		Vec2<T>& Vec2<T>::mul(const T& scalar) {
			x *= scalar;
			y *= scalar;
			return *this;
		}

		template <typename T>
		Vec2<T>& Vec2<T>::div(const T& scalar) {
			x /= scalar;
			y /= scalar;
			return *this;
		}

		template <typename T>
		Vec2<T>& Vec2<T>::operator+=(const Vec2<T> & other)
		{
			return add(other);
		}

		template <typename T>
		Vec2<T>& Vec2<T>::operator-=(const Vec2<T>& other) {
			return sub(other);
		}

		template <typename T>
		Vec2<T>& Vec2<T>::operator*=(const Vec2<T>& other) {
			return mul(other);
		}

		template <typename T>
		Vec2<T>& Vec2<T>::operator/=(const Vec2<T>& other) {
			return div(other);
		}

		template <typename T>
		Vec2<T>& Vec2<T>::operator*=(const T& scalar) {
			return mul(scalar);
		}

		template <typename T>
		Vec2<T>& Vec2<T>::operator/=(const T& scalar) {
			return div(scalar);
		}
		
		template <typename T>
		std::string Vec2<T>::ToString() const
		{
			std::ostringstream ss;
			ss << *this;
			return ss.str();
		}		
	}
}