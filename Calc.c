#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not possible!\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}

int main() {
    double num1, num2;
    int choice;

    while (1) {
        showMenu();
        printf("Enter operation number: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);

        switch (choice) {
            case 1:
                printf("Result: %.2f\n", add(num1, num2));
                break;
            case 2:
                printf("Result: %.2f\n", subtract(num1, num2));
                break;
            case 3:
                printf("Result: %.2f\n", multiply(num1, num2));
                break;
            case 4:
                printf("Result: %.2f\n", divide(num1, num2));
                break;
        }

        printf("\n");
    }

    return 0;
}
