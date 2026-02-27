#include <stdio.h>
#include <stdbool.h>

int main() {

    bool is_student = false;
    bool is_senior = true;
    double discount_student = 0.10;
    double discount_senior = 0.20;
    double price = 10.00;
    double total = 0.0;

    if(is_student && is_senior){
        total = price - (price * discount_student) - (price * discount_senior);
        printf("Your total as a student and a senior is %.2lf\n", total);

    }else if(is_student){
        total = price - (price * discount_student);
        printf("Your total as a student is %.2lf\n", total);

    }else if(is_senior){
        total = price - (price *discount_senior);
        printf("Your total as a senior is %.2lf\n", total);

    }

}
