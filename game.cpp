#include "precomp.h"
#include "game.h"

#include "output.h"

#include "Camera.h"
#include "Sphere.h"

#include "Material.h"

namespace Tmpl8
{
	//Main Trace function / screen output
	Output out;

	//Main Camera
	Camera cam;

	//Sphere Obj
	//Ground
	Sphere* sph0 = new Sphere(vec3(0, 30.f, 1), 30.f, new Material(color(0.35f, 0.98f, 0.34f),diffuse));
	Sphere* sph1 = new Sphere(vec3(0, 0, 5), 1.5f, new Material(color(0.11f, 0.56f, 1),diffuse));

	//Object list
	std::vector<Sphere*> spheres;

	void Game::Init()
	{
		out.CurColor = color(1, 0, 0);
		out.BackgroundCol = color(0.20f, 0.31f, 0.36f);
		spheres.push_back(sph1);
		spheres.push_back(sph0);
	}

	void Game::Tick(float deltaTime)
	{
		for (int j = 0; j < ScreenHeight; j++)
		{
			for (int i = 0; i < ScreenWidth; i++)
			{

				float u = static_cast<float>(i) / static_cast<float>(ScreenWidth);
				float v = static_cast<float>(j) / static_cast<float>(ScreenHeight);

				Ray r = cam.GenerateRay(u, v);

				out.CurColor = out.Trace(r,spheres);

				out.write_color(screen, out.CurColor, i, j);
			}
		}
	}

	void Game::Shutdown()
	{

	}
};