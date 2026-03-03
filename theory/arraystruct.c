#include <stdio.h>

typedef struct{
    char model[25];
    int year;
    int price;
}Car;

int main(){

    Car cars[] = {{"Mustang", 1990, 15000},
                  {"Nissan", 20250, 26000},
                  {"Corvette", 2026, 60000}};
    int num = sizeof(cars)/sizeof(cars[0]);

    for(int i = 0; i < num; i++){
        printf("%s %d $%d\n", cars[i].model, cars[i].year, cars[i].price);
    }

    /*Car car1 = {"Mustang", 1990, 15000};
    Car car2 = {"Nissan", 2025, 26000};
    Car car3 = {"Corvette", 2026, 60000};*/

    //printf("%s %d $%d\n", car1.model, car1.year, car1.price);

    return 0;
}
