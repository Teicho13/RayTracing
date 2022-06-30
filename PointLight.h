#pragma once
namespace Tmpl8
{
	class Ray;

	class PointLight
	{
	public:

		PointLight(vec3 o, color c, float i);

		vec3 Origin;
		color col;
		float intensity;
	};
}

