#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int long rand_num(int min, int max);
bool check_guessed_num(int long num_chosen, int long num_guess);
int long guessed_num(int min, int max);

int main(){

    int min = 1;
    int max = 100;
    int long num_to_guess = rand_num(min, max);
    int long num_chosen;
    
    printf("*** NUMBER GUESSING GAME ***\n");
    printf("NUM IS %ld: \n", num_to_guess);

    do{
        printf("Guess a number between %d - %d: ", min, max);
        num_chosen = guessed_num(min, max);

        if(num_chosen < num_to_guess){
            printf("TOO LOW!\n");
        }else if(num_chosen > num_to_guess){
            printf("TOO HIGH\n");
        }
        
    }while(!check_guessed_num(num_chosen, num_to_guess));

    printf("Congratulations! %ld is the right answer!\n", num_chosen);

}

int long rand_num(int min, int max){
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

bool check_guessed_num(int long num_chosen, int long num_guess){
    return num_chosen == num_guess;
}

int long guessed_num(int min, int max){
    char num[255];
    char *ptdr;
    long int num_is;

    do{
    fgets(num, sizeof(num), stdin);
    num[strlen(num)-1] = '\0';
    num_is = strtol(num, &ptdr, 10);
    
    if(*ptdr != '\0' || num_is > 100 || num_is < 1){
        printf("Enter a valid value between %d - %d: ", min, max);
    }

    }while(*ptdr != '\0' || num_is > 100 || num_is < 1);

    return num_is;

}
