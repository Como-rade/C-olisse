// Comment single line
/* Multi-line
   comments */

// Introduction to the different basic data-types"

/*
-int size: 4 bytes, stores whole number without decimals
-float size : 4 bytes, enough to store 6  decimal digits
-double size : 8 bytes, enough to store 15 decimal digits
-char size : 1 byte, enough to store single character/letter/
number or ASCII character
 */
#include<stdio.h>
#include<stdbool.h>

int main () {

    int x = 50;
    printf("x is equal to %d\n", x);

    float y = 10.4;
    // concatenate on multiple lies
    printf("x is equal to %d\n" 
            "and y is equal to %f\n", x,y);
    // truncating
    int f = 50.5;
    printf("f will be truncated; %d\n", f);

    //set precision
    // default behavior of C is to display 6 decimal digits
    float z = 3.4878745;
    printf("only display 2 digits after "
            "the decimal %.2f\n", z);

    //float vs double
    
    float g = 4.500001;
    double u = 4.500000000000001;
    printf("float should be around 6 decimal digits: %.6f\n"
            "double should be around 15: %.15lf\n", g, u);

    //char char char
    char v = 'B';

    printf("B is %c\n", v);

    //String which is actually just an array of char
    char s[] = "This is a string\n";

    printf("%s", s);
    /*
    s = "This is a new string\n";
    can't do that because it's a constant reference to a fixed
     block of memory*/
    
    // 0 = false, 1 = true
    // needs <stdbool.h>
    bool num0 = 0;
    bool num1 = 1;

    bool tr = true;
    bool fl = false;

    printf("num0 & true: %d ; %d\n"
            "num1 & false: %d ; %d\n", num0, tr, num1, fl);

    /*
     do not mix bool 0 & 1 value and exit code
     exit code 0 = it was a safe exit (no error)
     where as bool 0 = false
     */
    return 0;

}

