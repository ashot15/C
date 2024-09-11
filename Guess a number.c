#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int number, guess, attempts, max_attempts, min_range, max_range;
    char play_again;
    int wins = 0, losses = 0;
    int difficulty; // Declaration of the difficulty variable

    srand(time(0)); // Initialize random number generator

    do {
        printf("Choose a number range:\n");
        printf("Enter minimum value: ");
        scanf("%d", &min_range);
        printf("Enter maximum value: ");
        scanf("%d", &max_range);

        printf("Choose difficulty level:\n");
        printf("1. Easy (10 attempts)\n");
        printf("2. Medium (7 attempts)\n");
        printf("3. Hard (5 attempts)\n");
        printf("Enter level number: ");
        scanf("%d", &difficulty);

        switch (difficulty) {
            case 1:
                max_attempts = 10;
                break;
            case 2:
                max_attempts = 7;
                break;
            case 3:
                max_attempts = 5;
                break;
            default:
                printf("Invalid choice. Game over.\n");
                continue;
        }

        number = rand() % (max_range - min_range + 1) + min_range; // Random number in the specified range
        printf("I have chosen a number between %d and %d. You have %d attempts to guess it!\n", min_range, max_range, max_attempts);

        attempts = 0;

        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess > number) {
                printf("Too high!\n");
            } else if (guess < number) {
                printf("Too low!\n");
            } else {
                printf("Congratulations! You guessed the number %d in %d attempts.\n", number, attempts);
                wins++;
                break;
            }

            // Hint about proximity
            int difference = abs(number - guess);
            if (difference <= 10) {
                printf("You are very close!\n");
            } else if (difference <= 20) {
                printf("You are close!\n");
            }

            if (attempts >= max_attempts) {
                printf("You have run out of attempts! The number was %d.\n", number);
                losses++;
            }

        } while (attempts < max_attempts);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    // Display statistics
    printf("Statistics:\n");
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);

    return 0;
}
