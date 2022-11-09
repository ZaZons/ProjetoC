#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesInformacao.h"

void percPontosLed(tipoIp pontosIp[], int nPontos, float *percLed) {
    *percLed = (float) calcularPontosLed(pontosIp, nPontos) / nPontos;
}

void avariasResolvidas(tipoIntervencao intervencoes[], int nIntervencoes, int *avariasR) {
    for(int i = 0; i < nIntervencoes; i++) {
        if(intervencoes[i].operacional == 1) {
            *avariasR++;
        }
    }
}

void informacoes (int nPontos, tipoIp pontosIp[], tipoIntervencao intervencoes[], int nIntervencoes, tipoAvaria avarias[], int nAvarias)
{
    int i, nMercurio=0, nSodio=0, nLED=0, custoTotalIntervencao=0;
    float percMercurio=0, percSodio=0, percLED=0, mediaCustoIntervencao=0;

    for(i=0; i<nPontos; i++)
    {
        if(strcmp(pontosIp[i].tipoTecnologia, "Vapor de mercurio") == 0){
            nMercurio++;
        }else{
            if(strcmp(pontosIp[i].tipoTecnologia, "Vapor de sodio") == 0){
                nSodio++;
            }else{
                nLED++;
            }
        }
    }

    percTecnologia(nMercurio, nPontos, &percMercurio);
    percTecnologia(nSodio, nPontos, &percSodio);
    percTecnologia(nLED, nPontos, &percLED);

    printf("\nPercentagens de Tecnologias de Lumin�ria");
    printf("\n\tVapor de Mercurio: %.1f", percMercurio);
    printf("\n\tVapor de Sodio: %.1f", percSodio);
    printf("\n\t LED: %.1f", percLED);

    for(i=0; i<nIntervencoes; i++)
    {
        custoTotalIntervencao += intervencoes[i].custoIntervencao;
    }

    mediaCustoIntervencao = (float)custoTotalIntervencao / nIntervencoes;
    printf("\nCusto m�dia de Intervencoes: %.1f", mediaCustoIntervencao);

    int j;
    int id=-1;
    int contador = 0;
    int aux = 0;
    int idaux = -1;
    int idPonto;
    for(i = 0; i < nAvarias; i++)
    {
        id = avarias[i].idPontoIp;
        for(j = 0; j < nPontos; i++)
        {
            if (pontosIp[j].id == id){
                contador++;
                }
            if (contador > aux){
                aux = contador;
                idaux = id;
                }
        }
    }
    printf("\nPonto Ip com maior com maior numero de avarias: %d", idaux);

    tipoData novaData;
    int contadorMenorData=0;

    novaData = lerData();

    for(i=0; i<nAvarias;i++)
    {
        if(avarias[i].dataAvaria.ano <= novaData.ano){
            if(avarias[i].dataAvaria.mes <= novaData.mes){
                if(avarias[i].dataAvaria.dia < novaData.dia)
                    contadorMenorData++;
            }
        }
    }
    printf("\nNumero de avarias at� %d-%d-%d: %d", novaData.dia, novaData.mes, novaData.ano, contadorMenorData);



    int contadorSubstituicao = 0;
    int auxSubstituicao = 0;
    int idSubtituicao = -1;
    int auxIdSubstituicao = -1;


    for(i=0; i<nPontos; i++)
    {
        idSubtituicao = pontosIp[i].id;

        for(j=0; j<nIntervencoes; j++)
        {
            if(intervencoes[i].substituicaoLuminaria == 1){
            contadorSubstituicao++;
            }
            if(contadorSubstituicao > auxSubstituicao){
                auxSubstituicao = contadorSubstituicao;
                auxIdSubstituicao = idSubtituicao;
            }
        }
    }
    printf("\nPonto IP com maior numero de substituicao de lumin�rias: %d", auxIdSubstituicao);

    tipoData dataConsecutiva;
    int contadorDiasConsecutivos = 0;

    for(i=0; i<nPontos; i++)
    {
        id = pontosIp[i].id;

        for(j=0; j<nAvarias; j++)
        {
            if(avarias[j].idPontoIp == id){
                dataConsecutiva.ano = avarias[j].dataAvaria.ano;
                dataConsecutiva.mes = avarias[j].dataAvaria.mes;
                dataConsecutiva.dia = avarias[j].dataAvaria.dia;

                soma10Dias(&dataConsecutiva);


                if(intervencoes[j].dataIntervencao.ano >= dataConsecutiva.ano){
                    if(intervencoes[j].dataIntervencao.mes >=dataConsecutiva.mes){
                        if(intervencoes[j].dataIntervencao.dia > dataConsecutiva.dia){
                            contadorDiasConsecutivos++;
                        }
                    }
                }
            }
        }
    }
    printf("\nNumero de Avarias n�o resolvidas durante 10 dias: %d", contadorDiasConsecutivos);
}

void soma10Dias(tipoData *dataConsecutiva) {
    int diasMes = 31;
    dataConsecutiva->dia +=10;

    if (dataConsecutiva->mes == 2) {
        if ((dataConsecutiva->ano % 4) != 0) {
            diasMes = 29;
        } else {
            diasMes = 28;
        }
    } else {
        switch(dataConsecutiva->mes) {
            case 4:
            case 6:
            case 9:
            case 11:
                diasMes = 30;
        }
    }

    if (dataConsecutiva->dia > diasMes) {
        dataConsecutiva->dia -= diasMes;
        dataConsecutiva->mes++;
    }

    if (dataConsecutiva->mes == 12) {
        dataConsecutiva->mes = 1;
        dataConsecutiva->ano++;
    }
}
