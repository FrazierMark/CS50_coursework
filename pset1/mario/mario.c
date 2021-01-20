#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for input
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //each row
    for (int i = 0; i < n; i++)
    {
        //print front spaces
        for (int s = 0; s < n - 1 -i; s++)
        {
            printf(" ");
        }
        // print front #
        for (int h = n - 1 -i; h < n; h++)
        {
            printf("#");
        }
        //print 2 spaces
        printf("  ");

        //print end #
        for (int h = n - 1 -i; h < n; h++)
        {
            printf("#");
        }
        //new line
        printf("\n");
    }
}