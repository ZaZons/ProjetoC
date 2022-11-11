#ifndef FUNCOESINTERVENCAO_H_INCLUDED
#define FUNCOESINTERVENCAO_H_INCLUDED

#define MAX_CODIGO_INTERVENCAO MAX_CODIGO_AVARIA
#define MAX_INTERVENCOES MAX_AVARIAS
#define MIN_CUSTO 0.01
#define MAX_CUSTO 2000.0
#define MAX_DESCRICAO_INTERVENCAO 150

typedef struct {
    char codIntervencao[MAX_CODIGO_INTERVENCAO];
    int idPontoIp;
    tipoData dataIntervencao;
    char descricaoIntervencao[MAX_DESCRICAO_INTERVENCAO];
    float custoIntervencao;
    int substituicaoLuminaria;
    int operacional;
} tipoIntervencao;

/**
 * Adiciona uma intervencao ao vetor de intervencoes ja existentes e devolve a quantidade de intervencoes atualizada.
 */
int registarIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int nAvariasResolvidas);

/**
 * Obtem os dados da intervencao introduzidos pelo utilizador e armazena-os numa nova estrutura do tipo "tipoIntervencao".
 * Devolve a estrutura da nova intervencao.
 */
tipoIntervencao lerDadosIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias);

/**
 * Guarda informacao atualizada das intervencoes num Log (ficheiro de texto) sempre que uma nova intervencao e introduzida
 */
void gravarLog(tipoIntervencao intervencoes[], int nIntervencoes);

/**
 * Calcula e devolve o custo total das intervencoes feitas a um ponto IP.
 */
float custoTotalIntervencoes(int id, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
