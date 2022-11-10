#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesGravar.h"

void gravarFicheiro(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int abrirAoIniciar) {
    FILE *saveFile = fopen("parque.dat", "wb");

    if (saveFile == NULL) {
        printf("\nErro ao abrir o ficheiro\n");
    } else {
        if (abrirAoIniciar != -1) {
            gravarAbrirAoIniciar(abrirAoIniciar);
        }
        fwrite(pontosIp, sizeof(tipoIp), MAX_IP, saveFile);
        fwrite(&nPontos, sizeof(int), 1, saveFile);
        fwrite(avarias, sizeof(tipoAvaria), MAX_AVARIAS, saveFile);
        fwrite(&nAvarias, sizeof(int), 1, saveFile);
        fwrite(intervencoes, sizeof(tipoIntervencao), MAX_INTERVENCOES, saveFile);
        fwrite(&nIntervencoes, sizeof(int), 1, saveFile);
        fclose(saveFile);

        printf("\nDados guardados com sucesso.");
    }
}

void gravarAbrirAoIniciar(int abrirAoIniciar) {
    FILE *abrirAoIniciarFile = fopen("abrirAoIniciar.dat", "wb");

    if (abrirAoIniciarFile == NULL) {
        printf("\nErro ao abrir o ficheiro");
    } else {
        fwrite(&abrirAoIniciar, sizeof(int), 1, abrirAoIniciarFile);
        fclose(abrirAoIniciarFile);

        printf("\nDados guardados com sucesso.");
    }
}

void lerFicheiro(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int *nAvarias, tipoIntervencao intervencoes[], int *nIntervencoes) {
    FILE *saveFile = fopen("parque.dat", "wb");

    if (saveFile == NULL) {
        printf("\nErro ao abrir o ficheiro");
    } else {
        fwrite(pontosIp, sizeof(tipoIp), MAX_IP, saveFile);
        fwrite(nPontos, sizeof(int), 1, saveFile);
        fwrite(avarias, sizeof(tipoAvaria), MAX_AVARIAS, saveFile);
        fwrite(nAvarias, sizeof(int), 1, saveFile);
        fwrite(intervencoes, sizeof(tipoIntervencao), MAX_INTERVENCOES, saveFile);
        fwrite(nIntervencoes, sizeof(int), 1, saveFile);
        fclose(saveFile);

        printf("Ficheiro lido com sucesso.");
    }
}

int lerAbrirAoIniciar() {
    FILE *abrirAoIniciarFile;
    int abrirAoIniciar;
    do {
        abrirAoIniciarFile = fopen("abrirAoIniciar.dat", "rb");

        if (abrirAoIniciarFile == NULL) {
            abrirAoIniciarFile = fopen("abrirAoIniciar.dat", "wb");
        } else {
            fread(&abrirAoIniciar, sizeof(int), 1, abrirAoIniciarFile);
        }
    } while (abrirAoIniciarFile != NULL);
    fclose(abrirAoIniciarFile);

    return abrirAoIniciar;
}

