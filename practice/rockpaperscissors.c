#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int long cpu();
int long user_input();
char *hand_chosen(int long option);
void is_winner(int long user, int long cpu);

int main(){

    int long cpu_choice = cpu();
    int long user_choice;
    char *user_string;
    char *cpu_string = hand_chosen(cpu_choice);

    printf("*** ROCK PAPER SCISSORS ***\n");
    
    printf("Choose an option\n"
            "1. ROCK\n"
            "2. PAPER\n"
            "3. SCISSORS\n"
            "Enter your chhoice: ");
    user_choice = user_input();
    user_string = hand_chosen(user_choice);

    //printf("USER: %s\nCPU: %s\n", user_string, cpu_string);

    printf("CPU choice: %s\nYour choice: %s\n", cpu_string, user_string);
    if(cpu_choice == user_choice){
        printf("It's a draw!\n");
    }else{
        is_winner(user_choice, cpu_choice);
    }

    return 0;

}

int long cpu(){
    srand(time(NULL));
    return ((rand() % 3) + 1);
}

int long user_input(){
    char input[255];
    char *ptdr;
    int long choice;
    
    do{
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0';
    choice = strtol(input, &ptdr, 10);
    
    if(*ptdr != '\0' || choice < 1 || choice > 3){
        printf("Enter a valid choice: ");
    }

    }while(*ptdr != '\0' || choice < 1 || choice > 3);

    return choice;
}

char *hand_chosen(int long option){

    switch(option){
        case 1: return "ROCK";
                break;
        case 2: return "PAPER";
                break;
        case 3: return "SCISSORS";
                break;
    }
    return NULL;
}

void is_winner(int long user, int long cpu){
    
    switch(user){
        case 1: if(cpu == 2){
                    printf("You lost!\n");
                }else{
                    printf("You won!\n");
                }
                break;
        case 2: if(cpu == 1){
                    printf("You won!\n");
                }else{
                    printf("You lost!\n");
                }
                break;
        case 3: if(cpu == 1){
                    printf("You lost!\n");
                }else{
                    printf("You won!\n");
                }
                break;
    }

}
