#include "precomp.h"
#include "PointLight.h"
#include "Ray.h"

namespace Tmpl8
{
	PointLight::PointLight(vec3 o, color c, float i)
	{
		Origin = o;
		col = c;
		intensity = i;
	}
}
