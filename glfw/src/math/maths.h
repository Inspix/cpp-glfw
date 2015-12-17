#pragma once

#include "mat4.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace inspix {
	namespace math {
		static void clamp(float& destination, const float& min, const float& max, const float& value) {
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

		static float toRadians(float degrees) {
			return degrees * M_PI / 180.0f;
		}
	}
}