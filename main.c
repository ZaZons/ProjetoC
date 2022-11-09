#include <stdio.h>
#include <stdlib.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesListagem.h"

/**
 * Importar valores para mostrar no menu
 * */
int menu ();

int main() {
    FILE* saveFile;

    tipoIp pontosIp[MAX_IP];
    int nPontos = 0;
    tipoAvaria avarias[MAX_AVARIAS];
    int nAvarias = 0;
    tipoIntervencao intervencoes[MAX_INTERVENCOES];
    int nIntervencoes = 0;

    int avariasResolvidas = 0;
    float percLED = 0;

    int opcao;
    do {

        percTecnologia(nLED, nPontos, &percLED); //
        avariasResolvidas(nAvarias, &avariasResolvidas);


        opcao = menu(nPontos, nAvarias);
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
                informacoes();
                break;
            case 6:
                saveFile = fopen("parque.dat", "wb");

                if (saveFile == 0) {
                    printf("Erro ao abrir o ficheiro\n");
                } else {
                    fwrite(pontosIp, sizeof(tipoIp), MAX_IP, saveFile);
                    fwrite(nPontos, sizeof(int), 1, saveFile);
                    fwrite(avarias, sizeof(tipoAvaria), MAX_AVARIAS, saveFile);
                    fwrite(nAvarias, sizeof(int), 1, saveFile);
                    fwrite(intervencoes, sizeof(tipoIntervencao), MAX_INTERVENCOES, saveFile);
                    fwrite(nIntervencoes, sizeof(int), 1, saveFile);
                    fclose(saveFile);

                    printf("\nDados guardados com sucesso.");
                }
                break;
        }

    } while (opcao != 0);

    return 0;
}


int menu (int nPontos, int nAvarias) {
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
    scanf(" %d", &opcao);
    limparBufferStdin();

    return opcao;
}
