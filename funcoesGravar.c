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
    FILE* saveFile = fopen("parque.dat", "wb");

    if (saveFile == 0) {
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
    FILE* abrirAoIniciarFile = fopen("abrirAoIniciar.dat", "wb");

    if (abrirAoIniciarFile == 0) {
        printf("\nErro ao abrir o ficheiro");
    } else {
        fwrite(&abrirAoIniciar, sizeof(int), 1, abrirAoIniciarFile);
        fclose(abrirAoIniciarFile);

        printf("\nDados guardados com sucesso.");
    }
}

void lerFicheiro(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int *nAvarias, tipoIntervencao intervencoes[], int *nIntervencoes) {
    FILE* saveFile = fopen("parque.dat", "wb");

    if (saveFile == 0) {
        printf("\nErro ao abrir o ficheiro\n");
    } else {
        fwrite(pontosIp, sizeof(tipoIp), MAX_IP, saveFile);
        fwrite(nPontos, sizeof(int), 1, saveFile);
        fwrite(avarias, sizeof(tipoAvaria), MAX_AVARIAS, saveFile);
        fwrite(nAvarias, sizeof(int), 1, saveFile);
        fwrite(intervencoes, sizeof(tipoIntervencao), MAX_INTERVENCOES, saveFile);
        fwrite(nIntervencoes, sizeof(int), 1, saveFile);
        fclose(saveFile);
    }
}

int lerAbrirAoIniciar() {
    FILE* abrirAoIniciarFile = fopen("abrirAoIniciar.dat", "rb");
    int abrirAoIniciar = 0;

    if (abrirAoIniciarFile == 0) {
        printf("\nErro ao abrir o ficheiro");
    } else {
        fread(&abrirAoIniciar, sizeof(int), 1, abrirAoIniciarFile);
        fclose(abrirAoIniciarFile);
    }

    return abrirAoIniciar;
}

