#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Prompt for change owed.
    float c;
    do
    {
        c = get_float("Change owed: ");
    }
    while (c < 0);

    //Take change owed and convert to cents.
    int cents = round(c * 100);
    int coins = 0;

    //When cents are more that 25, subtract 25 cents then increase coin count by 1.
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }

    //Print final coin amount.
    printf("%i\n", coins);
}