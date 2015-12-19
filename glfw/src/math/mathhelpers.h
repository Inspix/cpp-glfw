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

	float toRadians(float degrees) {
		return degrees * (float)(M_PI / 180.0);
	}
}