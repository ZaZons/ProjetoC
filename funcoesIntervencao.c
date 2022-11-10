#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"

int registarIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int nAvariasResolvidas) {
    if (nIntervencoes >= MAX_INTERVENCOES) {
        printf("\nERRO - Numero maximo de intervencoes atingido.");
    } else {
        if (nAvarias == 0) {
            printf("\nERRO - Para registar intervencoes precisa de ter avarias registadas.");
        } else {
            if (nAvariasResolvidas == nAvarias) {
                printf("\nERRO - Todas as avarias estao resolvidas.");
            } else {
                intervencoes[nIntervencoes] = lerDadosIntervencao(pontosIp, nPontos, avarias, nAvarias);
                nIntervencoes++;
            }
        }
    }

    return nIntervencoes;
}

tipoIntervencao lerDadosIntervencao(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias) {
    tipoIntervencao novaIntervencao;
    int validacaoIp;
    int idIp;
    int avariaExiste = -1;
    char cpe[MAX_CPE];

    do {
        printf("\nInsira o codigo do IP sujeito a intervencao: ");
        idIp = lerInt(MIN_IP_ID, MAX_IP_ID);

        validacaoIp = procuraPontoIp(pontosIp, nPontos, idIp);

        if(validacaoIp == -1) {
            printf("\nERRO - Ponto IP nao encontrado\n");
        } else {
            if (pontosIp[validacaoIp].estadoFuncionamento == 1) {
                printf("\nO ponto selecionado nao necessita de intervencao.");
            } else {
                for(int i = 0; i < nAvarias; i++) {
                    if(avarias[i].idPontoIp == idIp) {
                        strcpy(novaIntervencao.codIntervencao, avarias[i].codRegisto);
                        avariaExiste = i;
                    }
                }

                if(avariaExiste == -1) {
                    printf("\nERRO - Registo de avaria inexistente");
                } else {
                    int validacaoData = 0;
                    tipoData dataIntervencao;

                    do {
                        printf("Insira a data e hora da intervencao: ");
                        dataIntervencao = lerData(MIN_ANO, MAX_ANO);

                        validacaoData = validarData(avarias[avariaExiste].dataAvaria, dataIntervencao);

                        if (validacaoData != 1) {
                            printf("\nERRO - A intervencao tem de ser efetuada depois da avaria ser registada.\n\n");
                        }
                    } while (validacaoData != 1);
                    novaIntervencao.dataIntervencao = dataIntervencao;

                    strcpy(cpe, pontosIp[validacaoIp].cpe);

                    printf("\nInsira a descricao da intervencao: ");
                    lerString(novaIntervencao.descricaoIntervencao, MAX_DESCRICAO_INTERVENCAO);

                    printf("Insira o custo da intervencao: ");
                    novaIntervencao.custoIntervencao = lerFloat(MIN_CUSTO, MAX_CUSTO);

                    int min = 0;
                    int max = 1;
                    printf("Foi efetuada substituicao de Luminaria? (0 - Nao / 1 - Sim): ");
                    novaIntervencao.substituicaoLuminaria = lerInt(min, max);

                    if (novaIntervencao.substituicaoLuminaria == 1) {
                        int luminaria;
                        min = 1;
                        max = 3;
                        printf("Qual foi a luminaria substituida? (1 - %s / 2 - %s / 3 - %s): ", TECNOLOGIA_MERCURIO, TECNOLOGIA_SODIO, TECNOLOGIA_LED);
                        luminaria = lerInt(min, max);

                        switch (luminaria) {
                            case 1:
                                strcpy(pontosIp[validacaoIp].tipoTecnologia, TECNOLOGIA_MERCURIO);
                                break;
                            case 2:
                                strcpy(pontosIp[validacaoIp].tipoTecnologia, TECNOLOGIA_SODIO);
                                break;
                            case 3:
                                strcpy(pontosIp[validacaoIp].tipoTecnologia, TECNOLOGIA_LED);
                                break;
                        }
                    }

                    min = 0;
                    max = 1;
                    printf("O Ponto IP ficou operacional? (0 - Nao / 1 - Sim): ");
                    novaIntervencao.operacional = lerInt(min, max);

                    pontosIp[validacaoIp].estadoFuncionamento = novaIntervencao.operacional;
                    gravarLog(novaIntervencao, idIp);
                }
            }
        }
    } while (validacaoIp == -1);

    return novaIntervencao;
}

void gravarLog(tipoIntervencao novaIntervencao, int idIp) {
    FILE *ficheiroIntervencoes;
    ficheiroIntervencoes = fopen("intervencoes.txt", "w");

    if (ficheiroIntervencoes == NULL) {
        printf("\nErro ao abrir o ficheiro.");
    } else {
        printf("dentro do ficheiro");
        fprintf(ficheiroIntervencoes, "Intervencao #%s: {", novaIntervencao.codIntervencao);
        fprintf(ficheiroIntervencoes, "\n\tPonto #%d", idIp);
        fprintf(ficheiroIntervencoes, "\n\tData: %2d/%2d/%4d %2d:%2d", novaIntervencao.dataIntervencao.dia, novaIntervencao.dataIntervencao.mes, novaIntervencao.dataIntervencao.ano, novaIntervencao.dataIntervencao.hora, novaIntervencao.dataIntervencao.minuto);
        fprintf(ficheiroIntervencoes, "\n\tCusto da intervencao: %.2f", novaIntervencao.custoIntervencao);
        fprintf(ficheiroIntervencoes, "\n\tSubstituida luminaria: %d", novaIntervencao.substituicaoLuminaria);
        fprintf(ficheiroIntervencoes, "\n\tPonto ficou operacional: %d", novaIntervencao.operacional);
        fprintf(ficheiroIntervencoes, "\n}\n");
    }

    fclose(ficheiroIntervencoes);
}

float custoTotalIntervencoes(int id, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    float custoTotalReparacoes = 0.0;

    for (int i = 0; i < nAvarias; i++) {
        if (avarias[i].idPontoIp == id) {
            for (int j = 0; j < nIntervencoes; j++) {
                if (strcmp(intervencoes[j].codIntervencao, avarias[i].codRegisto) == 0) {
                    custoTotalReparacoes += intervencoes[j].custoIntervencao;
                }
            }
        }
    }

    return custoTotalReparacoes;
}
