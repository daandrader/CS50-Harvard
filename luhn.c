#include<stdio.h>
#include<cs50.h> // cs50 harvard custom library
#include<math.h>
#include<stdlib.h>

int checksum(long int cc);
void typecc(long int cc);

int main(void){
    long int cc; // = 369421438430814;
    
    do
    {
    cc = get_long("Number: ");
    } while (cc < 0);
    

    if (checksum(cc) == 1){
        typecc(cc);
        //printf("VALID\n");    
    }
    else
    {
        printf("INVALID\n");
    }
    
   //checksum(cc);
}

int checksum(long int cc){ // implementa y verifica el algoritmo de Luhn
    int rem = 0;
    int n = 0;
    int tmp = 0;
    int tmp1 = 0;
    int val, rem_i;
    while (cc > 0)
    {
        rem = cc % 10; 
        
        if (n % 2 == 0)
        {
            tmp += rem;
        }
        else if (n % 2 == 1)
        {
            val = rem*2;
            while (val>0)
            {
                rem_i = val % 10;
                tmp1 += rem_i;
                val = val / 10;
                //printf("rem_i es %i\n", rem_i);
            }
            
        }
        cc /= 10;
        n++;         
    }
    int suma = tmp +tmp1;
    if (suma  % 10 == 0){
        return 1;
        //printf("La suma es %i\n", suma);
        //printf("tmp es %i\n", tmp);
        //printf("tmp1 es %i\n", tmp1);
    }
    else
    {
        return 0;
       //printf("La suma es %i\n", suma);
    }
    
}

void typecc(long int cc){ // verifica los primeros digitos de la cc y da su tipo
    
    int nDigits = floor(log10(labs(cc))) + 1; // establece el numero de digitos en la tarjeta (labs for long int)
    int n = 0;
    int rem = 0;
    int firstD, secondD;
    
    while(cc > 0)
    {
        rem = cc % 10; 
        
        if(n == nDigits-1){
            firstD = rem;
        }
        else if (n == nDigits -2)
        {
            secondD = rem;
        }
        cc /= 10;
        n++;
    }
    
   
    if ((firstD == 3 && secondD ==4 && nDigits == 15) || (firstD == 3 && secondD ==7 && nDigits == 15))
    {
        printf("AMEX\n");
    }
    else if ((firstD == 5 && secondD ==1 && nDigits == 16) || (firstD == 5 && secondD ==2 && nDigits == 16) || 
    (firstD == 5 && secondD ==3 && nDigits == 16) || (firstD == 5 && secondD ==4 && nDigits == 16) || (firstD == 5 && secondD ==5 && nDigits == 16)) 
    {
        printf("MASTERCARD\n");
    }
    else if ((firstD == 4 && nDigits == 13) || (firstD == 4 && nDigits == 16) )
    {
        printf("VISA\n");  
    }
    else
    {
         printf("INVALID\n"); 
    }
    

}
