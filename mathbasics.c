#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
   -math.h need to be linked with -lm flag when compiling
   -other math functions will also be in stdlib.h (abs for example)
*/

int main () {

    int x = 9;

    x = sqrt(x); //square root function

    printf("square root of 9 is %d\n", x);

    int y = 2;

    y = pow(y, 3); //power of (x is the variable, 3 is the power)

    printf("power of 2 to the 3 is %d\n", y);

    double d = 3.55;
    float z = 0.0f; //standard way to declare and initialize float
    z = 3.99;

    z = floorf(z); //floorf for float
    d = floor(d); //floor is used for double

    printf("z(float) floor is %f\nd(double) floor is %lf\n", z, d);


    int h = -3;

    h = abs(h); // absolute value

    printf("absolute value of -3 is %d\n", h);

    /*
    Check the man, many math function including log, sin, ect
     */





    return 0;
}
