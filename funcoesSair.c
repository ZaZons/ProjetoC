#include <stdio.h>
#include <stdlib.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesInformacao.h"
#include "funcoesSair.h"

void sair(void)
{
    char opcao;

    printf("\nDeseja guardar os dados antes de sair? [1 - Sim] [0 - Nao]");

    do{
        opcao = lerInt(0, 1);

        if(opcao != 1 && opcao != 0) {
            printf("\nOpcao Invalida");
        }

    }while(opcao != 1 && opcao != 0);

    if(opcao == 1) {

        gravarFicheiro(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes, -1);
    }

    printf("\nDeseja executar os dados gravados quando voltar a ser iniciado o programa?");

    do{
        opcao = lerInt(0, 1);

        if(opcao != 1 && opcao != 0) {
            printf("\nOpcao Invalida");
        }
    }while(opcao != 1 && opcao != 0);

    if(opcao == 1) {

    }
}
