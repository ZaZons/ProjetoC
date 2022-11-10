#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"

int registarAvaria(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias) {
    if (nAvarias >= MAX_AVARIAS) {
        printf("\nERRO - Numero maximo de avarias atingido.\n\n");
    } else {
        if (nPontos == 0) {
            printf("\nERRO - Para registar avarias precisa de adicionar pontos antes\n\n");
        } else {
            avarias[nAvarias] = lerDadosAvaria(avarias, nAvarias, pontosIp, nPontos);
            nAvarias++;
        }
    }

    return nAvarias;
}

tipoAvaria lerDadosAvaria(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias) {
    tipoAvaria novaAvaria;
    int min;
    int max;

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
    int idPontoIp;
    do {
        printf("Insira o numero de identificacao do ponto IP avariado: ");
        idPontoIp = lerInt(MIN_IP_ID, MAX_IP_ID);

        verificacao = procuraPontoIp(pontosIp, nPontos, idPontoIp);

        if (verificacao == -1) {
            printf("\nERRO - Ponto IP nao existente\n\n");
        }
    } while (verificacao == -1);
    novaAvaria.idPontoIp = idPontoIp;

    // Meio de comunicacao
    int intMeio;
    min = 1;
    max = 4;
    printf("\nInsira o meio de comunicacao da avaria (1 - telefone, 2 - carta, 3 - email, 4 - portal)");
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
    printf("\nInsira a data e hora da avaria: ");
    novaAvaria.dataAvaria = lerData();

    // Breve descricao da avaria
    printf("\nInsira uma breve descricao da avaria do ponto IP");
    lerString(novaAvaria.descricao, MAX_DESCRICAO);

    return novaAvaria;
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
