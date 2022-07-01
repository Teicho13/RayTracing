#pragma once
namespace Tmpl8
{
	class Material
	{
	public:
		Material();
		Material(vec3 c, MaterialType matType);


		color col;
		float reflectionIndex;
		float refractionIndex;
		MaterialType type;
	};
}

