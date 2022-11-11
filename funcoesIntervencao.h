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
//Pede um valor inteiro ao utilizador, procura se existe um PontoIp e uma avaria associadas a esse valor
//Se existir o pontoIp e a avaria, pede a data e hora da intervencao, descric�o, custo, se foi substituida a luminaria e se o pontoIp ficou operacional
//Altera o estado de funcionamento do pontoIp conforme inserido no operacional do registo de intervencao
void obterDadosIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias);

//Calcula e devolve o custo total das intervencoes atraves de ciclos que verificam se existe uma intervencao associada a um PontoIp, somando o caso exista
float custoTotalIntervencoes(int id, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
