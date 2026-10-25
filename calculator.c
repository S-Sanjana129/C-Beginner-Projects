#include <stdio.h>
#include <stdlib.h>

// Function declarations (Prototypes)
void showMenu();
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
void divide(float a, float b); // Void because we need to check for division by zero

int main() {
    int choice;
    float num1, num2;

    while(1) {
        showMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Exit condition
        if (choice == 5) {
            printf("\nThank you for using the C Calculator! Goodbye.\n");
            break;
        }

        // Validation for wrong inputs
        if (choice < 1 || choice > 5) {
            printf("\n❌ Invalid choice! Please select between 1 and 5.\n");
            continue;
        }

        // Taking inputs for calculations
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);

        // Switch case to process operations
        switch(choice) {
            case 1:
                printf("\n✅ Result: %.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("\n✅ Result: %.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                printf("\n✅ Result: %.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                divide(num1, num2);
                break;
        }
    }
    return 0;
}

// Function Definitions
void showMenu() {
    printf("\n=============================\n");
    printf("      TEXT-BASED CALCULATOR  \n");
    printf("=============================\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
    printf("-----------------------------\n");
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

void divide(float a, float b) {
    if (b == 0) {
        printf("\n❌ Error: Division by zero is not allowed!\n");
    } else {
        printf("\n✅ Result: %.2f / %.2f = %.2f\n", a, b, a / b);
    }
}
