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

/**
 * Le e devolve um numero inteiro introduzido pelo utilizador, compreendido entre os valores min e max.
 * Se o valor nao estiver compreender entre o minimo e o maximo, apresenta uma mensagem de erro e repete a funcao
 */
int lerInt(int min, int max);

/**
 * Le e devolve um numero decimal introduzido pelo utilizador, compreendido entre os valores min e max.
 * Se o valor nao estiver compreender entre o minimo e o maximo, apresenta uma mensagem de erro e repete a funcao
 */
float lerFloat(float min, float max);

/**
 * Le uma string com um numero maximo de caracteres (max + 1).
 * Se o numero de caracteres for 1, apresenta uma mensagem de erro e repete a funcao.
 * "Corta" o ultimo caracter ('\n') e devolve a string.
 */
void lerString(char vetor[], int max);

/**
 * Limpa o buffer 
 */
void limparBufferStdin(void);

/**
 * Le e devolve a data e hora na estrtutra tipoData.
 * Impoe valores minimos e maximos de acordo com o ano e mes selecionados.
 */
tipoData lerData();

/**
 * Valida se uma data e menor que a outra.
 * Caso a validacao seja verdadeira entao retorna 1, caso contrario retorna 0.
 */
int validarData(tipoData dataMenor, tipoData dataMaior);

#endif // FUNCOESLEITURA_H_INCLUDED
