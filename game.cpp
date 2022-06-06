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
	Sphere sph1 = Sphere(vec3(0, 0, 5), 1.0f,color(30,144,255));

	void Game::Init()
	{
		out.CurColor = color(255, 0, 0);
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

				out.CurColor = out.Trace(r,sph1);

				out.write_color(screen, out.CurColor, i, j);
			}
		}
	}

	void Game::Shutdown()
	{

	}
};