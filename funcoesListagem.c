#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesListagem.h"

void mostrarListagem(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    mostrarPontosIp(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes);
    mostrarPontosLed(pontosIp, nPontos);
    mostrarAvarias(avarias, nAvarias);
    mostrarHistoricoAvarias(avarias, nAvarias);

}

void mostrarPontosIp(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    printf("\n");
    printf("\nPontos IP: {");
    for (int i = 0; i < nPontos; i++) {
        int quantidadeAvarias = calcularQuantidadeAvarias(avarias, nAvarias, pontosIp[i].id);
        float custoTotalReparacoes = custoTotalIntervencoes(pontosIp[i].id, avarias, nAvarias, intervencoes, nIntervencoes);

        printf("\n\tPonto IP numero %d: {", i + 1);
        printf("\n\t\tNumero de identificacao: %d", pontosIp[i].id);
        printf("\n\t\tCodigo de Ponto de Entrega: %s", pontosIp[i].cpe);
        printf("\n\t\tPotencia da luminaria (Watts): %d", pontosIp[i].potencia);
        printf("\n\t\tEstado de funcionamento: %d", pontosIp[i].estadoFuncionamento);
        printf("\n\t\tTipo de tecnologia: %s", pontosIp[i].tipoTecnologia);
        printf("\n\t\tQuantidade total de avarias: %d", quantidadeAvarias);
        printf("\n\t\tCusto total das reparacoes: %.2f", custoTotalReparacoes);
        printf("\n\t}");
    }
    printf("\n}\n");
}

void mostrarPontosLed(tipoIp pontosIp[], int nPontos) {
    printf("\nPontos IP com luminarias LED: {");
    for (int i = 0; i < nPontos; i++) {
        if (strcmp(pontosIp[i].tipoTecnologia, TECNOLOGIA_LED) == 0) {
            printf("\n\t%d", pontosIp[i].id);
        }
    }
    printf("\n}\n");
}

void mostrarAvarias(tipoAvaria avarias[], int nAvarias) {
    printf("\n");
    printf("\nAvarias: {");
    for (int i = 0; i < nAvarias; i++) {
        printf("\n\tAvaria %s: {", avarias[i].codRegisto);
        printf("\n\t\tPonto IP avariado: %d", avarias[i].idPontoIp);
        printf("\n\t\tMeio de comunicacao da avaria: %s", avarias[i].meioComunicacao);
        printf("\n\t\tData da avaria: %2d/%2d/%4d", avarias[i].dataAvaria.dia, avarias[i].dataAvaria.mes, avarias[i].dataAvaria.ano);
        printf("\n\t\tDescricao: %s", avarias[i].descricao);
        printf("\n\t}");
    }
    printf("\n}\n");
}

void mostrarHistoricoAvarias(tipoAvaria avarias[], int nAvarias) {
    int idPontoHistorico;
    int nAvariasFiltradas = 0;
    tipoAvaria avariasFiltradas[MAX_AVARIAS];
    printf("\nSelecione o ponto IP para mostrar o historico de avarias: ");
    idPontoHistorico = lerInt(MIN_IP_ID, MAX_IP_ID);

    for (int i = 0; i < nAvarias; i++) {
        if (avarias[i].idPontoIp == idPontoHistorico) {
            avariasFiltradas[nAvariasFiltradas] = avarias[i];
            nAvariasFiltradas++;
        }
    }
    mostrarAvarias(avariasFiltradas, nAvariasFiltradas);
}

void mostrarPontoPorAvaria(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    char codAvariaHistorico[MAX_CODIGO_AVARIA];
    tipoIp pontoPorAvaria[1];
    printf("Selecione o codigo da avaria para identificar o ponto IP: ");
    lerString(codAvariaHistorico, MAX_CODIGO_AVARIA);

    int pontoPos;
    for (int i = 0; i < nAvarias; i++) {
        if (avarias[i].codRegisto == codAvariaHistorico) {
            pontoPos = procuraPontoIp(pontosIp, nPontos, avarias[i].idPontoIp);
            pontoPorAvaria[0] = pontosIp[pontoPos];
        }
    }

    if (pontoPos == -1) {
        printf("\nNao existe nenhuma avaria com o codigo que inseriu.");
    } else {
        mostrarPontosIp(pontoPorAvaria, 1, avarias, nAvarias, intervencoes, nIntervencoes);
    }
}

