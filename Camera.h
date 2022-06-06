#pragma once
#include "Ray.h"

namespace Tmpl8
{
	class Camera
	{
	public:

		Camera();

		Ray GenerateRay(float u, float v);

		vec3 Origin;
		vec3 Direction;
		float distance;

		vec3 Center;
		vec3 p0, p1, p2;
	};
}


