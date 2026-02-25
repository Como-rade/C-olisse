#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {


    double radius;
    double area_circle;
    double surface_sphere;
    double volume_sphere;

    printf("This is a simple program that will calculate the area of a circle,"
            "surface area and volume of a sphere given a radius.\n"
            "Enter a radius in cm: ");

    scanf("%lf", &radius);

    area_circle = M_PI * pow(radius, 2);
    surface_sphere = 4 * area_circle;
    volume_sphere = (4.0/3.0) * M_PI * pow(radius, 3);
    /*
     to have decimal value, you must add floating point (x.0) otherwise it will
     interpet it as an integer (3/4 = 0.00 where 3.0/4.0 = 0.75)
     */
    printf("Radius is %f cm\n"
            "Area of the circle is %f cm²\n"
            "Surface of the sphere is %f cm²\n"
            "Volume of the sphere is %f cm³\n",radius, area_circle,
            surface_sphere, volume_sphere);

    return 0;
}
