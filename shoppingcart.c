#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

   char item[20];
   float price;
   int quantity;
   float tot;

   printf("What item would you like to buy?: ");
   fgets(item, sizeof(item), stdin);

   printf("What is the price of each?: ");
   scanf("%f", &price);
   getchar();

   printf("How many would you like?: ");
   scanf ("%d", &quantity);

   price = floorf(price * 100) / 100;

   tot = price * quantity;

    if(quantity <= 1) {
        item[strlen(item)-1] = '\0';
        printf("You have bought %d %s\nThe total is: $%.2f\n", quantity, item,
                tot);
    }else{
        item[strlen(item)-1] = 's';
        item[strlen(item)] = '\0';
        printf("You have bought %d %s\nThe total is: $%.2f\n", quantity, item
                ,tot);
    }

   return 0;
}
