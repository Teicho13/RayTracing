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

	bool Sphere::IntersectRay(Ray& r, float t_min, float t_max)
	{
		vec3 oc = r.Origin - Origin;
		float half_b = dot(oc, r.Direction);
		float c = oc.sqrLentgh() - radius * radius;

		float discriminant = half_b * half_b - r.Direction.length() * c;
		if (discriminant < 0.0f) return false;
		float sqrtd = sqrtf(discriminant);

		// Find the nearest root that lies in the acceptable range.
		float root = (-half_b - sqrtd);
		if (root < t_min || t_max < root)
		{
			root = (-half_b + sqrtd);
			if (root < t_min || t_max < root)
			{
				return false;
			}
		}

		r.t = root;
		return true;
	}

	vec3 Sphere::getNormal(vec3 point)
	{
		return normalize(point - Origin);
	}
}
