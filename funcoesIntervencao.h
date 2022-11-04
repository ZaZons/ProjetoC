#ifndef FUNCOESINTERVENCAO_H_INCLUDED
#define FUNCOESINTERVENCAO_H_INCLUDED

typedef struct{
    int ID;
    tipoData dataIntervencao;
    char descricaoIntervencao[150];
    float custoIntervencao;
    int susbtituicaoLuminaria;
    int operacional;
}tipoIntervencao;

void obterDadosIntervencao(tipoIp pontosIP[], int quantidadePontos);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
