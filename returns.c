#include <stdio.h>

int square (int num){
    return num * num;
}

int main() {
    
    int x = square(2);
    int y = square(3);

    printf("%d\n"
           "%d\n", x, y);

    return 0;
}
