#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//define BLOCKSIZE to 512
#define BLOCKSIZE 512

//function for error
int input_error()
{
    printf("Usage: ./recover filename\n");
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return input_error();
    }

    //filename
    char *card_raw = argv[1];

    //opening card_raw file using pointer
    FILE *input_ptr = fopen(card_raw, "r");
    if (input_ptr == NULL)
    {
        printf("Unable to open file: %s\n", card_raw);
        return 1;
    }


    char filename[8];           //array to save filename
    FILE *output_ptr = NULL;    //initializing output pointer for file written-to
    uint8_t buffer[BLOCKSIZE];  //initializing buffer size
    int jpeg_counter = 0;       //jpeg counter

    //reading file into buffer, while it's not at end of file
    while (fread(buffer, sizeof(uint8_t), BLOCKSIZE, input_ptr) || feof(input_ptr) == 0)
    {
        // if beginning of jpeg found...
        if (buffer[0] == 0xff
            && buffer[1] == 0xd8
            && buffer[2] == 0xff
            && (buffer[3] & 0xf0) == 0xe0)
        {
            // and if an output pointer is already open, close it
            if (output_ptr != NULL)
            {
                fclose(output_ptr);
            }
            //name new outfile
            sprintf(filename, "%03i.jpg", jpeg_counter);

            //open new file and increase jpeg_counter by 1
            output_ptr = fopen(filename, "w");
            jpeg_counter++;
        }
        // if output pointer is already open continue to write to file
        if (output_ptr != NULL)
        {
            fwrite(&buffer, sizeof(buffer), 1, output_ptr);
        }
    }
    //close files if open
    if (input_ptr == NULL)
    {
        fclose(input_ptr);
    }
    if (output_ptr == NULL)
    {
        fclose(output_ptr);
    }

    return 0;
}
