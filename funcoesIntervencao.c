#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesIP.h"
#include "funcoesLeitura.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"

int validacaoIntervencao(int n1, int n2)
{
    int valor = 0;
    if(n1 == n2)
    {
        valor = 1;
    }
    else
    {
        valor = 0;
    }

    return valor;
}

void obterDadosIntervencao(tipoIP pontosIp[], int quantidadePontos){

    tipoIntervencao novaIntervencao[200];
    int i, idIp, validacaoIp;
    float  min, max;
    char codAvaria[MAX_CODIGO_AVARIA] = "NULL";
    int idIp = 0;

    do
    {
        min=0
        max=50;
        printf("\nIP sujeito a intervenção: ");
        idIp = lerInt(min, max);

        validacaoIp = procuraPontoIp(pontosIp, quantidadePontos, idIp);

        if(validacaoIp == -1)
        {
            printf("\nPonto IP nao encontrado");
        }
    }while(validacaoIp == -1);

    for(i=0; i<nAvarias; i++)
    {
        if(avarias[i].idPontosIp == idIP)
        {
            strcpy(avarias[i].codRegisto, codAvaria);
            quantidadeAvarias = i;
        }
    }
    if(strcmp(codAvaria, "NULL") == 1)
    {
        printf("\nRegisto de avaria inexistente");
    }
    else{

        strcpy(codAvaria, novaIntervencao.codIntervencao);
        novaIntervencao.dataIntervencao = lerData();
        strcpy(pontosIp.cpe, novaIntervencao.cpe); // check it
        lerString(novaIntervencao.descricaoIntervencao, 150);

        min= 0.01;
        max= 2000;
        novaIntervencao.custoIntervencao = lerFloat(min,max);

        min=0;
        max=1;
        printf("\nEfetuada substituição de Luminaria? [0 - Não] [1 - Sim]");
        novaIntervencao.substituicaoLuminaria = lerInt(min, max);

        printf("\nO Ponto IP ficou operacional? [0 - Não] [1 - Sim]")
        novaIntervencao.operacional = lerInt(min, max);

        pontosIp.estadoFuncionamento = novaIntervencao.operacional; // alterar o estado de funcionamento no pontosIp

}

float custoIntervencao(tipoIntervencao intervencoes, int n) //verificar se uso int n ou variavel
{
    int i;
    float custoTotal=0;

    for(i=0; i < n; i++)
    {
        custoTotal += intervencoes[i].custoIntervencao
    }

    return custoTotal;
}
