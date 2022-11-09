#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesInformacao.h"
#include "funcoesGravar.h"
#include "funcoesSair.h"

void sair(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    int opcao;

    printf("\nDeseja guardar os dados antes de sair? (1 - Sim / 0 - Nao) ");
    opcao = lerInt(0, 1);

    if (opcao == 1) {
        printf("\nDeseja carregar os dados gravados quando voltar a iniciar o programa?");
        opcao = lerInt(0, 1);

        gravarFicheiro(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes, opcao);
    }
}
