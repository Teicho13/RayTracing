#pragma once
namespace Tmpl8
{
	class Ray;

	class Sphere
	{
	public:
		Sphere(vec3 o, float r, color c , bool mir);
		bool IntersectRay(Ray& r);
		bool IntersectRay(Ray& r, float t_min, float t_max);

		vec3 getNormal(vec3 point);

		vec3 Origin;
		float radius;
		color colr;
		bool isMirror;
	};
}

