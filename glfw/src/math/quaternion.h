#pragma once


namespace inspix {
	namespace math {

		struct Quaternion {
			union {
				float data[4];
				struct {
					float x;
					float y;
					float z;
					float w;
				};
			};

			Quaternion();
			


		};


	}
}