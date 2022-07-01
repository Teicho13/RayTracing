#include "precomp.h"
#include "Sphere.h"
#include "Ray.h"
namespace Tmpl8
{
	Sphere::Sphere(vec3 o, float r, Material* mat)
	{
		Origin = o;
		radius = r;
		material = mat;
	}


	bool Sphere::IntersectRay(Ray& r)
	{
		vec3 oc = r.Origin - Origin;
		float a = dot(r.Direction, r.Direction);
		float b = 2 * dot(r.Direction, oc);
		float r2 = radius * radius;
		float c = dot(oc, oc) - r2;

		float t0, t1 = 0;
		//Checking if we hit the sphere
		if(solveDisc(a, b, c,t0,t1))
		{
			if(t0 > t1)
			{
				float temp = t0;
				t0 = t1;
				t1 = temp;
			}

			//is t0 negative ?
			if(t0 < 0.f)
			{
				t0 = t1;
				if(t0 < 0.f) return false; //Both are negative
			}

			r.t = t0;

			return true;
		}
		return false;
	}

	bool Sphere::IntersectRay(Ray& r, float t_min, float t_max)
	{
		vec3 oc = r.Origin - Origin;
		float half_b = dot(oc, r.Direction);
		float c = oc.sqrLentgh() - radius * radius;

		float discriminant = half_b * half_b - r.Direction.length() * c;
		if (discriminant < 0.0f) return false;
		float sqrtd = sqrtf(discriminant);

		// Find the nearest root that lies in the acceptable range.
		float root = (-half_b - sqrtd);
		if (root < t_min || t_max < root)
		{
			root = (-half_b + sqrtd);
			if (root < t_min || t_max < root)
			{
				return false;
			}
		}

		r.t = root;
		return true;
	}

	bool Sphere::solveDisc(float a, float b, float c, float& t0, float& t1)
	{
		float discriminant = b * b - 4 * a * c;

		if(discriminant < 0)
		{
			//No solutions
			return false;
		}

		if(discriminant == 0)
		{
			//1 solution
			t0 = t1 = -b / (2 * a);
			return true;
		}

		t0 = (-b + sqrtf(discriminant)) / (2 * a);
		t1 = (-b - sqrtf(discriminant)) / (2 * a);
		return true;
	}

	vec3 Sphere::getNormal(vec3 point, vec3 direction)
	{
		vec3 outward_normal = (point - Origin) / radius;
		bool frontFace = dot(direction, outward_normal) < 0;
		vec3 normal = frontFace ? outward_normal : -outward_normal;

		return normalize(normal);
	}
}
