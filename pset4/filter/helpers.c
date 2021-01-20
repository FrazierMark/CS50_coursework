#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through the 2D array
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //find RGB values and save them in variables
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            //avg the RGB values
            float avg_rgb = (round(red) + round(green) + round(blue)) / 3;
            int rgb = round(avg_rgb);

            //set avg RGB to original RGB varibales
            image[i][j].rgbtRed = rgb;
            image[i][j].rgbtGreen = rgb;
            image[i][j].rgbtBlue = rgb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through the 2D array
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //find RGB values and save them in variables
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            //calculate sepia color value using given algorithm
            float sepiaRed_f = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen_f = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue_f = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            int sepiaRed = round(sepiaRed_f);
            int sepiaGreen = round(sepiaGreen_f);
            int sepiaBlue = round(sepiaBlue_f);

            //limit value to 255 if it goes over
            if (sepiaRed > 255)

            {
                (sepiaRed = 255);
            }

            if (sepiaGreen > 255)

            {
                (sepiaGreen = 255);
            }

            if (sepiaBlue > 255)

            {
                (sepiaBlue = 255);
            }

            //set avg RGB to original RGB varibales
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}


void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through the 2D array
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            //swap pixels using swap function above (using pointer)
            swap(&image[i][j], &image[i][width - j - 1]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];

    //iterate through 2D array, (pixel by pixel)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //create variables to later calculate avg rgb values
            int sum_blue = 0;
            int sum_red = 0;
            int sum_green = 0;

            int counter = 0;

            //look to pixel before and after current pixel
            for (int k = -1; k < 2; k++)
            {
                //look to pixel above and below current pixel (in relation to iteration above)
                for (int h = -1; h < 2; h++)
                {
                    //stops program from looking outside the bounds of the photo
                    //each 'or' covers a 'side' of the photo (and in a way acts as a wall)
                    if (i + k < 0 || i + k > height -  1 || j + h < 0 || j + h > width - 1)

                    {
                        continue;
                    }

                    //find rgb values of surrrounding pixels and add them to a variable
                    sum_blue += image[i + k][j + h].rgbtBlue;
                    sum_red += image[i + k][j + h].rgbtRed;
                    sum_green += image[i + k][j + h].rgbtGreen;

                    //everytime a surrounding pixel is found and rgb values found, increase the counter
                    counter++;
                }
            }

            //find avg of all surrounding rgb values of a particular pixel and save in a temporary image copy
            image_copy[i][j].rgbtBlue = round((float)sum_blue / counter);
            image_copy[i][j].rgbtRed = round((float)sum_red / counter);
            image_copy[i][j].rgbtGreen = round((float)sum_green / counter);
        }
    }

//iterate through 2D array once more and save the new rgb values to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = image_copy[i][j].rgbtBlue;
            image[i][j].rgbtRed = image_copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = image_copy[i][j].rgbtGreen;
        }
    }
    return;
}
