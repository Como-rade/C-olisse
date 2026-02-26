#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

    int age = 0;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 18){
        printf("You are an adult\n");
    } else if(age == 0){
        printf("You're not born yet\n");
    }else{
        printf("You re a child\n");
    }
    getchar();

    bool is_student = true;

    if(is_student){
        printf("You're a student\n");
    }else{
        printf("You're not a student\n");
    }

    char name[50] = "";

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';

    if(strlen(name) == 0){
        printf("You did not enter your name\n");
    }else{
        printf("Hello %s\n", name);
    }

}
