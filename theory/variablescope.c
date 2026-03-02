#include <stdio.h>


/*
anything within different scope {} can share the same name
 */

//int result = 0; is withing a global scope and hard to debug

int add(int x, int y){
    int result = x + y;
    return result;
}

int substract(int x, int y){
    int result = x - y;
    return result;
}

int main () {
    int x = 5;
    int y = 6;

    int result = add(3, 4);

    result = substract(x, y);


    printf("%d\n", result);
    return 0;

}
