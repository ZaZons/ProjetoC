#include <stdio.h>
#include <stdlib.h>
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"

void mostrarListagem(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, /* tipoIntervencao intervencoes[] */, int nIntervencoes) {
    mostrarPontosIp(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes);
    mostrarPontosLed(pontosIp, nPontos);

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

void mostrarPontosIp(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, /* tipoIntervencao intervencoes[] */, int nIntervencoes) {
    printf("\n");
    printf("\nPontos IP: {")
    for (int i = 0; i < nPontos; i++) {
        int quantidadeAvarias = calcularQuantidadeAvarias(avarias, nAvarias, pontosIp[i].id);

        printf("\n\tPonto IP numero %d: {", i + 1);
        printf("\n\t\tNumero de identificacao: %d", pontosIp[i].id);
        printf("\n\t\tCodigo de Ponto de Entrega: %s", pontosIp[i].cpe);
        printf("\n\t\tPotencia da luminaria (Watts): %d", pontosIp[i].potencia);
        printf("\n\t\tEstado de funcionamento: %s", pontosIp[i].estadoFuncionamento);
        printf("\n\t\tTipo de tecnologia: %s", pontosIp[i].tipoTecnologia);
        printf("\n\t\tQuantidade total de avarias: %d", quantidadeAvarias);

        // float custoTotalReparacoes = 0;
        // for (int j = 0; j < nIntervencoes; j++) {
        //     for (int k = 0; k < nAvarias; k++) {
        //         if (intervencoes[j].ID == avarias[k].codRegisto) {
        //             if (avarias[k].idPontoIp == pontosIp[i].id) {
        //                 custoTotalReparacoes += intervencoes[j].custoIntervencao;
        //             } 
        //         }
        //     }
        // }

        // printf("\n\t\tCusto total das reparacoes: %.2f", custoTotalReparacoes);
        printf("\n\t}");
    }
    printf("\n}\n");
}

void mostrarPontosLed(pontosIp, nPontos) {
    char tecnologia[MAX_TECNOLOGIA] = "LED"; 
    printf("\nPontos IP com luminarias LED: {");
    for (int i = 0; i < nPontos; i++) {
        if (strcmp(pontosIp[i].tipoTecnologia, tecnologia) == 0) {
            printf("\n%d", pontosIp[i].id);
        }
    }
    printf("\n}\n");
}

