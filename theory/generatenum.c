#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("%d\n", rand()); //will generate the same value each time

    srand(time(NULL)); //current time with base seed

    printf("%d\n", rand()); /*because we set the seed differently, we get 
                            different result each time
                           */
    int random_num = (rand() % 2) + 1; //offset of +1

    printf("%d\n", random_num);

    int min = 1;
    int max = 6;

    random_num = (rand() % (max - min + 1)) + min; /* formula to print 
                                                      a "random" number
                                                      between min and max
                                                    */

    printf("%d\n", random_num);
    return 0;
}
