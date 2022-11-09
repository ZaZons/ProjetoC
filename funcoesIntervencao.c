#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"

int validacaoIntervencao(int n1, int n2) {
    int valor = 0;

    if(n1 == n2) {
        valor = 1;
    } else {
        valor = 0;
    }

    return valor;
}

void obterDadosIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias) {
    tipoIntervencao novaIntervencao;
    int validacaoIp;
    int idIp;
    int avariaExiste = 0;

    do {
        printf("\nInsira o codigo do IP sujeito a intervencao: ");
        idIp = lerInt(MIN_IP_ID, MAX_IP_ID);

        validacaoIp = procuraPontoIp(pontosIp, n, idIp);

        if(validacaoIp == -1) {
            printf("\nERRO - Ponto IP nao encontrado");
        } else {
            if (pontosIp[validacaoIp].estadoFuncionamento == 1) {
                printf("\nO ponto selecionado nao necessita de intervencao.");
            } else {
                for(int i = 0; i < nAvarias; i++) {
                    if(avarias[i].idPontoIp == idIp) {
                        strcpy(novaIntervencao.codIntervencao, avarias[i].codRegisto);
                        avariaExiste = 1;
                    }
                }

                if(avariaExiste == 0) {
                    printf("\nERRO - Registo de avaria inexistente");
                } else {
                    printf("Insira a data e hora da intervencao: ");
                    novaIntervencao.dataIntervencao = lerData(MIN_ANO, MAX_ANO);

                    strcpy(novaIntervencao.cpe, pontosIp[validacaoIp].cpe);

                    printf("Insira a descricao da intervencao: ");
                    lerString(novaIntervencao.descricaoIntervencao, MAX_DESCRICAO_INTERVENCAO);

                    printf("Insira o custo da intervencao: ");
                    novaIntervencao.custoIntervencao = lerFloat(MIN_CUSTO, MAX_CUSTO);

                    int min=0;
                    int max=1;
                    printf("\nFoi efetuada substituicao de Luminaria? (0 - Nao / 1 - Sim): ");
                    novaIntervencao.substituicaoLuminaria = lerInt(min, max);

                    printf("\nO Ponto IP ficou operacional? (0 - Nao / 1 - Sim): ");
                    novaIntervencao.operacional = lerInt(min, max);

                    pontosIp[validacaoIp].estadoFuncionamento = novaIntervencao.operacional; // alterar o estado de funcionamento no pontosIp
                }
            }
        }
    } while (validacaoIp == -1);
}

float custoTotalIntervencoes(int id, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    float custoTotalReparacoes = 0.0;

    for (int i = 0; i < nAvarias; i++) {
        if (avarias[i].idPontoIp == id) {
            for (int j = 0; j < nIntervencoes; j++) {
                if (strcmp(intervencoes[j].codIntervencao, avarias[i].codRegisto) == 0) {
                    custoTotalReparacoes += intervencoes[j].custoIntervencao;
                }
            }
        }
    }

    return custoTotalReparacoes;
}
