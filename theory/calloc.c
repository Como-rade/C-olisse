#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 -calloc = contiguous allocation
 -allocates memory dynamically and sets all allocated bytes to 0
 -malloc is faster but calloc leads to less bug
 -calloc(# of element, size)
 */

int main(){

    int number = 0;
    char num_string[1024] = {0};

    printf("Enter the number of grades: ");
    fgets(num_string, sizeof(num_string), stdin);
    num_string[strlen(num_string)] = '\0';
    sscanf(num_string, "%d", &number);

    int *scores = malloc(number * sizeof(int));
    
    if(scores == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i = 0; i < number; i++){
        printf("%d\n", scores[i]); //mostly be garbage value so unsafe

    }

    free(scores);
    scores = NULL;
    number = 0;
    memset(num_string, 0, sizeof(num_string));

    printf("Enter the number of grades: ");
    fgets(num_string, sizeof(num_string), stdin);
    num_string[strlen(num_string)] = '\0';
    sscanf(num_string, "%d", &number);

    scores = calloc(number, sizeof(int));

    if(scores == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i = 0; i < number; i++){
         printf("%d\n", scores[i]); //initialize everything to 0 so safer
    }

    for(int i = 0; i < number; i++){
        printf("Enter grade #%d: ", i+1);

        memset(num_string, 0, sizeof(num_string));
        fgets(num_string, sizeof(num_string), stdin);
        num_string[strlen(num_string)] = '\0';
        sscanf(num_string, "%d", &scores[i]);
    }

    for(int i; i < number; i++){
        printf("%d\n", scores[i]);
    }

    //very good practice to set everything to null/0
    free(scores);
    scores = NULL;
    number = 0;
    memset(num_string, 0, sizeof(num_string));

    return 0;
}
