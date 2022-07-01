#include "precomp.h"
#include "Material.h"

namespace Tmpl8
{
	Material::Material(vec3 col, MaterialType matType)
	{
		color = col;
		type = matType;
	}
}
