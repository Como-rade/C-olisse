#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void takes_s(int count);
void rectangle();

int main(){
    
    //for loop: for(Initialization; Condtion; Update)
    
    for(int i = 0; i < 10; i++){
        printf("Loop number %d\n", i);

    }

    for(int i = 2; i < 10; i+=2){
        printf("By two: i = %d\n", i);
    }

    for(int i = 10; i > 0; i--){
        takes_s(i);
    }

    printf("Happy New Year!\n");

    for(int i = 1; i <= 10; i++){
        printf("%d", i);
    }
    printf("\n");
    for(int i = 2; i <= 10; i++){
        printf("%d\n", i);
    }

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
        printf("%-3d ", i*j);
        }
        printf("\n");
    }

    rectangle();

    return 0;

}

void takes_s(int count){
    
    if(count > 1){
        //sleep(1);
        printf("%d seconds before New Years!\n", count);
    }else{
       // sleep(1);
        printf("%d second before New Years!\n", count);
    }
}

void rectangle(){
    char row_string[4];
    char columns_string[4];
    int long rows;
    int long columns;
    char *ptdr_row;
    char *ptdr_columns;
    char symbol[2];

    printf("Enter the # of rows: ");
    fgets(row_string, sizeof(row_string), stdin);
    row_string[strlen(row_string)-1] = '\0';

    printf("Enter the # of columns: ");
    fgets(columns_string, sizeof(columns_string), stdin);
    columns_string[strlen(columns_string)-1] = '\0';

    printf("Enter a symbol: ");
    fgets(symbol, sizeof(symbol), stdin);
    symbol[1] = '\0';

    rows = strtol(row_string, &ptdr_row, 10);
    columns = strtol(columns_string, &ptdr_row, 10);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%s", symbol);
        }
        printf("\n");

    }

}
