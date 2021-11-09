#include <stdio.h>


int main (void)
{
    //Coletar número do cartão
    long n = 0;
    
    printf("Número do cartão: ");
    scanf("%li", &n);
    
    int i = 0;
    long coeficiente = n;
    
    //contar os digitos
    while (coeficiente>0) 
    {
     coeficiente /= 10;
     i++;
    }
    
    //mensagem de erro caso o os difitos estejam errados
    if (i != 13 && i != 15 && i != 16)
    {
        printf("Número invalido \n");
        return 0;
    }

    int s1 = 0;
    int s2 = 0;
    long x = n;
    int total = 0;
    int m1;
    int m2;
    int d1;
    int d2;    
    
    do
    {
        // vai somar o ultimo numero e retira-lo de x
        m1 = x % 10;
        x = x / 10;
        s1 = s1 + m1;
        
        // vai remover o segundo digito de x
        m2 = x % 10;
        x = x / 10;
        
        // vai dobrar o ultimo segundo digito e soma-lo ao digito em s2
        m2 = m2 * 2;
        d1 = m2 % 10;
        d2 = m2 / 10;
        s2 = s2 + d1 + d2;
    }
    while (x > 0);    total = s1 + s2;
    
    if ((total % 10) != 0)
    
    //checagem do algoritimo de luhn
    printf("Número inválido \n");
    
    //Coletar os primeiros dois digitos 
    long pd = n;
    do
    {
        pd /= 10;
    }
    while (pd > 100);
    
    //verificação America Express
    
    if (pd/10 == 3 && (pd % 10 == 4 || pd % 10 == 7) && i == 15)
    printf("AMEX\n");
    
    //verificação Master Card
    
    else if (pd/10 == 5 && ((0 < pd % 10) && (pd % 10 < 6) ) && i == 16)
    printf("MASTERCARD\n");

    //verificação Visa
   
    else if (pd/10 == 4 && (i == 13 || i == 16))
    printf("VISA\n");
    
    else 
    printf("Número inválido \n");
}


 