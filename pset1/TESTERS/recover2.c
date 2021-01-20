
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<cs50.h>

int main(int argc, char *argv[])
{
    int buffer[512];

    if (argc !=2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }
    return 0;

    //filename
    char * card_raw = argv[1];

    //Defining file pointer AND opening card_raw file
    FILE* fpter = fopen("card_raw", "r");
    if (fpter == NULL)
    {
        printf("An error occurred while opening the file.\n");
        exit (1);
    }

    int jpeg_counter = 0;
    char pic[8];
    FILE* output_ptr;


        {

            if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (jpeg_counter > 0)
                {
                    //close already opened file
                    fclose(output_ptr);

                    //name new outfile and storing in array called pic
                    sprintf(pic, "%03i.jpg", jpeg_counter);

                    //open new file for writing
                    output_ptr = fopen(pic, "w");

                    //write to new file
                    fwrite(buffer, sizeof(int), 512, output_ptr);
                    jpeg_counter += 1;
                }

                if (jpeg_counter == 0)
                {
                    //name new outfile
                    sprintf(pic, "%03i.jpg", jpeg_counter);
                    jpeg_counter += 1;

                    //open new file
                    output_ptr = fopen(pic, "w");

                    //write to opened file
                    fwrite(buffer, sizeof(int), 512, output_ptr);
                }



            }

            else if (jpeg_counter > 0)
            {
                fwrite(buffer, sizeof(int), 512, output_ptr);
            }

        }

        fclose(output_ptr);
        fclose(fpter);
        return 0;
}
