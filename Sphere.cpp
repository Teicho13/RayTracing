#include "precomp.h"
#include "Sphere.h"
#include "Ray.h"
namespace Tmpl8
{
	Sphere::Sphere(vec3 o, float r, color c, bool mir)
	{
		Origin = o;
		radius = r;
		colr = c;
		isMirror = mir;
	}

	bool Sphere::IntersectRay(Ray& r)
	{
		vec3 oc = r.Origin - Origin;
		float a = dot(r.Direction, r.Direction);
		float b = 2 * dot(r.Direction, oc);
		float r2 = radius * radius;
		float c = dot(oc, oc) - r2;

		float t0, t1 = 0;
		//Checking if we hit the sphere
		if(solveDisc(a, b, c,t0,t1))
		{
			return true;
		}
		return false;
	}

	bool Sphere::solveDisc(float a, float b, float c, float& t0, float& t1)
	{
		float discriminant = b * b - 4 * a * c;

		if(discriminant < 0)
		{
			//No solutions
			return false;
		}

		if(discriminant == 0)
		{
			//1 solution
			t0 = t1 = -b / (2 * a);
			return true;
		}

		t0 = (-b + sqrtf(discriminant)) / (2 * a);
		t1 = (-b - sqrtf(discriminant)) / (2 * a);
		return true;
	}

	vec3 Sphere::getNormal(vec3 point)
	{
		return normalize(point - Origin);
	}
}
