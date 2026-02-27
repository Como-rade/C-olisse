#include <stdio.h>

/*
   Convention in c is to use snake_case
 */

int main() {
    /*
    -In the parentheses, we examine a value
    -break are a must otherwise they will cascade into the other cases
    */
    // char day_of_week = 'l';
    char lo = 'l';
    printf("%d\n", lo);

    int day_of_week = 0;
    printf("Enter a day of the week: ");
    scanf("%d", &day_of_week);
    fflush(stdin);

    switch(day_of_week){
        case 1:
            printf("It is Monday\n");
            break;
        case 2:
            printf("It is Tuesday\n");
            break;
        case 'l': 
            printf("It is an L day\n");
            break;
        default:
            printf("Enter something valide\n");

        
    }

    return 0;

}
