#ifndef FUNCOESLEITURA_H_INCLUDED
#define FUNCOESLEITURA_H_INCLUDED

#define MIN_ANO 2022
#define MAX_ANO 2023

typedef struct{
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
} tipoData;

int lerInt(int min, int max);
float lerFloat(float min, float max);
void lerString(char vetor[], int max);
void limparBufferStdin(void);
int lerEscolhaMultipla(int min, int max);
int lerInt3(int limite1, int limite2, int limite3);
tipoData lerData();

#endif // FUNCOESLEITURA_H_INCLUDED
