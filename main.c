#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *password = "password";
    char admin_input[50];
    int votes_for_a = 0;
    int votes_for_b = 0;
    int votes_for_c = 0;
    char vote;

    printf("Enter administrator password: ");
    scanf("%49s", admin_input);

    if (strcmp(admin_input, password) == 0) {
        printf("Welcome administrator! Voting has started.\n");

        while (1) {
            printf("Representatives: a, b, c\n");
            printf("Kindly enter the representative you want to vote for (q to quit): ");
            scanf(" %c", &vote);

            if (vote == 'a') {
                votes_for_a++;
            } else if (vote == 'b') {
                votes_for_b++;
            } else if (vote == 'c') {
                votes_for_c++;
            } else if (vote == 'q') {
                printf("Enter admin password to end voting: ");
                scanf("%49s", admin_input);
                if (strcmp(admin_input, password) == 0) {
                    printf("Voting has ended.\n");
                    printf("The total votes for a is: %d\n", votes_for_a);
                    printf("The total votes for b is: %d\n", votes_for_b);
                    printf("The total votes for c is: %d\n", votes_for_c);

                    printf("The representative with the most votes is: ");
                    if (votes_for_a > votes_for_b && votes_for_a > votes_for_c) {
                        printf("a\n");
                    } else if (votes_for_b > votes_for_a && votes_for_b > votes_for_c) {
                        printf("b\n");
                    } else if (votes_for_c > votes_for_a && votes_for_c > votes_for_b) {
                        printf("c\n");
                    } else {
                        printf("\nThere is a tie between the representatives. Revoting needed.\n");
                    }
                    break;
                } else {
                    printf("Incorrect password. Voting continues.\n");
                }
            } else {
                printf("Invalid representative. Please try again.\n");
            }
        }
    } else {
        printf("Incorrect password.\n");
    }

    return 0;
}
