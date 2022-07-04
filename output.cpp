#include "precomp.h"
#include "output.h"

#include "Material.h"
#include "PointLight.h"
#include "Ray.h"
#include "Sphere.h"

#include "Objects.h"


namespace Tmpl8
{
    int depth = 0;
    color Output::Trace(Ray& r, Objects& obj, int depth)
    {
        if (depth >= 5) return BackgroundCol;

        for (unsigned int i = 0; i < obj.spheres.size(); ++i)
        {
            if (obj.spheres[i]->IntersectRay(r))
            {
                color clr = obj.spheres[i]->material->col * 0.2;

                if(obj.spheres[i]->material->type == diffuse)
                {
                    vec3 HitPoint = r.Origin + r.Direction * r.t;
                    vec3 N = obj.spheres[i]->getNormal(HitPoint, r.Direction);

                    return Illumination(HitPoint, N, obj) * obj.spheres[i]->material->col;
                }
                if (obj.spheres[i]->material->type == mirror)
                {


                    vec3 HitPoint = r.Origin + r.Direction * r.t;
                    vec3 N = obj.spheres[i]->getNormal(HitPoint);

                    vec3 reflectDir = reflect(r.Direction, N);

                    vec3 origin = HitPoint  * epsilon;
                    Ray reflectRay(origin, reflectDir,INFINITY);
                    color reflectionColor = Trace(reflectRay, obj, depth);

                    return reflectionColor;
                }
                if (obj.spheres[i]->material->type == dielectric)
                {
 


                }
            }

        }
        return BackgroundCol;
    }

    color Output::Illumination(vec3 hitP, vec3 N, Objects& obj)
    {
        vec3 LightEnergy(0);

        for (unsigned int i = 0; i < obj.lights.size(); ++i)
        {
            vec3 L = obj.lights[i]->Origin - hitP;
            vec3 Dir = normalize(L);
            Ray shadowRay(hitP, Dir, INFINITY);

            float lNormal = 1 / L.length();
            float NdotL = Max(0.0f, dot(N, L * lNormal));

            float l = L.length();
            if (NdotL > 0)
            {
                if(obj.hit(shadowRay, epsilon, l - 2 * epsilon))
                {
                    LightEnergy += (lNormal * NdotL) * obj.lights[i]->col * obj.lights[i]->intensity;
                }
            }
        }

        return LightEnergy;
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
