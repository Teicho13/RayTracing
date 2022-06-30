#include "precomp.h"
#include "output.h"

#include "PointLight.h"
#include "Ray.h"
#include "Sphere.h"


namespace Tmpl8
{

    //Lights
    PointLight pl1 = PointLight(vec3(1, -10, 3),color(255,255,255),0.2f);

    color Output::Trace(Ray& r, std::vector<Sphere*> s)
    {
        vec3 LightEnergy(0);
	    for (unsigned int i = 0; i < s.size(); ++i)
	    {
            if (s[i]->IntersectRay(r,0,INFINITY))
            {
                vec3 HitPoint = r.Origin + r.Direction * r.t;

                vec3 Dir = (pl1.Origin - HitPoint);
                Dir.normalize();

                float length = Dir.length();

                float LNormal = 1 / length;

                float NdotL = Max(0.0f, dot(HitPoint, Dir * LNormal));


                Ray Shadowray(HitPoint, Dir, INFINITY);

                if(NdotL > 0)
                {
                    if (!s[i]->IntersectRay(Shadowray, 0.01f, length - 2 * 0.01f))
                    {
                        vec3 hitP = Shadowray.Origin + Shadowray.Direction * Shadowray.t;
                        vec3 outward_normal = (hitP - s[i]->Origin) / s[i]->radius;
                        bool frontface = dot(Shadowray.Direction, outward_normal) < 0;
                        vec3 normal = frontface ? outward_normal : -outward_normal;
                        color col = s[i]->colr;
                        //rec.mat = m_Mat;
                        LightEnergy += (1 / LNormal * NdotL) * pl1.col * pl1.intensity;
                        //return color(0, 0, 0);
                    }
                }

                

                return LightEnergy * s[i]->colr;
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
        //and Clamp them to 255

        int r = static_cast<int>(Clamp(r1, 0.0f, 255.0f));
        int g = static_cast<int>(Clamp(g1, 0.0f, 255.0f));
        int b = static_cast<int>(Clamp(b1, 0.0f, 255.0f));

        //add RGB values together to create a Hexvalue
        const int hexVal = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);

        //print on screen and invert image vertically
        screen->Plot(posX, (ScreenHeight - posY) - 1, hexVal);
    }

}
