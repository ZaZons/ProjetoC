#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"

int registarAvaria(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int nAvarias, int associada) {
    if (nAvarias >= MAX_AVARIAS) {
        printf("\nERRO - Numero maximo de avarias atingido.");

        if (associada != 0) {
            printf(" Impossivel introduzir um ponto IP avariado.");
            pontosIp[*nPontos].id = 0;
            (*nPontos)--;
        }
    } else {
        int numPontos = *nPontos;
        if (numPontos == 0) {
            printf("\nERRO - Para registar avarias precisa de adicionar pontos antes.");
        } else {
            int nPontosAvariados = 0;

            if (associada != 0) {
                printf("\nO ponto IP introduzido nao esta operacional. Registe a avaria associada: ");
            } else {
                for (int i = 0; i < numPontos; i++) {
                    if (pontosIp[i].estadoFuncionamento == 0) {
                        nPontosAvariados++;
                    }
                }
            }

            if (nPontosAvariados == numPontos) {
                printf("\nERRO - Todos os pontos IP estao avariados, impossivel registar avarias ate estes serem reparados.");
            } else {
                avarias[nAvarias] = lerDadosAvaria(pontosIp, numPontos, avarias, nAvarias, associada);
                nAvarias++;
            }
        }
    }

    return nAvarias;
}

tipoAvaria lerDadosAvaria(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, int associada) {
    tipoAvaria novaAvaria;
    int min;
    int max;

    printf("\n");

    // Codigo de registo
    char codRegisto[MAX_CODIGO_AVARIA];
    int verificacao;
    do {
        printf("Insira o codigo de registo da avaria: ");
        lerString(codRegisto, MAX_CODIGO_AVARIA);

        verificacao = procuraAvaria(avarias, nAvarias, codRegisto);

        if (verificacao != -1) {
            printf("\nERRO - Avaria ja registada!\n\n");
        }
    } while (verificacao != -1);
    strcpy(novaAvaria.codRegisto, codRegisto);

    // Numero de identificacao do ponto IP avariado
    if (associada == 0) {
        novaAvaria.idPontoIp = lerIdPontoIp(pontosIp, nPontos);
    } else {
        novaAvaria.idPontoIp = associada;
    }

    // Meio de comunicacao
    int intMeio;
    min = 1;
    max = 4;
    printf("Insira o meio de comunicacao da avaria (1 - %s / 2 - %s / 3 - %s / 4 - %s): ", COMUNICACAO_1, COMUNICACAO_2, COMUNICACAO_3, COMUNICACAO_4);
    intMeio = lerInt(min, max);

    switch (intMeio) {
        case 1:
            strcpy(novaAvaria.meioComunicacao, COMUNICACAO_1);
            break;
        case 2:
            strcpy(novaAvaria.meioComunicacao, COMUNICACAO_2);
            break;
        case 3:
            strcpy(novaAvaria.meioComunicacao, COMUNICACAO_3);
            break;
        case 4:
            strcpy(novaAvaria.meioComunicacao, COMUNICACAO_4);
            break;
    }

    // Data e hora da avaria
    printf("Insira a data e hora da avaria:");
    novaAvaria.dataAvaria = lerData();

    // Descricao da avaria
    printf("Insira uma breve descricao da avaria do ponto IP: ");
    lerString(novaAvaria.descricao, MAX_DESCRICAO);

    return novaAvaria;
}

int lerIdPontoIp(tipoIp pontosIp[], int nPontos) {
    int idPontoIp;
    int verificacao;
    do {
        printf("Insira o numero de identificacao do ponto IP avariado: ");
        idPontoIp = lerInt(MIN_IP_ID, MAX_IP_ID);

        verificacao = procuraPontoIp(pontosIp, nPontos, idPontoIp);

        if (verificacao == -1) {
            printf("\nERRO - Ponto IP nao existente\n\n");
        } else {
            for (int i = 0; i < nPontos; i++) {
                if (pontosIp[i].id == idPontoIp) {
                    if (pontosIp[i].estadoFuncionamento == 0) {
                        printf("\nERRO - Este ponto ja se encontra avariado e registado como tal\n\n");
                        verificacao = -1;
                    } else {
                        pontosIp[i].estadoFuncionamento = 0;
                    }
                }
            }
        }
    } while (verificacao == -1);

    return idPontoIp;
}

int procuraAvaria(tipoAvaria avarias[], int nAvarias, char codRegisto[]) {
    int pos = -1;

    for (int i = 0; i < nAvarias; i++) {
        if (strcmp(avarias[i].codRegisto, codRegisto) == 0) {
            pos = i;
        }
    }

    return pos;
}

int calcularQuantidadeAvarias(tipoAvaria avarias[], int nAvarias, int idPontoIp) {
    int quantidadeAvarias = 0;
    for (int i = 0; i < nAvarias; i++) {
        if (avarias[i].idPontoIp == idPontoIp) {
            quantidadeAvarias++;
        }
    }

    return quantidadeAvarias;
}
