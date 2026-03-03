#include <stdio.h>
/*
 -Gives an existing datatype a "nickname"
 -typedef existing_type new_name;
 */

typedef int Number;
typedef char String[50];
typedef char Initials[3];

int main() {

    Number x = 3;
    Number y = 4;
    Number z = x + y;

    printf("%d\n", z);

    char name[] = "John Doe";
   // name[9] = 'g'; stack smashing detected means using too much data than it's
   // allocated
    printf("%s\n", name);

    String name_2 = "John Doe Doe";
    printf("%s\n", name_2);

    Initials user1 = "SD";
    printf("%s\n", user1);

    return 0;
}
