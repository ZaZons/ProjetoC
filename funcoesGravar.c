#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesGravar.h"

void gravarFicheiro(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int abrirAoIniciar) {
    saveFile = fopen("parque.dat", "wb");

    if (saveFile == 0) {
        printf("\nErro ao abrir o ficheiro\n");
    } else {
        if (gravarAbrirAoIniciar != -1) {
            gravarAbrirAoIniciar(abrirAoIniciar);
        }
        fwrite(pontosIp, sizeof(tipoIp), MAX_IP, saveFile);
        fwrite(nPontos, sizeof(int), 1, saveFile);
        fwrite(avarias, sizeof(tipoAvaria), MAX_AVARIAS, saveFile);
        fwrite(nAvarias, sizeof(int), 1, saveFile);
        fwrite(intervencoes, sizeof(tipoIntervencao), MAX_INTERVENCOES, saveFile);
        fwrite(nIntervencoes, sizeof(int), 1, saveFile);
        fclose(saveFile);

        printf("\nDados guardados com sucesso.");
    }
}

void gravarAbrirAoIniciar(int abrirAoIniciar) {
    saveFile = fopen("abrirAoIniciar.dat", "wb");
    if (saveFile == 0) {
        printf("\nErro ao abrir o ficheiro");
    } else {
        fwrite(abrirAoIniciar, sizeof(int), 1, savefile);
    }
}
