#include "precomp.h"
#include "PointLight.h"
#include "Ray.h"

namespace Tmpl8
{
	PointLight::PointLight(vec3 o)
	{
		Origin = o;
	}

	bool PointLight::intersect(Ray& r)
	{
		vec3 c = Origin - r.Origin;
		float t = dot(c, r.Direction);
		if(t < 0) return false;
		vec3 q = c - t * r.Direction;

		if(q.x == 0 && q.y == 0 && q.z == 0)
		{
			r.t = t;
			return true;
		}
		return false;
	}
}
