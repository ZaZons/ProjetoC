#ifndef FUNCOESINTERVENCAO_H_INCLUDED
#define FUNCOESINTERVENCAO_H_INCLUDED

typedef struct{
    char codIntervencao[1];
    tipoData dataIntervencao;
    char cpe[MAX_CPE];
    char descricaoIntervencao[150];
    float custoIntervencao;
    int substituicaoLuminaria;
    int operacional;
}tipoIntervencao;

void obterDadosIntervencao(tipoIp pontosIP[], int n);
float custoIntervencao(tipoIntervencao intervencoes, int n);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
