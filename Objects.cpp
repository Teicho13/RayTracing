#include "precomp.h"
#include "Objects.h"

#include "Ray.h"

#include "Sphere.h"
#include "Material.h"

#include "PointLight.h"

namespace Tmpl8
{
	Objects::Objects()
	{
		createSpheres();
		createLights();
	}

	bool Objects::hit(Ray& r, float t_min, float t_max)
	{
		bool hit = false;
		for (unsigned int i = 0; i < spheres.size(); ++i)
		{
			if (spheres[i]->IntersectRay(r, t_min, t_max))
			{
				hit = true;
			}
		}
		return true;
	}

	void Objects::createSpheres()
	{
		//Ground Sphere
		Sphere* sph0 = new Sphere(vec3(0, 30.f, 1), 30.f, new Material(color(0.35f, 0.98f, 0.34f), diffuse));

		//Midle blue sphere
		Sphere* sph1 = new Sphere(vec3(0, 0, 5), 1.5f, new Material(color(0.11f, 0.56f, 1), mirror));

		Sphere* sph2 = new Sphere(vec3(3, 0, 5), 1.5f, new Material(color(0.84f, 0.07f, 0.07f), diffuse));
		Sphere* sph3 = new Sphere(vec3(-3, 0, 5), 1.5f, new Material(color(1.0f, 0.65f, 0.06f), diffuse));

		spheres.push_back(sph1);
		spheres.push_back(sph2);
		spheres.push_back(sph3);


		//do this last
		spheres.push_back(sph0);
	}

	void Objects::createLights()
	{
		//Lights
		PointLight* pl1 = new PointLight(vec3(-1, -3.5, 3.5), color(1, 1, 1), 3.3f);
		PointLight* pl2 = new PointLight(vec3(1, -3.5, 3.5), color(1, 1, 1), 3.3f);

		lights.push_back(pl1);
		lights.push_back(pl2);


	}
}
