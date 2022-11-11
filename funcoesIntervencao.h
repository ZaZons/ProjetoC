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

//Valida se é possivel criar um novo registo de intervencao, se possivel incrementa à variavel nIntervencoes
//Se nIntervencoes for maior que o numero maximo ou nao houver avarias registadas, apresentadas mensagens de erro. S
int registarIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int nAvariasResolvidas);

//Estrutura responsavel de guardar os dados inseridos pelo utilizador(data e hora de intervencao, descricao, custo, se foi substituida a luminaria, se for substituida que tecnologia foi utilizada
//se for substituida que tecnologia foi utilizada, se o ponto ficou operacional)
//Altera o valor de estado de funcionamento do pontoIp se na intervencao se afirmar que está operacional
tipoIntervencao lerDadosIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias);

//Grava os dados de tipoEstrutura intervencoes no ficheiro "intervencoes.txt"
//Caso o ficheiro nao abra corretamento, é mostrado uma mensagem de erro
void gravarLog(tipoIntervencao intervencoes[], int nIntervencoes);

//Pede um valor inteiro ao utilizador, procura se existe um PontoIp e uma avaria associadas a esse valor
//Se existir o pontoIp e a avaria, pede a data e hora da intervencao, descric�o, custo, se foi substituida a luminaria e se o pontoIp ficou operacional
//Altera o estado de funcionamento do pontoIp conforme inserido no operacional do registo de intervencao
void obterDadosIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias);

//Calcula e devolve o custo total das intervencoes atraves de ciclos que verificam se existe uma intervencao associada a um PontoIp, somando o caso exista
float custoTotalIntervencoes(int id, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

#endif // FUNCOESINTERVENCAO_H_INCLUDED
