#include <stdio.h>
#include <stdlib.h>

int main() {

    char choice;
    double temp = 0.0;
    double conv = 0.0;

    printf("Temperature Conversion Program\n"
            "C. Celsius to Fahrenheit\n"
            "F. Fahrenheit to Celsius\n"
            "Is the temp in Celsius (C) or Fahrenheit (F)?: ");
    scanf("%c", &choice);
    fflush(stdin);

    if(choice == 'C'){
        printf("Enter the temperature in Celsius: ");
        scanf("%lf", &temp);
        fflush(stdin);
    }else if (choice = 'F'){
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%lf", &temp);
        fflush(stdin);

    }else{
        printf("Gerara Here mayn\n");
        exit(1);
    }

    if(choice == 'C'){
        conv = (temp * 9.0/5.0) + 32;
        printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", temp, conv);
    }else if(choice == 'F'){
        conv = (temp - 32) * (5.0/9.0);
        printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", temp, conv);
    }

    return 0;
}
