#include <stdio.h>
#include <stdbool.h>

/*
Function prototype provides the compiler with useful infor about a function
mainly: name, return type and params before it's actual definition.
Enables type checking and allows functiosn to be used before they're defined
It improves readability, organizations and helps prevent errors
 */

void hello(char name[], int age); //function prototype
bool age_check(int age);

int main(){

    hello("John Doe", 30);
    
    if(age_check(18)){
        printf("You're under 18\n");
    }else{
        printf("You're 18 or over\n");
    }

    return 0;
}

void hello(char name[], int age){
    printf("Hello %s\n"
            "You are %d years old\n", name, age);

}

bool age_check(int age){
   return age < 18; 
}
