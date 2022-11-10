#ifndef FUNCOESAVARIA_H_INCLUDED
#define FUNCOESAVARIA_H_INCLUDED

#define MAX_AVARIAS 200
#define MAX_CODIGO_AVARIA 19
#define MAX_MEIO_COMUNICACAO 30
#define MAX_DESCRICAO 100

#define COMUNICACAO_1 "Telefone"
#define COMUNICACAO_2 "Carta"
#define COMUNICACAO_3 "Email"
#define COMUNICACAO_4 "Portal"

typedef struct {
    char codRegisto[MAX_CODIGO_AVARIA];
    int idPontoIp;
    char meioComunicacao[MAX_MEIO_COMUNICACAO];
    tipoData dataAvaria;
    char descricao[MAX_DESCRICAO];
} tipoAvaria;

/**
 * Adiciona uma avaria ao vetor de avarias ja existentes e devolve a quantidade de avarias atualizada.
 */
int registarAvaria(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int nAvarias, int associada);

/**
 * Obtem os dados da avaria introduzidos pelo utilizador e armazena-os numa nova estrutura do tipo "tipoAvaria".
 * Devolve a estrutura da nova avaria.
 */
tipoAvaria lerDadosAvaria(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, int associada);

/**
 * Le o id do ponto IP a que a avaria esta associada.
 * Apenas e chamada se a avaria em questao nao tiver ja um ponto IP associado.
 */
int lerIdPontoIp(tipoIp pontosIp[], int nPontos);

/**
 * Procura por uma avaria com o mesmo codigo de registo que o utilizador inseriu.
 * Caso ja exista uma com o mesmo codigo a funcao retorna a posicao dessa avaria no vetor.
 * Caso nao exista nenhuma avaria com o mesmo codigo entao a funcao retorna -1.
 */
int procuraAvaria(tipoAvaria avarias[], int nAvarias, char codRegisto[]);

/**
 * Calcula e devolve quantidade de avarias que um ponto IP tem, a partir do seu codigo unico.
 */
int calcularQuantidadeAvarias(tipoAvaria avarias[], int nAvarias, int idPontoIp);

#endif // FUNCOESAVARIA_H_INCLUDED



