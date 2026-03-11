#include <stdio.h>
#include "rad2volume.h"

int my_function()
{
     static int counter = 0;
     return counter++;
}

int main(void){
    double radius = 3.0, volume; /*radius is declared and initialized, while
                                   volume is only declared. A trick to not
                                   repeat the word double multiple times
                                  */
    volume = radius2volume(radius);
    printf("Pi is approximated as %.3f.\n", MY_PI);
    printf("Volume of a sphere with radius 3.0 is %.3f.\n", volume);

    printf("Value of static counter: %d\n", my_function());
    printf("Value of static counter: %d\n", my_function());
    printf("Value of static counter: %d\n", my_function());
    printf("%10d\n", LOL);
    
    return 0;
}
