#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float VP = -1;
    int Q = 0;
    int D = 0;
    int N = 0;
    int P = 0;
    
    while (VP <= 0)
     {
        VP = get_float("Qual valor do troco a ser pago?\n");
     }
     
     int cent = round(VP * 100);
     
     while ((cent - 25) >= 0)
     {
         cent = cent - 25;
         Q++;
     }
     while ((cent - 10) >= 0)
     {
         cent = cent - 10;
         D++;
     }
     while ((cent - 5) >= 0)
     {
         cent = cent - 5;
         N++;
     }
     while ((cent - 1) >= 0)
     {
         cent = cent - 1;
         P++;
     }
     
     int moedas = Q + D + N + P;
     printf("Você precisará de %i moedas:\n %i Quarters\n %i Dimes\n %i Nickels\n %i Pennies\n", moedas, Q, D, N, P);
}




