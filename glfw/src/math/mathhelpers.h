#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace {
	void clamp(float& destination, const float& min, const float& max, const float& value) {
		if (value >= max)
		{
			destination = max;
		}
		else if (value <= min) {
			destination = min;
		}
		else {
			destination = value;
		}
	}

	float clamp(const float& min, const float& max, const float& value) {
		if (value >= max)
		{
			return max;
		}
		else if (value <= min) {
			return min;
		}
		else {
			return value;
		}
	}

	float toRadians(float degrees) {
		return degrees * (float)(M_PI / 180.0);
	}
	
	template<typename T>
	inline T sqr(T v) { return v*v; }
}