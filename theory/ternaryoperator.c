#include <stdio.h>
#include <stdbool.h>

int main() {

    int x = 5;
    int y = 6;
    /*
     the ternary operator is the ?.
     equivalent to if-else
     the () are not needed but better for readability
     */
    int max = (x > y) ? x : y;
    printf("%d\n", max);

    bool is_online = false;
    printf("%s\n", (is_online) ? "Is Online" : "Is Offline");

    int odd_even = 6;
    printf("%d %s\n", odd_even, (odd_even % 2 == 0) ? "Is even" : "Is odd");
    
    int age = 13;
    printf("%s\n", (age >= 18) ? "Is an adult" : "Is a kid");

    int hours = 11;
    int minutes = 3;
    char *meridiem = (hours >= 12) ? "PM" : "AM";
    printf("%02d:%02d %s\n", hours, minutes, meridiem);

    return 0;
}
