#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char soma (char num1,char num2);
int *resto;

////////////////////////////////MAIN////////////////////////////////////////
int main(){
    char string[20], n1, n2;
    int length, length2, i = 0, aux, contSoma = 0, x = 0, count=0;

    resto = &x;

    scanf("%s", string);

    length = strlen(string);

    printf("String de input: %s\n", string);

    for(; i<length; i++){
        n1 = n2 = '0';
        if (i == length-1){
            for(; string[i]!='+';i--){
                if (string[i]!='x'){
                    n2 = string[i];
                    string[i] = 'x';
                    printf("n2 = %c\nstring = %s\n", n2, string);
                    for(; string[i]!='+'; i--);
                    i++;
                    aux=i;
                }
            }
            if (string[i]=='+'){
                i--;
                printf("pulou o '+'\n");
            }
            for(; i>=0; i--){
                if (string[i]!='x'){
                    n1 = string[i];
                    string[i] = 'x';
                    printf("n1 = %c\nstring = %s\n", n1, string);
                    for(; i>0; i--);
                }   
            }
            string[length+contSoma] = soma(n1, n2);
            string[length+contSoma+1] = '\0';
            contSoma++;
            printf("string: %s\n", string);   
        }
        if (string[0]=='x'&&string[aux]=='x'){
            break;
        }   
    }

    if (*resto == 1){
        printf("add +1");
        string[length+contSoma] = '1';
        string[length+contSoma+1]='\0';
    }

    printf("string:%s\n", string);
    length2 = strlen(string);
    aux = length2;

    for (i = length2; i>length; --i){   
        string[aux] = string[i-1];
        aux++;
        count++;
        printf("count%d", count);
    }
    
    
    string[length]='=';
    
    
    for(i = length; i<length2; i++){
        string[i+1]=string[i+count];
        printf("string no for:%s\n", string);
    }
    
    string[length2+1] = '\0';

    printf("string:%s\n", string);

    return 0;
}

char soma (char num1, char num2){
    char resultado;
    int r, nInt1, nInt2;

    nInt1 = num1-48;
    printf("nInt1 = %d\n", nInt1);
    nInt2 = num2-48;
    printf("nInt2 = %d\n", nInt2);

    r = nInt1 + nInt2;
    if (*resto == 1){
        r++;
        *resto = 0;
        printf("resgatou +1\n");
    }

    if (r>9){
        *resto = 1;
        r = r - 10;
        printf("add +1\n");
    }

    resultado = r+48;

    printf("resultado da soma = %c\n", resultado);
    return resultado;
}