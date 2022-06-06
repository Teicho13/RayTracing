#pragma once
#include "precomp.h"

namespace Tmpl8 {
	class Sphere;
	class Ray;

	class Output
    {
    public:
        color Trace(Ray& r, std::vector<Sphere*> s);

        void write_color(Surface* screen, color pixel_color, int posX, int posY);

        //Current Color
        color CurColor;
    };
}
