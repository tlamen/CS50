#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //Get old (original) values for rgb
            float oldred = image[j][i].rgbtRed;
            float oldgreen = image[j][i].rgbtGreen;
            float oldblue = image[j][i].rgbtBlue;

            //Get the average (pt = media) to get the gray shades
            float media = (oldred + oldgreen + oldblue) / 3;

            //Assign every value with the average value to make it gray
            image[j][i].rgbtRed = media;
            image[j][i].rgbtGreen = media;
            image[j][i].rgbtBlue = media;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //Get original values for rgb
            float originalRed = image[j][i].rgbtRed;
            float originalGreen = image[j][i].rgbtGreen;
            float originalBlue = image[j][i].rgbtBlue;

            //Assign then with new values (filtering it)
            float newRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            float newGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            float newBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            //Assure values aren't higher than 255
            if (newRed > 255)
            {
                image[j][i].rgbtRed = 255;
            }
            else
            {
                image[j][i].rgbtRed = newRed;
            }
            if (newGreen > 255)
            {
                image[j][i].rgbtGreen = 255;
            }
            else
            {
                image[j][i].rgbtGreen = newGreen;
            }
            if (newBlue > 255)
            {
                image[j][i].rgbtBlue = 255;
            }
            else
            {
                image[j][i].rgbtBlue = newBlue;
            }
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    float temporaryRed[height][width];
    float temporaryGreen[height][width];
    float temporaryBlue[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            temporaryRed[height - 1 - j][width - 1 - i] = image[j][i].rgbtRed;
            temporaryGreen[height - 1 - j][width - 1 - i] = image[j][i].rgbtGreen;
            temporaryBlue[height - 1 - j][width - 1 - i] = image[j][i].rgbtBlue;
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtRed = temporaryRed[height - j - 1][i];
            image[j][i].rgbtGreen = temporaryGreen[height - j - 1][i];
            image[j][i].rgbtBlue = temporaryBlue[height - j - 1][i];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float temporaryRed[height][width];
    float temporaryGreen[height][width];
    float temporaryBlue[height][width];
    int blurry = 1;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i == 0 | j == 0)
            {
                blurry = 0;
            }
            if (j == height - 1 | i == width - 1)
            {
                blurry = 0;
            }
            if (blurry == 1)
            {
                temporaryRed[j][i] = (image[j - 1][i - 1].rgbtRed + image[j - 1][i].rgbtRed + image[j - 1][i].rgbtRed + image[j][i - 1].rgbtRed + image[j][i].rgbtRed + image[j][i + 1].rgbtRed + image[j + 1][i - 1].rgbtRed + image[j + 1][i].rgbtRed + image[j + 1][i + 1].rgbtRed) / 9;
                temporaryGreen[j][i] = (image[j - 1][i - 1].rgbtGreen + image[j - 1][i].rgbtGreen + image[j - 1][i].rgbtGreen + image[j][i - 1].rgbtGreen + image[j][i].rgbtGreen + image[j][i + 1].rgbtGreen + image[j + 1][i - 1].rgbtGreen + image[j + 1][i].rgbtGreen + image[j + 1][i + 1].rgbtGreen) / 9;
                temporaryBlue[j][i] = (image[j - 1][i - 1].rgbtBlue + image[j - 1][i].rgbtBlue + image[j - 1][i].rgbtBlue + image[j][i - 1].rgbtBlue + image[j][i].rgbtBlue + image[j][i + 1].rgbtBlue + image[j + 1][i - 1].rgbtBlue + image[j + 1][i].rgbtBlue + image[j + 1][i + 1].rgbtBlue) / 9;

                image[j][i].rgbtRed = temporaryRed[j][i];
                image[j][i].rgbtGreen = temporaryGreen[j][i];
                image[j][i].rgbtBlue = temporaryBlue[j][i];

            }
            blurry = 1;
        }
    }
    return;
}
