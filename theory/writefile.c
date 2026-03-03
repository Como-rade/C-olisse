#include <stdio.h>

int main() {
    /*
    -if file doesnt exist, it will create it
    -using relative path (output.txt, where we are right now), can use absolute
    path (/home/key/C-olisse/output.txt)
    */
    FILE *p_file = fopen("output.txt", "w");
    
    char text[] = "Test Test\nROCKNROLL\n";

    if(p_file == NULL){ //couldnt open the file
        printf("Error opening a file\n");
        return 1; // 0 = success; 1 = failure
    }

    int written = fprintf(p_file,"%s", text ); //to write in file
    if(written >= 0){
        printf("File was written successfully\n");
    }else{
        printf("Error has occured while writing in the file.\n");
    }

    fclose(p_file);

    return 0;

}
