#include <stdio.h>

int main(){
    
    double first_num = 0.0;
    double second_num = 0.0;
    double total = 0.0;
    char operator = '\0';

    printf("Enter the first number: ");
    scanf("%lf", &first_num);
    getchar();

    printf("Enter the operator (+ - * /): ");
    scanf("%c", &operator);

    printf("Enter the second number: ");
    scanf("%lf", &second_num);


    switch(operator){
        case '+':
            total = first_num + second_num;
            printf("Addition result is %.2lf\n", total);
            break;
        case '-':
            total = first_num - second_num;
            printf("Substraction result is %.2lf\n", total);
            break;
        case '*':
            total = first_num * second_num;
            printf("Multiplication reuslt is %.2lf\n", total);
            break;
        case '/':
            total = first_num / second_num;
            printf("Division result is %.2lf\n", total);
            break;
        default:
            printf("You must enter a valid operator.\n");

    }

}
