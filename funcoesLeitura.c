#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesLeitura.h"

int lerInt(int min, int max)
{
    int n;

    do
    {
        scanf(" %d", &n);
        limparBufferStdin();

        if(n<min || n>max)
        {
            printf("Valor inválido, [%d - %d]", min, max);
        }

    } while (n<min || n>max);

    return n;
}

float lerFloat (int min, int max)
{
    do
    {
        int n;
        scanf(" %f", &n);
        limparBufferStdin();
    if(n<min || n>max)
        {
            printf("Valor inválido, [%d - %d]", min, max);
        }
    }while(n<min || n>max);

    if(n<min || n>max)
    {
        printf("Valor inválido, [%d - %d]", min, max);
    }

    return n;
}

void lerString (char vetor[], int max)
{
    int tamanhoString;

    do
    {
        fgets(vetor, max, stdin);
        tamanhoString = strlen(vetor);
    } while (tamanhoString == 1);

    if(vetor[tamanhoString -1] != '\n')
    {
        limparBufferStdin();
    }
}

void limparBufferStdin(void)
{
    char lixo;

    do
    {
        lixo=getchar();

    }
    while(lixo!='\n' && lixo != EOF);
}

tipoData lerData
{
 int maxDia, min, max;
 tipoData novaData;

min = 2022;
max = 2023;

 printf("Ano: ");
 novaData.ano = lerInt( ,)


min = 1;
max = 12;

 printf("Mes: ");
 novaData.mes = lerInt(1,12);

 if( (novaData.ano%4)==0 && novaData.mes == 2)
 {
    maxDia = 29;
 }

switch(novaData.mes)
{
    case 2:
        maxDia = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDia = 30;
        break;

    default:
        maxDia = 31;
}

min = 1;
max = maxDia;
printf("Dia: ");
novaData.dia = lerInt(1, maxDia);

}

int lerIntExato(int limite1, int limite2, int limite3)
{
    int n;

    do
    {
        scanf("%d", &n);

        if(n != limite1)
        {
            if(n != limite2)
            {
                if(n != limite3)
                {
                    printf("ERRO - O VALOR É INVALIDO, INSERIR [%d, %d ou %d]", limite1, limite2, limite3);
                }
            }
        }

    } while (n != limite1 && n != limite2 && n != limite3);

    return n;
}
