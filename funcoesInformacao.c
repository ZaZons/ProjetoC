#include <stdio.h>
#include <stdlib.h>
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesInformacao.h"

void percTecnologia(int n, int nTotal, float *percN)
{

    *percN = ((float)n * 100)/nTotal
}

void avariasResolvidas(int nAvarias, int *avariasR)
{
    int i;

    for(i=0; i<nAvarias; i++)
    {
        if(intervencoes[i].estadoFuncionamento == 1)
        {
            *avariasR++;
        }
    }
}

void informacoes (int nPontos, tipoIp pontosIp, tipoIntervencao intervencoes, tipoAvaria avarias)
{
    int i, nMercurio=0, nSodio=0, nLED=0, custoTotalIntervencao=0, contador=0;
    float percMercurio=0, percSodio=0, percLED=0, mediaCustoIntervencao=0;

    for(i=0; i<nPontos; i++)
    {
        if(pontosIp[i].tipoTecnologia == 1){
            nVaporMercurio++;
        }else{
            if(pontosIp[i].tipoTecnologia == 2){
                nVaporSodio++;
            }else{
                nLED++;
            }
        }
    }
    percTecnologia( nMercurio, nPontos, &percMercurio);
    percTecnologia(nSodio, nPontos, &percSodio);
    percTecnologia(nLED, nPontos, &percLED);

    printf("\nPercentagens de Tecnologias de Luminária");
    printf("\n\tVapor de Mercurio: %.1f", percMercurio);
    printf("\n\tVapor de Sodio: %.1f", percSodio);
    printf("\n\t LED: %.1f", percLED);

    for(i=0; i<nIntervencoes; i++)
    {
        custoTotalIntervencao += intervencoes[i].custoIntervencao
    }

    mediaCustoIntervencao = (float)custoTotalIntervencao / nIntervencoes;
    printf("\n Custo média de Intervencoes: %.1f", mediaCustoIntervencao);

    int contador = 0;
    int aux = 0;
    int idaux = 0;
    int idPonto;
    for(int i = 0; i < navaria; i++)
    {
        id = avaria[i].pontoid
        for(int j = 0; j < npontos; i++)
        {
            if (pontosIp[j] == id){
                contador++
                }
            if (contador > aux){
                aux = contador
                idaux = id
                }
        }
    }
    printf("\nPonto Ip com maior com maior numero de avarias: %d", idaux);

    tipoData novaData;

    novadata = lerdata();

    for(i=0; i<nAvarias;)







}
