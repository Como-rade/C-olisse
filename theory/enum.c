#include <stdio.h>

/*
 -Constants should always be upper case
 -By default, first constants = 0, second = 1, ect... (+1 increment)
 -You can give them a value that is a NUMBER, no strings
 -If a value is given to a enum and the next one has no set value, it will be
 value of the enum before + 1
 -Usage of typedef is permited. Therefore, you don't need to use the keyword enum
 when using it in the program
 */
enum Day{
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

enum Weight{
    JOHN_DOE = 100, JOHN_DOA = 200, JOHN_LOE, JOHN_FOE = 300, JOHN_FAE
};

typedef enum{
    SUCCESS, FAILURE, PENDING
}Status;

typedef enum{
    APPLE, MELON
}Fruits; 

void connect_status(Status status);

int main(){
    
    enum Day today = TUESDAY;
    printf("%d\n", today);

    if(today == SUNDAY || today == SATURDAY){
        printf("It's the weekend!\n");
    }else{
        printf("It's a weekday!\n");
    }

    enum Weight guy = JOHN_FAE;
    printf("%d\n", guy);

    Status status = FAILURE;
    connect_status(status);

    Fruits fruit = APPLE;
    printf("%d\n", fruit);

    return 0;

}

void connect_status(Status status){
    switch(status){
        case SUCCESS:
            printf("Connection was successful.\n");
            break;

        case FAILURE:
            printf("Could not connect.\n");
            break;
        case PENDING:
            printf("Connecting...\n");
            break;
    }
}
