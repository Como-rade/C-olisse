#include <stdio.h>

int main() {

    char fruits[][10] = {"Apple", "Banana", "Coconut"}; //not contiguous in mem
    //unlike an int[][] or other(?)

    int size = sizeof(fruits) / sizeof(fruits[0]);

    for(int i = 0; i < size; i++){
        printf("%s\n", fruits[i]);
    }

    return 0;
}
