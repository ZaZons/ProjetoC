#ifndef FUNCOESINTERVENCAO_H_INCLUDED
#define FUNCOESINTERVENCAO_H_INCLUDED

#define MAX_CODIGO_INTERVENCOES

typedef struct{
    char codIntervencao[MAX_CODIGO_INTERVENCOES];
    tipoData dataIntervencao;
    char cpe[MAX_CPE]
    char descricaoIntervencao[150];
    float custoIntervencao;
    int substituicaoLuminaria;
    int operacional;
}tipoIntervencao;

void obterDadosIntervencao(tipoIp pontosIP[], int quantidadePontos);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
