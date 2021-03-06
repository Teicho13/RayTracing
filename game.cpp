#include "precomp.h"
#include "game.h"

#include "output.h"

#include "Camera.h"
#include "Sphere.h"

#include "Material.h"

#include "Objects.h"

namespace Tmpl8
{
	//Main Trace function / screen output
	Output out;

	//Main Camera
	Camera cam;

	//Create Objects for the scene
	Objects obj;

	//Object list
	std::vector<Sphere*> spheres;

	void Game::Init()
	{
		out.CurColor = color(1, 0, 0);
		out.BackgroundCol = color(0.20f, 0.31f, 0.36f);
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

				out.CurColor = out.Trace(r,obj,0);

				out.write_color(screen, out.CurColor, i, j);
			}
		}
	}

	void Game::Shutdown()
	{

	}
};