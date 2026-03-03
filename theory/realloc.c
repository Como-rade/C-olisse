#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 -Reallocation
 -Resize previously allocated memory (expand or shrink)
 -realloc(ptr, bytes);
 */

int main() {

    int number = 0;
    int new_number = 0;
    char num_string[1024] = {0};

    printf("Enter the number of prices: ");
    fgets(num_string, sizeof(num_string), stdin);
    num_string[strlen(num_string)] = '\0';
    sscanf(num_string, "%d", &number);

    float *prices = calloc(number, sizeof(int));

    if(prices == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("memory calloc: %p\n", prices);

    for(int i = 0; i < number; i++){
        printf("Enter price #%d: ", i+1);

        memset(num_string, 0, sizeof(num_string));
        fgets(num_string, sizeof(num_string), stdin);
        num_string[strlen(num_string)] = '\0';
        sscanf(num_string, "%f", &prices[i]);
    }

    printf("Enter a new number of prices that will be added: ");

    memset(num_string, 0, sizeof(num_string));
    fgets(num_string, sizeof(num_string), stdin);
    num_string[strlen(num_string)] = '\0';
    sscanf(num_string, "%d", &new_number);

    float *temp = realloc(prices, new_number*sizeof(float));
    /*
     If there's enough space immediately following the original block,
     realloc will point to the same pointer where the memory is allocated and
     add the blocks.
     Otherwise, if there isn't enough space, it will do a copy to a new 
     block of memory and point to that
     In the case of the a new space, it's important to free and null everything

     */

    printf("memory realloc %p\n", temp);

    if(temp == NULL){
        printf("Could not reallocate memory\n");
    }else{
        prices = temp;
        temp = NULL;
        for(int i = number; i < new_number; i++){
            printf("Enter price #%d: ", i+1);

            memset(num_string, 0, sizeof(num_string));
            fgets(num_string, sizeof(num_string), stdin);
            num_string[strlen(num_string)] = '\0';
            sscanf(num_string, "%f", &prices[i]);
        }
    }
    

    for(int i = 0; i < new_number; i++){
        printf("$%.2f\n", prices[i]);
    }

    free(prices);
    prices = NULL;
    memset(num_string, 0, sizeof(num_string));

    return 0;
}
