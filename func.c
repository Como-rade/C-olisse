#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void hbd(char name[], long int age){ //parameters
    printf("Happy birthday to you!\n"
            "Happy birthday dear %s\n"
            "You're %ld years old\n", name, age);
}

int main() {
    char name[50];
    char age_s[8];
    long int age = 0;
    char *endptr;


    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';

    printf("Enter your age: ");
    fgets(age_s, sizeof(age_s), stdin);
    age_s[strlen(age_s)-1] = '\0';
    
    age = strtol(age_s, &endptr, 10);

    hbd(name, age); //arguments
}
