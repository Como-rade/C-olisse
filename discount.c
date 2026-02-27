#include <stdio.h>


int main(){

    char is;
    double price = 10.00;
    double total = 0.0;

    printf("Are you a student (S), senior(N) or both(B)?: ");
    scanf("%c", &is);
    fflush(stdin);

    switch(is){
        case 'S':
            total = price - (price*0.10);
            printf("Your total as a student is %.2lf\n", total);
            break;
        case 'N':
            total = price - (price*0.20);
            printf("Your total as a senior is %.2lf\n", total);
            break;
        case 'B':
            total = price - (price*0.10) - (price*0.20);
            printf("Your total as a senior and a student is %.2lf\n", total);
    }

}
