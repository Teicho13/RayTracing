#include "precomp.h"
#include "output.h"

#include "Material.h"
#include "PointLight.h"
#include "Ray.h"
#include "Sphere.h"


namespace Tmpl8
{

    //Lights
    PointLight pl1 = PointLight(vec3(-1, -3.5, 3.5), color(1, 1, 1), 3.3f);

    color Output::Trace(Ray& r, std::vector<Sphere*> s)
    {
        vec3 LightEnergy(0);

        for (unsigned int i = 0; i < s.size(); ++i)
        {
            if (s[i]->IntersectRay(r))
            {
                vec3 HitPoint = r.Origin + r.Direction * r.t;
                vec3 N = s[i]->getNormal(HitPoint,r.Direction);

                vec3 L = pl1.Origin - HitPoint;
                vec3 Dir = normalize(L);
                Ray shadowRay(HitPoint, Dir, INFINITY);

                float lNormal = 1 / L.length();
                float NdotL = Max(0.0f, dot(N, L * lNormal));


                float l = L.length();

                if (NdotL > 0)
                {
                    if (!s[i]->IntersectRay(shadowRay, epsilon, l - 2 * epsilon))
                    {
                        LightEnergy += (lNormal * NdotL) * pl1.col * pl1.intensity;
                    }
                }
                return LightEnergy * s[i]->material->col;
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
