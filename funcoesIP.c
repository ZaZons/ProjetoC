#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"

int novoPontoIp(tipoIp pontosIp[], int n) {
    if (n >= MAX_IP) {
        printf("Numero maximo de pontos IP atingido.\n");
    } else {
        pontosIp[n] = lerDadosPontoIp(pontosIp, n);
        n++;
    }

    return n;
}

tipoIp lerDadosPontoIp(tipoIp pontosIp[], int n) {
    tipoIp novoPonto;
    int min;
    int max;

    // Numero de identificacao
    int id;
    int verificacao;
    do {
        printf("Insira o numero do novo ponto: ");
        id = lerInt(MIN_IP_ID, MAX_IP_ID);

        verificacao = procuraPontoIp(pontosIp, n, id);

        if (verificacao != -1) {
            printf("\nERRO - Posto ja existente!");
        }
    } while (verificacao != -1);
    novoPonto.id = id;

    // CPE (Codigo de Ponto de Entrega)
    int tamanhoCpe;
    do {
        printf("\nInsira o CPE (Codigo de Ponto de Entrega) do novo ponto: ");
        lerString(novoPonto.cpe, MAX_CPE);

        tamanhoCpe = strlen(novoPonto.cpe);

        if (tamanhoCpe != MAX_CPE) {
            printf("ERRO - O CPE tem %d digitos!", MAX_CPE);
        }
    } while (tamanhoCpe != MAX_CPE);

    // Potencia
    int potencia;
    int potencia1 = 33;
    int potencia2 = 50;
    int potencia3 = 100;
    min = 1;
    max = 3;
    printf("\nInsira a potencia da luminaria do ponto (1 - %dW, 2 - %dW, 3 - %dW): ", potencia1, potencia2, potencia3);
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
    // novoPonto.potencia = potencia;

    // Estado de funcionamento
    int estadoFuncionamento;
    min = 0;
    max = 1;
    printf("\nInsira o estado de funcionamento do ponto (0 - Avariado / 1 - Funcional): ");
    estadoFuncionamento = lerInt(min, max);
    novoPonto.estadoFuncionamento = estadoFuncionamento;

    // Tipo de tecnologia
    int intTipo;
    min = 1;
    max = 3;
    printf("\nInsira o estado de funcionamento do ponto (1 - Vapor de mercurio / 2 - Vapor de sodio / 3 - LED): ");
    intTipo = lerEscolhaMultipla(min, max);

    switch (intTipo) {
        case 1:
            strcpy("Vapor de mercurio", novoPonto.tipoTecnologia);
            break;
        case 2:
            strcpy("Vapor de sodio", novoPonto.tipoTecnologia);
            break;
        case 3:
            strcpy("LED", novoPonto.tipoTecnologia);
            break;
    }

    return novoPonto;
}

int procuraPontoIp(tipoIp pontosIp[], int n, int id) {
    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (pontosIp[i].id == id) {
            pos = i;
        }
    }

    return pos;
}

int calcularPontosLed(tipoIp pontosIp[], int n) {
    char tecnologia[MAX_TECNOLOGIA] = "LED";
    int nPontos = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(pontosIp[i].tipoTecnologia, tecnologia) == 0) {
            nPontos++;
        }
    }

    return nPontos;
}
