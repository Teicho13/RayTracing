#include "precomp.h"
#include "Ray.h"

namespace Tmpl8
{
	Ray::Ray()
	{
		Origin = vec3(0,0,0);
		Direction = vec3(0,0,0);
		t = 0;
	}

	Ray::Ray(vec3 orig, vec3 dir, float length)
	{
		Origin = orig;
		Direction = dir;
		t = length;
	}
}

