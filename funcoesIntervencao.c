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
    int min, max, i, idIp, validacaoIp;
    char codAvaria[MAX_CODIGO_AVARIA] = "NULL";
    int idIp = 0;

    do
    {
        min=0
        max=50;
        printf("IP sujeito a intervenção: ");
        idIp = lerInt(min, max);

        validacaoIp = procuraPontoIp(pontosIp, quantidadePontos, idIp);

        if(validacaoIp == -1)
        {
            printf("Ponto IP nao encontrado");
        }
    }while(validacaoIp == -1);

    for(i=0; i<quantidadeAvarias; i++)
    {
        if(avarias[i].idPontosIp == idIP)
        {
            strcpy(avarias[i].codRegisto, codAvaria);
            quantidadeAvarias = i;
        }
    }
    if(strcmp(codAvaria, "NULL") == 1)
    {
        printf("Registo de avaria inexistente");
    }
    else{
        novaIntervencao.dataIntervencao = lerData();
        lerString(novaIntervencao.descricaoIntervencao, 150);

        min= 0.1;
        max= 2000;
        novaIntervencao.custoIntervencao = lerFloat(min,max);

        min=0;
        max=1;
        printf("Efetuada substituição de Luminaria? ");
        novaIntervencao.substituicaoLuminaria = lerInt(min, max);

        printf("O Ponto IP ficou operacional? [0 - Não] [1 - Sim]")
        novaIntervencao.operacional = lerInt(min, max);

        pontosIp.estadoFuncionamento = novaIntervencao.operacional;



    /**do
    {
        min = 1;
        max = 9999;
        printf("\nID do IP sujeito a intervencao: ");
        ID = lerInt(min, max);
        pos = procuraPontoIp(pontosIP, quantidadePontos, ID) //falta verificar se tem avaria
    }while(pos != -1 && /* verificacao de ter avaria */);

    /*novaIntervencao.ID = ID;

    novaIntervencao.dataIntervencao = lerData();

    lerString(novaIntervencao.descricaoIntervencao, 150);

    min= 0.1;
    max= 2000;
    novaIntervencao.custoIntervencao = lerFloat(min,max);

    printf("Efetuada substituição de Luminaria? ");*/




}
