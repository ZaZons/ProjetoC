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

int registarIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int nAvariasResolvidas);
tipoIntervencao lerDadosIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias);
void gravarLog(tipoIntervencao intervencoes[], int nIntervencoes);
float custoTotalIntervencoes(int id, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
