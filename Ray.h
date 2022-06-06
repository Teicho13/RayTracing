#pragma once
namespace Tmpl8
{
	class Ray
	{
	public:
		Ray();
		Ray(vec3 orig, vec3 dir, float length);

		vec3 Origin;
		vec3 Direction;
		float t; // Distance
	};
}

