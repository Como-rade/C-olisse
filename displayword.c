#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char words[100];
    printf("Write something will less than a 99 characters: ");
    fgets(words, sizeof(words), stdin);
    words[strlen(words)-1] = '\0';
    char c = words[0]; 
    for(int i = 1 ; c != '\0'; i++){
        printf("%c" , c);
        c = words[i];
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
    return 0;
}
