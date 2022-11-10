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
int menu(int nPontos, int nAvarias, int avariasResolvidas, float percLed);
void sair(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

int main() {
    tipoIp pontosIp[MAX_IP];
    tipoAvaria avarias[MAX_AVARIAS];
    tipoIntervencao intervencoes[MAX_INTERVENCOES];

    int nPontos = 0;
    int nAvarias = 0;
    int nIntervencoes = 0;
    int avariasResolvidas = 0;
    float percLed;

    int abrirAoIniciar = lerAbrirAoIniciar();

    if (abrirAoIniciar == 1) {
        lerFicheiro(pontosIp, &nPontos, avarias, &nAvarias, intervencoes, &nIntervencoes);
    }

    int opcao;
    do {
        percTecnologia(pontosIp, nPontos, TECNOLOGIA_LED, &percLed);
        avariasResolvidas = calcularAvariasResolvidas(intervencoes, nIntervencoes);

        opcao = menu(nPontos, nAvarias, avariasResolvidas, percLed);
        switch (opcao) {
        case 1:
            nPontos = novoPontoIp(pontosIp, nPontos);

            if (pontosIp[nPontos - 1].estadoFuncionamento == 0)
            {
                nAvarias = registarAvaria(pontosIp, &nPontos, avarias, nAvarias, pontosIp[nPontos - 1].id);
            }
            break;
        case 2:
            nAvarias = registarAvaria(pontosIp, &nPontos, avarias, nAvarias, 0);
            break;
        case 3:
            nIntervencoes = registarIntervencao(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes, avariasResolvidas);
            break;
        case 4:
            mostrarListagem(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes);
            break;
        case 5:
            informacoes(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes);
            break;
        case 6:
            gravarFicheiro(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes, -1);
            break;
        case 0:
            sair(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes);
            break;
        }
    } while (opcao != 0);

    return 0;
}

int menu(int nPontos, int nAvarias, int avariasResolvidas, float percLed) {
    int opcao = 0;

    printf("\t\n\nGestao de Pontos de Iluminacao Publica(IP)");
    printf("\nTotal de pontos IP: %d\tPontos IP avariados: %d", nPontos, (nAvarias - avariasResolvidas));
    printf("\nAvarias resolvidas: %d\tTecnologia LED (%%): %.2f", avariasResolvidas, percLed * 100);
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

void sair(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    int opcao;

    printf("\nDeseja guardar os dados antes de sair? (1 - Sim / 0 - Nao) ");
    opcao = lerInt(0, 1);

    if (opcao == 1)
    {
        printf("\nDeseja carregar os dados gravados quando voltar a iniciar o programa?");
        opcao = lerInt(0, 1);

        gravarFicheiro(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes, opcao);
    }

    printf("Adeus!!!");
}
