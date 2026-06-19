#include <stdio.h>

/*
Performs integer division without using / or *
i.e. calculates a/b

*/
int integer_division(int a, int b)
{
    int count = 0;
    int current = 0;

    if (a < 0){
        a *= -1;
    }

    if (b < 0){
        b *= -1;
    }

    if (b == 0 ){
        return 0;
    }

    while (current <= a){
        current += b;
        count++;
    }
    
    if (current > a) {
        count--;
    }
    return count;

}

int main(void)
{
    printf("Testing integer_division(a, b):\n\n");

    // Basic cases
    printf("10 / 2 = %d (expected 5)\n", integer_division(10, 2));
    printf("9 / 3 = %d (expected 3)\n", integer_division(9, 3));

    // Truncation cases
    printf("10 / 3 = %d (expected 3)\n", integer_division(10, 3));
    printf("7 / 4 = %d (expected 1)\n", integer_division(7, 4));

    // Division by zero
    printf("10 / 0 = %d (expected 0)\n", integer_division(10, 0));

    // Negative values
    printf("-10 / 2 = %d (expected 5)\n", integer_division(-10, 2));
    printf("10 / -2 = %d (expected 5)\n", integer_division(10, -2));
    printf("-10 / -2 = %d (expected 5)\n", integer_division(-10, -2));

    // Larger values
    printf("100 / 7 = %d (expected 14)\n", integer_division(100, 7));
    printf("12345 / 123 = %d (expected 100)\n", integer_division(12345, 123));

    return 0;
}