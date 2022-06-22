#include "precomp.h"
#include "Sphere.h"
#include "Ray.h"
namespace Tmpl8
{
	Sphere::Sphere(vec3 o, float r, color c)
	{
		Origin = o;
		radius = r;
		colr = c;
	}

	bool Sphere::IntersectRay(Ray& r)
	{
		vec3 c = Origin - r.Origin;
		float t = dot(c, r.Direction);
		vec3 q = c - (t * r.Direction);
		float q2 = dot(q, q);
		float r2 = dot(radius, radius);

		if(q2 > r2) return false;

		float rayT = t - sqrtf(r2 - q2);
		if (rayT < r.t && rayT >= epsilon) {
			r.t = rayT;
			return true;
		}
		return false;
	}
}
