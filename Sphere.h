#pragma once


namespace Tmpl8
{
	class Material;
	class Ray;

	class Sphere
	{
	public:
		Sphere(vec3 o, float r, Material* mat);


		bool IntersectRay(Ray& r);
		bool IntersectRay(Ray& r, float t_min,float t_max);
		bool solveDisc(float a, float b, float c, float& t0, float& t1);

		vec3 getNormal(vec3 point);
		vec3 getNormal(vec3 point, vec3 direction);
		

		vec3 Origin;
		float radius;
		Material* material;
	};
}

