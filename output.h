#pragma once
#include "precomp.h"

namespace Tmpl8 {
	class Objects;
	class Ray;

	class Output
    {
    public:
        color Trace(Ray& r, Objects& obj);
        color Illumination(vec3 hitP, vec3 N, Objects& obj);

        void write_color(Surface* screen, color pixel_color, int posX, int posY);

        //Current Color
        color CurColor;
        color BackgroundCol;
    };
}
