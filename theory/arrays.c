#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){

    int numbers[] = {10, 20, 30, 40, 50};
    char grades[] = {'A', 'B', 'C', 'D'};
    char name[] = "John Doe"; //is an array of char

    char *ptdr;
    int long input;
    char input_string[6];
    int long arr_num[5];

    numbers[0] = 100;

    printf("%d\n", numbers[0]);
    printf("%c\n", grades[0]);
    printf("%c\n", name[0]);

    int array_length = sizeof(numbers) / sizeof(numbers[0]); //array size
    // it takes the total byte size of the array divided by byte size
    //of 1 element

    for(int i = 0; i < array_length; i++){
        printf("Element at index %d: %d\n", i, numbers[i]);
    }

    printf("%ld\n",sizeof(arr_num)/sizeof(arr_num[0]));
    array_length = sizeof(arr_num)/sizeof(arr_num[0]);

    printf("sizeof %ld\n", sizeof(input_string));
    for(int i = 0; i < array_length; i++){
        printf("Enter a number: ");
        fgets(input_string, sizeof(input_string), stdin);        
        //printf("string is %s\nlength is %ld\n", input_string,
          //      strlen(input_string));
        
        input_string[strlen(input_string)+1] = '\0';
        clear_input_buffer();
       // printf("input string: %s\n lenght: %ld\n", input_string,
       //         strlen(input_string));
        input = strtol(input_string, &ptdr, 10);
        
       // printf("input %ld\n", input);
        arr_num[i] = input;
        fflush(stdin);
    }

    for(int i = 0; i < array_length; i++){
        printf("Number at index %d: %ld\n", i, arr_num[i]);
    }

    return 0;

}
