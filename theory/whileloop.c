#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    
    int long num = 0;
    char numstring[4];
    char *endptr;


    while(num <= 0){
        printf("Enter a number greater than 0: ");
        fgets(numstring, sizeof(numstring), stdin);
        numstring[strlen(numstring)-1] = '\0';
        num = strtol(numstring, &endptr, 10);

    }

    do{

        printf("do{}while(); will check the condition at the end, so it will"
                " atleast loop once\n");
    }while(false);

    return 0;

}
