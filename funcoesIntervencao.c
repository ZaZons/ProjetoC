#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"

int validacaoIntervencao(int n1, int n2)
{
    int valor = 0;
    if(n1 == n2)
    {
        valor = 1;
    }
    else
    {
        valor = 0;
    }

    return valor;
}

void obterDadosIntervencao(tipoIp pontosIp[], int n, tipoAvaria avarias[], int nAvarias){

    tipoIntervencao novaIntervencao;
    int i, validacaoIp;
    float  min, max;
    char codAvaria[MAX_CODIGO_AVARIA] = "NULL";
    int idIp = 0;
    int avariaExiste = 0;

    do
    {
        printf("\nIP sujeito a intervenção: ");
        idIp = lerInt(MIN_IP_ID, MAX_IP_ID);

        validacaoIp = procuraPontoIp(pontosIp, n, idIp);

        if(validacaoIp == -1)
        {
            printf("\nPonto IP nao encontrado");
        } else {
            if (pontosIp[validacaoIp].estadoFuncionamento == 1) {
                printf("\nO ponto selecionado nao necessita de intervencao.");
            } else {
                for(i=0; i<nAvarias; i++)
                {
                    if(avarias[i].idPontoIp == idIp)
                    {
                        strcpy(novaIntervencao.codIntervencao, avarias[i].codRegisto);
                        avariaExiste = 1;
                    }
                }

                if(avariaExiste == 0)
                {
                    printf("\nRegisto de avaria inexistente");
                } else {
                    printf("Insira a data e hora da intervencao: ");
                    novaIntervencao.dataIntervencao = lerData(MIN_ANO, MAX_ANO);

                    strcpy(novaIntervencao.cpe, pontosIp[validacaoIp].cpe);

                    printf("Insira a descricao da intervencao: ");
                    lerString(novaIntervencao.descricaoIntervencao, MAX_DESCRICAO_INTERVENCAO);

                    printf("Insra o custo da intervencao: ");
                    novaIntervencao.custoIntervencao = lerFloat(MIN_CUSTO, MAX_CUSTO);

                    min=0;
                    max=1;
                    printf("\nFoi efetuada substituição de Luminaria? [0 - Não] [1 - Sim]");
                    novaIntervencao.substituicaoLuminaria = lerInt(min, max);

                    printf("\nO Ponto IP ficou operacional? [0 - Não] [1 - Sim]");
                    novaIntervencao.operacional = lerInt(min, max);

                    pontosIp[validacaoIp].estadoFuncionamento = novaIntervencao.operacional; // alterar o estado de funcionamento no pontosIp

                }
            }
        }
    }while(validacaoIp == -1);
}

float custoIntervencao(tipoIntervencao intervencoes[], int nIntervencoes, tipoAvaria avarias[], int nAvarias, tipoIp pontosIp[], int nPontos) //verificar se uso int n ou variavel
{
    float custoTotalReparacoes = 0;

    for (int j = 0; j < nIntervencoes; j++) {
        for (int k = 0; k < nAvarias; k++) {
            if (strcmp(intervencoes[j].codIntervencao, avarias[k].codRegisto) == 0) {
                for (int i = 0; i < nPontos; i++) {
                    if (avarias[k].idPontoIp == pontosIp[i].id) {
                        custoTotalReparacoes += intervencoes[j].custoIntervencao;
                    }
                }
            }
        }
    }
    return custoTotalReparacoes;
}
