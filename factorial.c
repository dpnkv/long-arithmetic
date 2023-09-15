// Long arithmetic factorial calculating

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BASE 10
#define LIMIT 500000

unsigned long long int  factorial(int number);
void long_factorial(int number);

int main(int argc, char **argv)
{
    int number = 0;
    number = atoi(argv[1]);
    printf("Arguments: %d, 2nd argument: %d\n", argc, atoi(argv[1]));

    if (number >= 0 && number <= 20)
    {
        factorial(number);
        printf("%I64u", factorial(number));
    }
    else if (number > 20)
        long_factorial(number);
    else printf("Error!\n");
    return 0;
}

unsigned long long int factorial(int number)
{
    unsigned long long int result = 1;
    for (int i = 1; i <= number; i++)
    {
        result *= i;
    }
    return result;
}

void long_factorial(int number)
{
    char a[LIMIT];
    int b; // next multiplicand
    unsigned long long int factorial_of_20 = factorial(20);
    int amount;
    int i = 0;
    int n = 0;
    while (factorial_of_20 > 0)
    {
        a[i] = factorial_of_20 % BASE;
        factorial_of_20 /= BASE;
        i++;
        n++;
    }
    amount = n;
    int remainder = 0;
    int tmp = 0;
    for (b = 21; b <= number; b++)
    {
        for (int i = 0; i <= (amount-1); i++)
        {
            tmp = a[i] * b + remainder;
            remainder = tmp / BASE;
            a[i] = tmp % BASE;
        }
        while (remainder > 0)
        {
            amount++;
            a[amount-1] = remainder % BASE;
            remainder /= BASE;
        }
    }

    FILE *fptr;
    fptr = fopen("D:\\factorial.txt", "w");
    fprintf(fptr, "Factorial of %d:\n", number);
    for (int i = (amount-1); i >= 0; i--)
        fprintf(fptr, "%d", a[i]);
    fprintf(fptr, "\nDigits in your number: %d", amount);
    fclose(fptr);
}
