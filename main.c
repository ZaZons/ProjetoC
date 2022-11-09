#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesInformacao.h"
#include "funcoesListagem.h"
#include "funcoesGravar.h"

#define MIN_ESCOLHA 0
#define MAX_ESCOLHA 6

/**
 * Importar valores para mostrar no menu
*/
int menu (int nPontos, int nAvarias, float percLed, int avariasR);

int main() {
    FILE* saveFile;

    tipoIp pontosIp[MAX_IP];
    tipoAvaria avarias[MAX_AVARIAS];
    tipoIntervencao intervencoes[MAX_INTERVENCOES];

    int nPontos = 0;
    int nAvarias = 0;
    int nIntervencoes = 0;
    int avariasR = 0;
    int nLed;
    float percLed;

    int abrirAoIniciar = lerAbrirAoIniciar();

    //if (abrirAoIniciar == 1) {
    //    lerFicheiro(pontosIp, &nPontos, avarias,  &nAvarias, intervencoes, &nIntervencoes);
    //}

    int opcao;
    do {
        percPontosLed(pontosIp, nPontos, &percLed);
        avariasResolvidas(intervencoes, nIntervencoes, &avariasR);

        opcao = menu(nPontos, nAvarias, percLed, avariasR);
        switch(opcao) {
            case 1:
                nPontos = novoPontoIp(pontosIp, nPontos);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                //informacoes();
                break;
            case 6:
                gravarFicheiro(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes, -1);
                break;
            case 0:
                //sair(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes);
                break;
        }

    } while (opcao != 0);

    return 0;
}


int menu (int nPontos, int nAvarias, float percLed, int avariasR) {
    int opcao = 0;

    printf("\n\tGestao de Pontos de Iluminacao Publica(IP)");
    printf("\nTotal de pontos IP: %d\tPontos IP avariados: %d", nPontos, nAvarias); //add totalpontos e pontos avariados
    printf("\nAvarias resolvidas: %d\tTecnologia LED (%%): %.1f", 0, 0.0); // add avarias resolvidas e tec led
    printf("\n   1. Novo ponto IP");
    printf("\n   2. Registo de Avaria");
    printf("\n   3. Registo de Intervencao");
    printf("\n   4. Listagens");
    printf("\n   5. Informacoes");
    printf("\n   6. Gravar");
    printf("\n   0. Sair");
    printf("\n\tSelecione a opcao: ");

    opcao = lerInt(MIN_ESCOLHA, MAX_ESCOLHA);

    return opcao;
}
