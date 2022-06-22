#pragma once
namespace Tmpl8
{
	class Ray;

	class PointLight
	{
	public:

		PointLight(vec3 o);

		bool intersect(Ray& r);

		vec3 Origin;
	};
}

