#include "precomp.h"
#include "game.h"

#include "output.h"

#include "Camera.h"
#include "Sphere.h"

namespace Tmpl8
{
	//Main Trace function / screen output
	Output out;

	//Main Camera
	Camera cam;

	//Sphere Obj
	Sphere* sph0 = new Sphere(vec3(0, 4, 3), 2.5f, color(0.35f, 0.98f, 0.34f), false);
	Sphere* sph1 = new Sphere(vec3(0, 0, 5), 1.0f,color(0.11f,0.56f,1),false);
	Sphere* sph2 = new Sphere(vec3(-1, 2, 5), 1.0f,color(0.54f,1,0.03f),true);

	//Object list
	std::vector<Sphere*> spheres;

	void Game::Init()
	{
		out.CurColor = color(1, 0, 0);
		out.BackgroundCol = color(0.20f, 0.31f, 0.36f);
		spheres.push_back(sph1);
		spheres.push_back(sph2);
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