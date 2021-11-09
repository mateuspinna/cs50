#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                RGBTRIPLE pixel = image[i][j];
                int média = round ((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3);
                
                image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = média;
            }
        }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                RGBTRIPLE pixel = image[i][j];
                
                int sepiared = round(pixel.rgbtRed*0.393 + pixel.rgbtGreen*0.769 + pixel.rgbtBlue*0.189);
                int sepiagreen = round(pixel.rgbtRed*0.349 + pixel.rgbtGreen*0.686 + pixel.rgbtBlue*0.168);
                int sepiablue = round(pixel.rgbtRed*0.272 + pixel.rgbtGreen*0.534 + pixel.rgbtBlue*0.131);
                
                image[i][j].rgbtRed = sepiared;
                
                if (sepiared > 255)
                {
                image[i][j].rgbtRed = 255;
                }
                
                image[i][j].rgbtGreen = sepiagreen;
                
                if (sepiagreen > 255)
                {
                image[i][j].rgbtGreen = 255;
                }
                
                image[i][j].rgbtBlue = sepiablue;
                
                if (sepiablue > 255)
                {
                image[i][j].rgbtBlue = 255;
                }
            }
        }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE reflect[height][width];
    
    
    for (int i = 0; i < height; i++)
        {
                int coluna = 0;
                for (int j = width; j >= 0; j--, coluna++)
                {
                    reflect[i][coluna] = image[i][j];
                }
        }
    
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][j] = reflect[i][j];
            }
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
   RGBTRIPLE blur[height][width];
   
   for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                int contador = 0;
                int rowCoords[] = {row-1, row, row+1};
                int colCoords[] = {col-1, col, col+1};
                float totalR = 0;
                float totalG = 0;
                float totalB = 0;
                
                for (int l = 0; l < 3; l++)
                    {
                        for (int c = 0; c <3; c++)
                        {
                        int linhaAtual = rowCoords[l];
                        int colunaAtual = colCoords[c];
                        
                        if (linhaAtual >= 0 && linhaAtual < height && colunaAtual >= 0 && colunaAtual < width )
                        {
                            RGBTRIPLE pixel = image[linhaAtual][colunaAtual];
                            
                            totalR += pixel.rgbtRed;
                            totalG += pixel.rgbtGreen;
                            totalB += pixel.rgbtBlue;
                            
                            contador++;
                        }
                        }
                            
                    }
            
                blur[row][col].rgbtRed = round(totalR / contador);
                blur[row][col].rgbtGreen = round(totalG / contador);
                blur[row][col].rgbtBlue = round(totalB / contador);
            }
        }
   
   
   
   
   for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][j] = blur[i][j];
            }
        }
   
   
    return;
}
