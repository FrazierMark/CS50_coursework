#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
//calculate length of string
#include <string.h>

int main(void)
{

    //Prompt user for text using get_string
    string text = get_string("Text: ");

    int num_letters, num_words, num_sentences;
    num_letters = 0;
    num_words = 0;
    num_sentences = 0;

    //move through string
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        //if letter is part of alphabet, increase the letter counter
        if (isalpha(text[i]))
        {
            num_letters++;
        }

        //starting with first element and if it is not a space, increase word counter,
        if ((i == 0 && text[i] != ' ')
            || (i != length - 1 && text[i] == ' ' && text[i + 1] != ' '))
        {
            num_words++;
        }
        //if any of the following appear: ". ? !" in the text, increase the sentence counter
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            num_sentences++;
        }
    }

    //calculate L and S to use in Colemane-Liau index
    float L = (num_letters / (float) num_words) * 100;
    float S = (num_sentences / (float) num_words) * 100;

    //compute the Coleman-Liau index
    //need to round, cause integer (grade level)
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
