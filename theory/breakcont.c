#include <stdio.h>

/*
- Break will break out of a loop
- continue will skip current cycle of the loop
 */
int main(){
    
    for(int i = 1; i <= 10; i++){
        if(i == 4){
            break; //get out of the for loop ENTIRELY if i == 4
        }

        printf("%d\n", i);

    }

    for(int i = 1; i <= 10; i++){
        if(i == 4){
            continue; /*will skip the current loop cycle and go to the next
                      it will not execute whatever codes that is after
                      in this case it wont printf 4*/
        }
        printf("%d\n", i);
    } 
    

}
