#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (){

    int choice = 0;
    double weight = 0.0;
    double conversion = 0.0;
    double set_value = 2.205;

    printf("Weight Conversion Calculator\n"
            "1. Kilograms to Pounds\n"
            "2. Pounds to Kilograms\n"
            "Enter your choise (1 or 2): ");

    scanf("%d", &choice);
    fflush(stdin);

    if(choice == 1){
        printf("Enter the weight in kilograms: ");
        scanf("%lf", &weight);
        fflush(stdin);
    }else if(choice == 2){
        printf("Enter the weight in pounds: ");
        scanf("%lf", &weight);
        fflush(stdin);
    }else{
        printf("You never listen.\n");
        exit(1);
    }

    if(choice == 1){
        conversion = weight * set_value;
        printf("%.2lf kilograms is equal to %.2lf pounds\n", weight, conversion);
    }else if (choice == 2){
        conversion = weight/ set_value;
        printf("%.2lf pounds is equal to %.2lf kilogram\n", weight, conversion);
    }else{
        printf("You truly never listen");
    }

}
