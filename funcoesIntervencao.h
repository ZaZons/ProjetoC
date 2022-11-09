#ifndef FUNCOESINTERVENCAO_H_INCLUDED
#define FUNCOESINTERVENCAO_H_INCLUDED

#define MAX_CODIGO_INTERVENCAO MAX_CODIGO_AVARIA
#define MAX_INTERVENCOES MAX_AVARIAS
#define MIN_CUSTO 0.01
#define MAX_CUSTO 2000.0
#define MAX_DESCRICAO_INTERVENCAO 150

typedef struct {
    char codIntervencao[MAX_CODIGO_INTERVENCAO];
    tipoData dataIntervencao;
    char cpe[MAX_CPE];
    char descricaoIntervencao[MAX_DESCRICAO_INTERVENCAO];
    float custoIntervencao;
    int substituicaoLuminaria;
    int operacional;
} tipoIntervencao;

void obterDadosIntervencao(tipoIp pontosIp[], int n, tipoAvaria avarias[], int nAvarias);
float custoIntervencao(tipoIntervencao intervencoes[], int nIntervencoes, tipoAvaria avarias[], int nAvarias, tipoIp pontosIp[], int nPontos);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
