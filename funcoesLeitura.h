#ifndef FUNCOESLEITURA_H_INCLUDED
#define FUNCOESLEITURA_H_INCLUDED

typedef struct{
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
}tipoData;

int lerInt(int min, int max);
float lerFloat(int min, int max);
void lerString(char vetor[], int max);
void limparBufferStdin(void);
int lerIntExato(int limite1, int limite2, int limite3);

#endif // FUNCOESLEITURA_H_INCLUDED
