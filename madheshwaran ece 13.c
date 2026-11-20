#include <stdio.h>

// Function for addition
int add(int a, int b)
{
    return a + b;
}

// Function for subtraction
int subtract(int a, int b)
{
    return a - b;
}

// Function for multiplication
int multiply(int a, int b)
{
    return a * b;
}

// Function for division
float divide(int a, int b)
{
    return (float)a / b;
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\nAddition = %d", add(a, b));
    printf("\nSubtraction = %d", subtract(a, b));
    printf("\nMultiplication = %d", multiply(a, b));

    if (b != 0)
        printf("\nDivision = %.2f", divide(a, b));
    else
        printf("\nDivision is not possible");

    return 0;
}




