#include <stdio.h>
/*
 -A pointer is a variable that stores the MEMORY ADDRESS of another variable
 */

void birthday(int age);
void birthday_ref(int *age);

int main() {

    int age = 24;

    printf("%p\n", &age); //%p to output the address, &VAR "address of" operator

    int *p_age = &age; //* dereference operator(to create a pointer) 

    printf("%p\n%p\n", &age, p_age); //since p_age is already a pointer, & is not
                                    //needed

    birthday(age);
    printf("age is %d\n", age); //no changes

    /*p_age++;
    printf("pointer is %p\n", p_age);*/

    birthday_ref(p_age);
    //birthday_ref(&age); works too
    printf("age is %d\n"
            "p_age age is %d\n", age, *p_age);

    return 0;

}

void birthday(int age){
    /*
    pass by value which means a copy is made so age in main is not changed
    if we want to change the var we need to pass it by reference
     */
    age++;
}

void birthday_ref(int *age){
    /*age++; this will cause the address to increment
      this will cause the pointer age to point somewhere else temporarly(?)
      printf("pointer %p\n", age); */
    (*age)++; /*we need to dereference then increment
                *age++ doesn't work because of operator precedence in C
                which means we would (in this case) increment the memory
                address by one (age++) then dereference
               */
}
