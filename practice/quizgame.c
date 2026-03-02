#include <stdio.h>
#include <string.h>

int main(){

    char options[][255] = {"A. Jupiter\nB. Saturn\nC. Uranus\nD. Neptune\n", 
        "A. Mercury\nB. Venus\nC. Earth\nD. Mars\n", 
        "A. Earth\nB. Mars\nC. Jupiter\nD. Saturn\n", 
        "A. Yes\nB. No\nC. Maybe\nD. Sometimes\n"};

    char questions[][255] = {"What is the largest planet in the solar system?\n"
    ,"What is the hottest planet?\n",
    "What planet has the most moons?\n",
    "Is the Earth flat?\n"};
    
    char answer_key[4] = {'A', 'B', 'D', 'B'};
    int array_size = sizeof(questions)/sizeof(questions[0]);
    char key_stroke[4];
    int points = 0;

    for(int i = 0; i < array_size; i++){
        printf("%s\n%s\n", questions[i], options[i]);
        printf("Enter your answer (A B C D): ");
        fgets(key_stroke, sizeof(key_stroke), stdin);
        key_stroke[strlen(key_stroke)-1] = '\0';

        if(answer_key[i] == key_stroke[0]){
            printf("CORRECT!\n\n");
            points++;
        }else{
            printf("INCORRECT!\n\n");
        }
    }

    printf("Your score is %d points!\n", points);

    return 0;
}
