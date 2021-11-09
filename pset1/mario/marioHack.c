#include <stdio.h>
#include <cs50.h>

int main(void)
   
    {
        
        int n = get_int("Escolha a altura da pirâmide(1-8)");
        
        while (n < 1 || n > 8)
        {
            n = get_int("Escolha a altura da pirâmide(1-8)");
        }
        
        if (n == 1)
        {
            printf("       #  #       \n");
        }
        else if (n == 2)
        {
            printf("       #  #       \n      ##  ##      \n");
        }
        else if (n == 3)
        {
            printf("       #  #       \n      ##  ##      \n     ###  ###     \n");
        }
        else if (n == 4)
        {
            printf("       #  #       \n      ##  ##      \n     ###  ###     \n    ####  ####    \n");
        }
        else if (n == 5)
        {
            printf("       #  #       \n      ##  ##      \n     ###  ###     \n    ####  ####    \n   #####  #####   \n");
        }
        else if (n == 6)
        {
            printf("       #  #       \n      ##  ##      \n     ###  ###     \n    ####  ####    \n   #####  #####   \n  ######  ######  \n");
        }
        else if (n == 7)
        {
            printf("       #  #       \n      ##  ##      \n     ###  ###     \n    ####  ####    \n   #####  #####   \n  ######  ######  \n #######  ####### \n");
        }
        else
        {
            printf("       #  #       \n      ##  ##      \n     ###  ###     \n    ####  ####    \n   #####  #####   \n  ######  ######  \n #######  ####### \n########  ########\n");
        }
    }
    
    