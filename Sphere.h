#pragma once
namespace Tmpl8
{
	class Ray;

	class Sphere
	{
	public:
		Sphere(vec3 o, float r, color c , bool mir);


		bool IntersectRay(Ray& r);
		bool solveDisc(float a, float b, float c, float& t0, float& t1);

		vec3 getNormal(vec3 point);

		vec3 Origin;
		float radius;
		color colr;
		bool isMirror;
	};
}

