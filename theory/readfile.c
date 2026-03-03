#include <stdio.h>

int main(){
    
    FILE *p_file = fopen("output.txt", "r");
    char buffer[1024] = {0}; //1024bytes = 1kilobyte; it will hold data

    if(p_file == NULL){
        printf("Could not open file\n");
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), p_file) != NULL){
        printf("%s", buffer);
    }

    fclose(p_file);

    return 0;
}
