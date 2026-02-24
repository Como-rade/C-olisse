#include <stdio.h>
#include <string.h>

int main() {

    char adj[100];
    char noun[100];
    char adj_2[100];
    char verb[100];
    char adj_3[100];

    printf("Enter an adjective (description): ");
    fgets(adj, sizeof(adj), stdin);
    adj[strlen(adj)-1] = '\0';

    printf("Enter a noun (animal or person): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun)-1] = '\0';

    printf("Enter an adjective (description): ");
    fgets(adj_2, sizeof(adj_2), stdin);
    adj_2[strlen(adj_2)-1] = '\0';

    printf("Enter a verb (ending w/ -ing): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strlen(verb)-1] = '\0';

    printf("Enter an adjective (description): ");
    fgets(adj_3, sizeof(adj_3), stdin);
    adj_3[strlen(adj_3)-1] = '\0';

    printf("\nToday I went to a %s zoo.\n"
            "In an exhibit, I saw a %s.\n"
            "%s was %s and %s\n"
            "I was %s!\n", adj, noun, noun, adj_2, verb, adj_3);

    return 0;
}
