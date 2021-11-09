#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
    //Solicita o input do texto ao usuario
    string text = get_string("Text: ");

    //declara as variaveis que serão usadas no calculo do indice
    int letras = 0;
    int palavras = 0;
    int sent = 0;

    //tamanho da string que sera usado no loop
    int n = strlen(text);


    // contador de letras, sentenças e palavras
    for (int i = 0; n > i; i++)
        {
        if (isalpha(text[i]) != 0)

            letras++ ;

        else if (text[i] == ' ')

            palavras++;

        else if (text[i] == '.' || text[i] == '?' || text[i] == '!' )

            sent++;

        }

    // soma a ultima palavra que nao seria contada pela falta do ' '
    palavras++;

        }

    //calculo das variaveis L S e também do indice Coleman-Liau
    double L = ((float)letras/(float)palavras)*100;
    double S = ((float)sent/(float)palavras)*100;
    double indice = (0.0588*L) - (0.296*S) - 15.8;

    //exibe a grade adequada ao indice obtido
    if (indice < 1)

    printf("Before Grade 1\n");

    else if (indice >= 1 && indice <=15)

    printf("Grade %.0f\n", round(indice));

    else

    printf("Grade 16+\n");

}