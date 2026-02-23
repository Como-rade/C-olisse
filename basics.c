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

    /*
    FORMAT SPECIFIERS & OPTIONAL MODIFIERS
     */
    int age = 25;
    float price = 19.99;
    double pi = 3.141592;
    char currency = '$';
    char name[] = "Suh dud";

    printf("%d\n", age);
    printf("%f\n", price);
    printf("%lf\n", pi);
    printf("%c\n", currency);
    printf("%s\n", name);

    //Optional modifiers: WIDTH
    int num01 = 1;
    int num011 = -1;
    double num2 = 10;
    printf("%4d\n", num01); //empty space BEFORE starting to print
                            //number of caracter counts in the WIDTH
    printf("%10lf\n", num2);

    printf("%-4d\n", num01); //empty space AFTER the variable is printed 

    printf("%04d\n", num01); //0 will appear instead of empty spaces
   
    printf("%+d\n or %+d\n",num01, num011); //display sign
    
    //Optional modifiers: precision

     float price01 = 19.99;
     float price02 = -1.50;

     printf("%f\n", price01); //standard behavior will display 6 digits after

     printf("%.2f\n", price01); //amount of digits to display
     
     printf("%.1f\n", price01); //will round up

     //Mix both optional modifiers

     printf("%7.1f\n", price01);
     printf("%+5.2f\n", price01);
     printf("%+10.1f\n", price02);

     
    return 0;

}

