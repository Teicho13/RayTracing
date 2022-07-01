#pragma once
#include <vector>

namespace Tmpl8
{
	class Ray;
	class PointLight;
	class Sphere;

	class Objects
	{
	public:
		Objects();

		bool hit(Ray& r, float t_min, float t_max);

		void createSpheres();
		void createLights();

		std::vector<Sphere*> spheres;
		std::vector<PointLight*> lights;
	};
}

