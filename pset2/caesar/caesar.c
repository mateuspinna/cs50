#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// coleta a quantidade de argumentos e armazena o argumento como uma string
int main (int argc, string argv[])
{
    //analisa o segundo argumento adimitindo apenas o uso de números
    if(argc == 2)
    {
        //reporta erro caso algum caractere não for um algarismo de 0 a 9 
        for (int i = 0, n=strlen(argv[1]); i < n; i++)
        {
            if ((argv[1][i] < '0' || argv[1][i] > '9'))
            {
            
            printf("Usage: ./caesar key\n");
            return 0;
            }   
        }
        
        // transforma o vertor do argumento 1 em inteiro para ser utilizado como chave
        int key = atoi(argv[1]);
        
        // solicita o plaintext ao usuario
        string pt = get_string("plaintext: ");
        
        //vai contar a quantidade de caracteres presentes no plaintext que será utilizado como mecanismo de repetição
        int len = strlen(pt);
        
        printf("ciphertext: ");
        
        // vai imprimir os caracteres alfabéticos com a criptografia caesar e imprimir qualquer da mesma forma que no plaintext
        for (int i = 0; i < len; i++)
        {
        
        if (pt[i] >= 'a' && pt[i] <= 'z')
            
            {
            printf("%c", (((pt[i] + key) - 'a') % 26) + 'a');
            }
        
        else if (pt[i] >= 'A' && pt[i] <= 'Z')
        
            {
            printf("%c", (((pt[i] + key) - 'A') % 26) + 'A');
            }
        else
        {
            char x = pt[i];
            printf("%c", x);
        }
        }
    }
    else
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }

        printf("\n");
        return 0;
}


