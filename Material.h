#pragma once
namespace Tmpl8
{
	class Material
	{
	public:
		Material(vec3 col, MaterialType matType);

		vec3 color;
		float reflectionIndex;
		float refractionIndex;
		MaterialType type;
	};
}

