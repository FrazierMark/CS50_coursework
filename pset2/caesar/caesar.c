#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool validate_key(string s);


int main(int argc, string argv[])
{
    //check for vaild input
    if (argc != 2 || !validate_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //atoi function converts string to integer or characters to numbers
    int key = atoi(argv[1]);

    string plain_text = get_string("plaintext: ");

    //iterates through the plaintext, applies Caesar's algorithm, and prints the ciphertext
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plain_text); i < len; i++) //strlen function figures length of plain_text
    {
        char c = plain_text[i];
        if (isalpha(c)) //if letter, continue to apply algorithm
        {
            char m = 'A';
            if (islower(c))
                m = 'a';
            printf("%c", (c - m + key) % 26 + m);
        }
        else
        {
            printf("%c", c); //else, if not a letter, just print it
        }
    }
    printf("\n");
}

// function created to validate if given key is a digit.
bool validate_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
        if (!isdigit(s[i]))

            return false;

            return true;
}
