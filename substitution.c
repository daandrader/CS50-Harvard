#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int validate1(string key); //valida primera condicion
int validate2(string key); //valida segunda condicion
int validate3(string key); //valida tercera condicion
void encipher(string key, string input); // cifra el texto y lo imprime

int main(int argc, string argv[])
{
    if (argc == 2 && validate1(argv[1]) == 1 && validate2(argv[1]) == 1 
        && validate3(argv[1]) == 1) //checa que el numero de argumentos sea 2 y las condiciones se cumplan
    {
        string input = get_string("plaintext:  ");
        //printf(":  %s\n", input);
        encipher(argv[1], input);
        return 0;
    }
    else if (argc != 2) // en caso que los argumentos sean diferentes de dos
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (validate1(argv[1]) == 1)  // valida 1 
    {
        return 1;
    }

    else if (validate2(argv[1]) == 1) // valida 2
    {
        return 1;
    }
    else if (validate3(argv[1]) == 1) //valida 3
    {
        return 1;
    }

}
// cifra el texto
void encipher(string key, string input)
{

    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("ciphertext: ");
    for (int i = 0; i < strlen(input); i++)
    {
        for (int j = 0; j < strlen(alp) ; j++)
        {
            if (toupper((int) input[i]) == toupper((int) alp[j]))
            {
                if (islower(input[i]))
                {
                    printf("%c", tolower(key[j]));
                }
                else if (isupper(input[i]))
                {
                    printf("%c", toupper(key[j]));
                }
            }
        }
        if ((int) input[i] >= 32 && (int) input[i] <= 64)
        {
            printf("%c", input[i]);
        }
    }
    printf("\n");

}
//checa que la key tenga 26 caracteres
int validate1(string key)
{
    int n = strlen(key);
    if (n != 26) // si la longitud de la llave no es 26
    {
        printf("Key must contain 26 characters.\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
//checa que solo tenga caracteres alfa numericos
int validate2(string key)
{
    int n = strlen(key);
    for (int i = 0; i < n ; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("The key must contain only alphabetic characters\n");
            return 0;
        }
    }
    return 1;
}
//checa que no tenga caracteres repetidos
int validate3(string key)
{
    int n = strlen(key);
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if ((int) key[i] == (int) key[j])
            {
                printf("The key must not contain repeated characters.\n");
                return 0;
            }

        }
    }
    return 1;
}