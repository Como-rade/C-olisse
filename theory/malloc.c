#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 -malloc = memory allocation
 -in the HEAP (not the stack) where we allocate memory
 -malloc(number of bytes)
 */

int main(){
    
    //char grades[5] = {0};
    char num_string[1024] = {0};
    int num_grades = 0;

    printf("Enter the number of grades: ");
    fgets(num_string, sizeof(num_string), stdin);
    num_string[strlen(num_string)] = '\0';
    sscanf(num_string, "%d", &num_grades);
    printf("%d\n", num_grades);

    //to calculate the number of bytes we need we want SIZE * sizeof(datatype)
    char *grades = malloc (num_grades * sizeof(char));
   
    if(grades == NULL){
        printf("Memory allocation failed\n");
        return 1;
        // null pointer can cause a segmentation fault
    }
    
    for(int i = 0; i < num_grades; i++){
        printf("Enter grade #%d: ", i+1);
       
        memset(num_string, 0, sizeof(num_string));//clear char[]
        fgets(num_string, sizeof(num_string), stdin);
        num_string[strlen(num_string)] = '\0';
        sscanf(num_string, "%c", &grades[i]);
    }

    for(int i = 0; i < num_grades; i++){
        printf("%c\n", grades[i]);
    }

    free(grades); //VERY IMPORTANT to free the memory allocated
    grades = NULL; /*VERY IMPORTANT otherwise it will be a dangling pointer
                    which can be exploited(?) 
                   */
    return 0;
}
