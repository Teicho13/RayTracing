#pragma once
namespace Tmpl8
{
	class Ray;

	class Sphere
	{
	public:
		Sphere(vec3 o, float r, color c);
		bool IntersectRay(Ray& r);

		vec3 Origin;
		float radius;
		color colr;
	};
}

