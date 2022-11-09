#include <stdio.h>
#include <stdlib.h>
#include "funcoesLeitura.h"
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

    int j;
    int id=-1;
    int contador = 0;
    int aux = 0;
    int idaux = -1;
    int idPonto;
    for(i = 0; i < nAvarias; i++)
    {
        id = avaria[i].idPontoIp;
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

    novadata = lerdata();

    for(i=0; i<nAvarias;i++)
    {
        if(avarias[i].dataAvaria.ano <= novadata.ano){
            if(avarias[i].dataAvaria.mes <= novadata.mes){
                if(avarias[i].dataAvaria.dia < novadata.dia)
                    contadorMenorData++;
            }
        }
    }
    printf("\nNumero de avarias até %d-%d-%d: %d"novadata.dia, novaData.mes, novaData.ano, contadorMenorData);



    int contadorSubstituicao = 0;
    int auxSubstituicao = 0;
    int idSubtituicao = -1;
    int auxIdSubstituicao = -1;


    for(i=0; i<nPontos; i++)
    {
        idSubtituicao = pontosIp.id;

        for(j=0; j<nIntervencoes; j++)
        {
            if(intervencoes[i].substituicaoLuminaria == 1){
            contadorNumSubstituicoes++;
            }
            if(contadorSubstituicao > auxSubstituicao){
                auxSubstituicao = contadorSubstituicao;
                auxIdSubstituicao = idSubtituicao;
            }
        }
    }
    printf("Ponto IP com maior numero de substituicao de luminárias: %d", auxIdSubstituicao);

    tipoData dataConsecutiva;
    int contadorDiasConsecutivos = 0;

    for(i=0; i<nPontos; i++)
    {
        id = pontosIp.id

        for(j=0; j<nAvarias; j++)
        {
            if(avarias[j].idPontoIp == id){
                dataConsecutiva.ano = avarias[j].dataAvaria.ano
                dataConsecutiva.mes = avarias[j].dataAvaria.mes
                dataConsecutiva.dia = avarias[j].dataAvaria.dia

                dataConsecutiva.ano +=10;
                dataConsecutiva.mes +=10;
                dataConsecutiva.dia +=10;

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
}
