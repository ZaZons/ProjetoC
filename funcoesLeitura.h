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

//Le e devolve um numero inteiro itnroduzido pelo utilizador, compreendido entre os valores min e max
//Se o valor n�o estiver compreender entre o minimo e o maximo, apresenta uma mensagem de erro e repete a funcao
int lerInt(int min, int max);

//Le e devolve um numero decimal itnroduzido pelo utilizador, compreendido entre os valores min e max
//Se o valor n�o estiver compreender entre o minimo e o maximo, apresenta uma mensagem de erro e repete a funcao
float lerFloat(float min, float max);

//Le e devolve um vetor at� um certo m�ximo de caracteres, sendo o mesmo definido pelo valor inteiro de max
//Se o numero de caracteres for 1, repetida a leitura do input do utilizador
void lerString(char vetor[], int max);

//Limpa o buffer
void limparBufferStdin(void);

//Le e devolve um numero inteiro entre o valor minimo e o m�ximo recebido pela funcao
//Caso nao seja inserido um valor correspondente entre o valor minimo e maximo, envia uma mensagem de erro e volta a pedir para inserir um valor inteiro
int lerEscolhaMultipla(int min, int max);

//Le e armazena a data e hora na estrtutra tipoData
//Impoe valores minimos e maximos de acordo com o ano e mes selecionados
tipoData lerData();

/**
 * Valida se uma data e menor que a outra.
 * Caso a validacao seja verdadeira entao retorna 1, caso contrario retorna 0.
*/
int validarData(tipoData dataMenor, tipoData dataMaior);

#endif // FUNCOESLEITURA_H_INCLUDED
