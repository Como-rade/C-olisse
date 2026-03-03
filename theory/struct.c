#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*
 -Struct are kinda like object in other programming language
 -Use of typedef is possible (no need struct keyword when declaring)
 */

struct Student{
    char name[50];
    int age;
    float gpa;
    bool is_fulltime;
};

typedef struct{
    char model[50];
    int year;
}Car;

void print_student(struct Student student);


int main() {

    struct Student student1 = {"John Doe", 30, 4, true};
   // printf("%s, %s\n", student1.name, (student1.is_fulltime) ? "He is full time" 
            //: "He is part time" );
    print_student(student1);
    
    struct Student student2; /*
    when declaring a struct, it gives it some block of memories
    it is possible to printf but will give some garbage data
    (leftover data from another program)
                              */
    printf("%s, %d\n", student2.name, student2.age);

    struct Student student3 = {0}; //will set everything to 0 or it's equivalent
    printf("%s, %d\n", student3.name, student3.age);
    strncpy(student3.name, "John Daoe", sizeof(student3.name));
    student3.name[strlen(student3.name)-1] = '\0';
    printf("his name is %s\nLength: %ld\n", student3.name, 
            strlen(student3.name));

    struct Student student4 = {0};
    printf("%s, %d\n", student4.name, student4.age);
    strncpy(student4.name, "John Goe", sizeof(student4.name));
    student4.name[strlen(student4.name)] = '\0';
    printf("name is %s\n", student4.name);

    Car car1 = {"X5", 1990};
    printf("%d\n", car1.year);

    return 0;
}

void print_student(struct Student student){
    printf("%s\n"
            "%d\n"
            "%.2lf\n"
            "%s\n", student.name, student.age, student.gpa,
             (student.is_fulltime) ? "He is full time": "He is part time");
}
