#include "helpers.h"
#include "math.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{float a;
    for(int j = 0; j < width; j++)
    {
       for (int i = 0; i < height; i++)
       {
           a=(image[i][j].rgbtGreen+image[i][j].rgbtRed+image[i][j].rgbtBlue)/3.0;
           image[i][j].rgbtGreen=round(a);
           image[i][j].rgbtRed=round(a);
           image[i][j].rgbtBlue=round(a);


       }}
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int j = 0; j < width; j++)
    {
       for (int i = 0; i < height; i++)
       {float a;
       float b;
       float c;

           a=.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
           b=.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;

           c=.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
           if(a>255){a=255;}
           if(b>255){b=255;}
           if(c>255){c=255;}

           image[i][j].rgbtRed=round(a);
           image[i][j].rgbtGreen=round(b);
           image[i][j].rgbtBlue=round(c);




       }}
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{RGBTRIPLE copy[height][width];
for(int j = 0; j < width; j++)
    {
       for (int i = 0; i < height; i++)
       {copy[i][j]=image[i][j];}}
    for(int j = 0; j < width; j++)
    {
       for (int i = 0; i < height; i++)
       {
    //        if(j<=width/2){
    //         //    image[i][j]=image[i][(j*-1)+width];

    //            image[i][j]=image[i][(j*-1)+width];
    //        }




               image[i][j]=copy[i][(j*-1)+width-1];




       }}
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{RGBTRIPLE copy[height][width];
    float sum_red;
    float sum_green;
    float sum_blue;
    float counter;
    for(int j = 0; j < width; j++)
    {
       for (int i = 0; i < height; i++)
       {
           sum_blue = 0;
            sum_green = 0;
            sum_red = 0;
            counter = 0;
           for (int h= -1; h < 2; h++)
        {
            if (j + h < 0 || j + h > width - 1)
            {
                continue;
            }

        for (int v = -1; v < 2; v++)
            {
                if (i + v < 0 || i + v > height - 1)
                {
                    continue;
                }

                sum_red += image[i + v][j + h].rgbtRed;
                sum_blue += image[i + v][j + h].rgbtBlue;
                sum_green += image[i + v][j + h].rgbtGreen;
                counter++;
            }
        }
        copy[i][j].rgbtRed = round(sum_red / counter);
        copy[i][j].rgbtBlue = round(sum_blue / counter);
        copy[i][j].rgbtGreen = round(sum_green / counter);


       }}
       for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        image[i][j].rgbtRed = copy[i][j].rgbtRed;
        image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
    }
}
    return;
}
