#include <math.h>
#include "rad2volume.h"

/*
 in the rad2volume.h, there is no function prototype for cuber. Therefore,
 it is only available within this file.
 */
double cuber(double x){
    return(pow(x, 3.0)); 
}

double radius2volume(double rad){
    return((4.0/3.0) * MY_PI * cuber(rad));
}
