#include "precomp.h"
#include "output.h"

#include "PointLight.h"
#include "Ray.h"
#include "Sphere.h"


namespace Tmpl8
{

    //Lights
    PointLight pl1 = PointLight(vec3(2, -2, 1));

    color Output::Trace(Ray& r, std::vector<Sphere*> s)
    {
	    for (unsigned int i = 0; i < s.size(); ++i)
	    {
            if (s[i]->IntersectRay(r))
            {
                vec3 HitPoint = r.Origin + r.Direction * r.t;
                vec3 N = s[i]->getNormal(HitPoint);

                if(s[i]->isMirror)
                {
                    vec3 ReflectDir = r.Direction - 2 * (r.Direction * N) * N;
                    vec3 reflectOr = HitPoint + ReflectDir * epsilon;

                    Ray reflectRay(reflectOr, ReflectDir,INFINITY);
                    color clr = s[i]->colr * 0.2;
                    return clr + Trace(reflectRay,s) * 0.8;
                }else
                {
	                
                }


                /*vec3 Dir = (pl1.Origin - HitPoint);
                Dir.normalize();
                float length = Dir.length();

                Ray sr(HitPoint, Dir, length);*/

                /*if(pl1.intersect(sr))
                {
                    return color(0, 0, 0);
                }*/

                return s[i]->colr ;
            }
	    }
        return BackgroundCol;
    }

	void Output::write_color(Surface* screen, color pixel_color, int posX, int posY)
	{
        //Get vector values
        float r1 = pixel_color.x;
        float g1 = pixel_color.y;
        float b1 = pixel_color.z;

        //Check if colors are completely black
        if (r1 == 0 && g1 == 0 && b1 == 0) {
            const int hexVal = ((static_cast<int>(r1) & 0xff) << 16) + ((static_cast<int>(g1) & 0xff) << 8) + (static_cast<int>(b1) & 0xff);
            screen->Plot(posX, (ScreenHeight - posY) - 1, hexVal);
            return;
        }

        //make RGB values from vector
        int r = static_cast<int>(256 * Clamp(r1, 0.0f, 0.999f));
        int g = static_cast<int>(256 * Clamp(g1, 0.0f, 0.999f));
        int b = static_cast<int>(256 * Clamp(b1, 0.0f, 0.999f));

        //add RGB values together to create a Hexvalue
        int hexVal = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);

        //print on screen and invert image vertically
        screen->Plot(posX, (ScreenHeight - posY) - 1, hexVal);
    }

}
