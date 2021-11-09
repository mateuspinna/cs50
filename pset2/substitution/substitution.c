#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// coleta a quantidade de argumentos e armazena o argumento como uma string
int main (int argc, string argv[])
{
    {
    //analisa o segundo argumento adimitindo apenas o uso de números
    if(argc == 2)
    {

        int n = strlen(argv[1]);

        if (n != 26)
        {
        printf("Key must contain 26 characters\n");
        return 1;
        }
        
        //reporta erro caso algum caractere não for uma letra
        for (int i = 0; i < n; i++)
        {
            if (isalpha(argv[1][i]) == 0)
            {
            printf("Key must contain only letters\n");
            return 1;
            }
        }
        // key digitada ao inicializar o programa
        string kd = argv[1];

        
        // variavel onde será armazenada os valores de 0 a 25 que ao adicionar o char 'a' ou 'A' achamos 
        // o char correspondente tendo como referencia a sequencia fornecida pelo usuario
        char key[26];

        // verificação de repetição das letras
        // a variavel vai armazenar 26 booleans diferentes
        bool letrasverif[26];

            //vai setar todas as posições como false
            for (int i = 0; i<26 ; i++)
            {
             letrasverif[i] = false;
            }
            
            
            // Os valores armazenados vao variar de 0 - 25, caso seja um valor novo vai salvar como true e salvar o valor inteiro, 
            // caso ja seja true vai reportar erro de repetição
            for (int i = 0; i<26 ; i++)
            {
            if (isupper(kd[i]))
                {
                if((letrasverif[kd[i] - 'A']) == true)
                {
                printf("You must not repeat the same letter\n");
                return 1;
                }
                else
                {
                letrasverif[kd[i] - 'A'] = true;
                key[i] = kd[i] - 'A';
                }
                }
            else
            {
                if((letrasverif[kd[i] - 'a']) == true)
                {
                printf("You must not repeat the same letter\n");
                return 1;
                }
                else
                {
                letrasverif[kd[i] - 'a'] = true;
                key[i] = kd[i] - 'a';
                }
            }
            }
        
        // solicitação de input do texto a ser criptografado
        string pt = get_string("plaintext: ");
        string ct = pt;

        int len = strlen(pt);
        
        // mecanismo de repetição que vai criptografar cada char e armazena-lo na varialvel ct para ser impresso como ciphertext
        for (int i = 0; i < len; i++)
       {

        if (pt[i] >= 'a' && pt[i] <= 'z')

            {
            ct[i] = ((key[pt[i] - 'a']) + 'a');
            }

        else if (pt[i] >= 'A' && pt[i] <= 'Z')

            {
            ct[i] = ((key[pt[i] - 'A']) + 'A');
            }
        
        //esse else serve para deixar intacto os chars que nao são letras
        else
        {
            ct[i] = pt[i];
        }
        }

    printf("ciphertext: %s\n", ct);
    }
        // reporta erro caso o numero de argumentos não seja 2
        else
        {
        printf("Usage: ./subtitution key\n");
        return 1;
        }
    }
}