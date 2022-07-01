#pragma once
#include <vector>

namespace Tmpl8
{
	class PointLight;
	class Sphere;

	class Objects
	{
	public:
		Objects();


		std::vector<Sphere*> spheres;
		std::vector<PointLight*> lights;
	};
}

