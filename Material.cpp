#include "precomp.h"
#include "Material.h"

namespace Tmpl8
{
	Material::Material()
	{
		col = color(0);
		type = diffuse;
	}

	Material::Material(color c, MaterialType matType)
	{
		col = c;
		type = matType;
	}
}
