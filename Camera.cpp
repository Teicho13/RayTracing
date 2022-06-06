#include "precomp.h"
#include "Camera.h"

namespace Tmpl8
{
	Camera::Camera()
	{
		Origin = vec3(0,0,0);
		Direction = vec3(0, 0, 1);
		distance = 1.0f;

		Center = Origin + Direction * distance;
		p0 = Center + vec3(-1,1, 0);
		p1 = Center + vec3(1,1, 0);
		p2 = Center + vec3(-1,-1, 0);
	}

	Ray Camera::GenerateRay(float u, float v)
	{
		vec3 Point = p0 + (p1 - p0) * u + (p2 - p0) * v;
		vec3 RayDir = Point - Origin;
		return Ray(Origin, RayDir.normalized(), 100);
	}
}

