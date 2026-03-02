#include <stdio.h>

int main() {
    
    int numbers[][3] = {{1, 2, 3}, 
                        {4, 5, 6}, 
                        {7, 8, 9}};

    printf("%d\n", numbers[1][2]); //first [] is row second is column
    

    return 0;

}
