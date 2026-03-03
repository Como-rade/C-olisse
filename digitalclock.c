#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    time_t rawtime;
    struct tm *info;

    printf("DIGITAL CLOCK\n");

    while(true){

    time(&rawtime);
    info = localtime(&rawtime);
    printf("\r%02d:%02d:%02d", (info->tm_hour)%24, info->tm_min,
            info->tm_sec);
    fflush(stdout);
    //printf("\r");

    sleep(1);
    }


    return 0;

}
