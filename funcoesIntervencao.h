#ifndef FUNCOESINTERVENCAO_H_INCLUDED
#define FUNCOESINTERVENCAO_H_INCLUDED

#define MAX_CODIGO_INTERVENCAO MAX_CODIGO_AVARIA
#define MAX_INTERVENCOES MAX_AVARIAS

typedef struct {
    char codIntervencao[MAX_CODIGO_INTERVENCAO];
    tipoData dataIntervencao;
    char cpe[MAX_CPE];
    char descricaoIntervencao[150];
    float custoIntervencao;
    int substituicaoLuminaria;
    int operacional;
} tipoIntervencao;

void obterDadosIntervencao(tipoIp pontosIP[], int n);
float custoIntervencao(tipoIntervencao intervencoes, int n);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
