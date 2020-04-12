#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// Este programa calcula el indice de lectura de Coleman-Liau para cualquier texto

// encabezados de funciones
int letters(string word);
int words(string word);
int sentences(string word);

int main(void)
{
    // se solicita un string
    string s = get_string("Texto: ");
    // se calculan las contantes y el indice
    float L = (float) letters(s) / words(s) * 100;
    float S = (float) sentences(s) / words(s) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    //Se agregan condiciones acorde con el valor del indice
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }



}
//Funcion para calcular el numero de letras
int letters(string text)
{
    int word_c = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            word_c += 1;
        }
    }
    return word_c;
}
//Funcion para calcular el numero de palabras
int words(string text)
{
    int word_c = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32 && isalpha(text[i + 1]))
        {
            word_c += 1;
        }
    }
    return word_c;
}
// Funcion para calcular el numero de oraciones
int sentences(string text)
{
    int word_c = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            word_c += 1;
        }
    }
    return word_c;
}
