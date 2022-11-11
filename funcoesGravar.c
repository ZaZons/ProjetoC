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
    FILE *saveFile;
    saveFile = fopen("parque.dat", "wb");

    if (saveFile == 0) {
        printf("\nErro ao abrir o ficheiro");
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

        printf("Dados guardados com sucesso.");
    }
}

void gravarAbrirAoIniciar(int abrirAoIniciar) {
    FILE *abrirAoIniciarFile;
    abrirAoIniciarFile = fopen("abrirAoIniciar.dat", "wb");

    if (abrirAoIniciarFile == 0) {
        printf("\nErro ao abrir o ficheiro");
    } else {
        fwrite(&abrirAoIniciar, sizeof(int), 1, abrirAoIniciarFile);
        fclose(abrirAoIniciarFile);
    }
}

void lerFicheiro(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int *nAvarias, tipoIntervencao intervencoes[], int *nIntervencoes) {
    FILE *saveFile;
    saveFile = fopen("parque.dat", "rb");

    if (saveFile == 0) {
        printf("\nErro ao abrir o ficheiro");
    } else {
        fread(pontosIp, sizeof(tipoIp), MAX_IP, saveFile);
        fread(nPontos, sizeof(int), 1, saveFile);
        fread(avarias, sizeof(tipoAvaria), MAX_AVARIAS, saveFile);
        fread(nAvarias, sizeof(int), 1, saveFile);
        fread(intervencoes, sizeof(tipoIntervencao), MAX_INTERVENCOES, saveFile);
        fread(nIntervencoes, sizeof(int), 1, saveFile);
        fclose(saveFile);

        printf("Dados carregados com sucesso.");
    }
}

int lerAbrirAoIniciar() {
    FILE *abrirAoIniciarFile;
    int abrirAoIniciar;
    do {
        abrirAoIniciarFile = fopen("abrirAoIniciar.dat", "rb");

        if (abrirAoIniciarFile == 0) {
            abrirAoIniciarFile = fopen("abrirAoIniciar.dat", "wb");
        } else {
            fread(&abrirAoIniciar, sizeof(int), 1, abrirAoIniciarFile);
        }
    } while (abrirAoIniciarFile == 0);
    fclose(abrirAoIniciarFile);

    return abrirAoIniciar;
}

