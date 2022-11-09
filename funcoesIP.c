#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"

int novoPontoIp(tipoIp pontosIp[], int nPontos) {
    if (nPontos >= MAX_IP) {
        printf("Numero maximo de pontos IP atingido.\n");
    } else {
        pontosIp[nPontos] = lerDadosPontoIp(pontosIp, nPontos);
        nPontos++;
    }

    return nPontos;
}

tipoIp lerDadosPontoIp(tipoIp pontosIp[], int nPontos) {
    tipoIp novoPonto;
    int min;
    int max;

    printf("\n");

    // Numero de identificacao
    int id;
    int verificacao;
    do {
        printf("Insira o numero do novo ponto: ");
        id = lerInt(MIN_IP_ID, MAX_IP_ID);

        verificacao = procuraPontoIp(pontosIp, nPontos, id);

        if (verificacao != -1) {
            printf("\nERRO - Posto ja existente!\n\n");
        }
    } while (verificacao != -1);
    novoPonto.id = id;

    // CPE (Codigo de Ponto de Entrega)
    int tamanhoCpe;
    do {
        printf("Insira o CPE (Codigo de Ponto de Entrega) do novo ponto: ");
        lerString(novoPonto.cpe, MAX_CPE);

        tamanhoCpe = strlen(novoPonto.cpe);

        if (tamanhoCpe < MAX_CPE) {
            printf("\nERRO - O CPE tem de ter obrigatoriamente %d digitos!\n\n", MAX_CPE);
        }
    } while (tamanhoCpe != MAX_CPE);

    // Potencia
    int potencia;
    int potencia1 = 33;
    int potencia2 = 50;
    int potencia3 = 100;
    min = 1;
    max = 3;
    printf("Insira a potencia da luminaria do ponto (1 - %dW, 2 - %dW, 3 - %dW): ", potencia1, potencia2, potencia3);
    potencia = lerEscolhaMultipla(min, max);

    switch (potencia) {
        case 1:
            novoPonto.potencia = potencia1;
            break;
        case 2:
            novoPonto.potencia = potencia2;
            break;
        case 3:
            novoPonto.potencia = potencia3;
            break;
    }

    // Estado de funcionamento
    int estadoFuncionamento;
    min = 0;
    max = 1;
    printf("Insira o estado de funcionamento do ponto (0 - Avariado / 1 - Funcional): ");
    estadoFuncionamento = lerInt(min, max);
    novoPonto.estadoFuncionamento = estadoFuncionamento;

    // Tipo de tecnologia
    int intTipo;
    min = 1;
    max = 3;
    printf("Insira o tipo de luminaria do ponto (1 - Vapor de mercurio / 2 - Vapor de sodio / 3 - LED): ");
    intTipo = lerEscolhaMultipla(min, max);

    switch (intTipo) {
        case 1:
            strcpy(novoPonto.tipoTecnologia, "Vapor de mercurio");
            break;
        case 2:
            strcpy(novoPonto.tipoTecnologia, "Vapor de sodio");
            break;
        case 3:
            strcpy(novoPonto.tipoTecnologia, "LED");
            break;
    }

    return novoPonto;
}

int procuraPontoIp(tipoIp pontosIp[], int nPontos, int id) {
    int pos = -1;

    for (int i = 0; i < nPontos; i++) {
        if (pontosIp[i].id == id) {
            pos = i;
        }
    }

    return pos;
}

int calcularPontosLed(tipoIp pontosIp[], int nPontos) {
    char tecnologia[MAX_TECNOLOGIA] = "LED";
    int nLed = 0;

    for (int i = 0; i < nPontos; i++) {
        if (strcmp(pontosIp[i].tipoTecnologia, tecnologia) == 0) {
            nLed++;
        }
    }

    return nLed;
}
