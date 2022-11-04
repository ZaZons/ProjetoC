#include <stdio.h>
#include <stdlib.h>
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"

void mostrarListagem(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    printf("\n");
    for (int i = 0; i < nPontos; i++) { 
        printf("\nPonto IP numero %d: {", i + 1);
        printf("\n\tNumero de identificacao: %d", pontosIp[i].id);
        printf("\n\tCodigo de Ponto de Entrega: %s", pontosIp[i].cpe);
        printf("\n\tPotencia da luminaria (Watts): %d", pontosIp[i].potencia);
        printf("\n\tEstado de funcionamento: %s", pontosIp[i].estadoFuncionamento);
        printf("\n\tTipo de tecnologia: %s", pontosIp[i].tipoTecnologia);

        int quantidadeAvarias = 0;
        for (int j = 0; j < nAvarias; j++) {
            if (avarias[j].idPontoIp == pontosIp[i].id) {
                quantidadeAvarias++;
            }
        }

        float custoTotalReparacoes = 0;
        for (int j = 0; j < nIntervencoes; j++) {
            for (int k = 0; k < nAvarias; k++) {
                if (intervencoes[j].ID == avarias[k].codRegisto) {
                    if (avarias[k].idPontoIp == pontosIp[i].id) {
                        custoTotalReparacoes += intervencoes[j].custoIntervencao;
                    } 
                }
            }
        }

        printf("\n\tQuantidade total de avarias: %d", quantidadeAvarias);
        printf("\n\tCusto total das reparacoes: %.2f", custoTotalReparacoes);
        printf("\n}\n");
    }
}
