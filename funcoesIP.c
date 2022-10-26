#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesIP.h"
#include "funcoesLeitura.h"

int novoPontoIp(tipoIp pontosIp[], int n) {
    if (n >= MAX_IP) {
        printf("Numero maximo de pontos IP atingido.\n");
    } else {
        pontosIp[n] = lerDadosPontoIp(pontosIp, n);
        n++;
    }
}

tipoIp lerDadosPontoIp(tipoIp pontosIp[], int n) {
    tipoIp novoPonto;
    int min;
    int max;

    // Número de identificação
    int id;
    int verificacao;
    do {
        min = 1;
        max = 9999;
        printf("Insira o numero do novo ponto: ");
        id = lerInt(min, max);

        verificacao = procuraPontoIp(pontosIp, n, id);

        if (verificacao != -1) {
            printf("\nERRO - Posto já existente!");
        }
    } while (verificacao != -1);
    novoPonto.id = id;

    // CPE (Código de Ponto de Entrega)
    char cpe[MAX_CPE];
    int tamanhoCpe;
    do {
        printf("\nInsira o CPE (Código de Ponto de Entrega) do novo ponto: ");
        lerString(cpe, MAX_CPE);

        tamanhoCpe = strlen(cpe);

        if (tamanhoCpe != MAX_CPE) {
            printf("ERRO - O CPE tem %d digitos!", MAX_CPE);
        }
    } while (tamanhoCpe != MAX_CPE);
    strcpy(novoPonto.cpe, cpe);
    novoPonto.cpe[strlen(novoPonto.cpe) - 1] = '\0';

    // Potência
    int potencia;
    int limite1 = 33;
    int limite2 = 50;
    int limite3 = 100;
    printf("\nInsira a potencia da luminária do ponto (%d, %d, %d): ", limite1, limite2, limite3);
    potencia = lerIntExato(limite1, limite2, limite3);
    novoPonto.potencia = potencia;

    // Estado de funcionamento
    int estadoFuncionamento;
    min = 0;
    max = 1;
    printf("\nInsira o estado de funcionamento do ponto (0 - Avariado / 1 - Funcional): ");
    estadoFuncionamento = lerInt(min, max);
    novoPonto.estadoFuncionamento = estadoFuncionamento;

    // Tipo de tecnologia
    char tipoTecnologia[MAX_TECNOLOGIA];
    int intTipo;
    min = 1;
    max = 3;
    printf("\nInsira o estado de funcionamento do ponto (1 - Vapor de mercúrio / 2 - Vapor de sódio / 3 - LED): ");
    intTipo = lerInt(min, max);

    switch (intTipo) {
        case 1:
            strcpy("Vapor de mercurio", tipoTecnologia);
            break;
        case 2:
            strcpy("Vapor de sodio", tipoTecnologia);
            break;
        case 3:
            strcpy("LED", tipoTecnologia);
            break;
    }

    strcpy(novoPonto.tipoTecnologia, tipoTecnologia);
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
