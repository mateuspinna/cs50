#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h, i, j;

    // Essa parte pergunta a altura das 2 pirâmides
    do
    {
        h = get_int("Quão alta você deseja a pirâmide?\n ");
    }



    while(h < 1 || h > 8);

    // mecanismo de repetição que vai imprimir os blocos de forma adequada
    for(i = 0; i < h ; i++)
    {
        for(j = 0; j < h - 1 - i ; j++)
        {
            printf(" ");
        }
        for(j = 0 ; j < i + 1 ; j++)
        {
            printf("#");
        }


        printf("\n");
    }

}