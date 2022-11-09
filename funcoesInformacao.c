#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesLeitura.h"
#include "funcoesIP.h"
#include "funcoesAvaria.h"
#include "funcoesIntervencao.h"
#include "funcoesInformacao.h"

void percTecnologia(tipoIp pontosIp[], int nPontos, char tecnologia[], float *percTec) {
    *percTec = (float) calcularTecnologiaPontos(pontosIp, nPontos, tecnologia) / nPontos;
}

void calcularAvariasResolvidas(tipoIntervencao intervencoes[], int nIntervencoes, int *avariasR) {
    for(int i = 0; i < nIntervencoes; i++) {
        if (intervencoes[i].operacional == 1) {
            *avariasR++;
        }
    }
}

void informacoes (tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, ) {
    mostrarPontosIpTecnologia(pontosIp, nPontos);
    mostrarCustoMedioIntervencoes(intervencoes, nIntervencoes);
    mostrarPontoMaisAvarias(pontosIp, nPontos, avarias, nAvarias);
    mostrarAvariasAteData(avarias, nAvarias);
    mostrarPontoMaisSubstituicao(pontosIp, nPontos, intervencoes, nIntervencoes);
    mostrarAvariadoMais10Dias(pontosIp, nPontos, avarias, nAvarias, intervencoes, nIntervencoes);

    /*
    if (dataConsecutiva.ano == intervencoes[k].dataIntervencao.ano) {
        if (dataConsecutiva.mes >= intervencoes[k].dataIntervencao.mes) {
            if (dataConsecutiva.dia >= intervencoes[k].dataIntervencao.dia) {
                contadorDiasConsecutivos++;
            }
        }
    } else {
        if (dataConsecutiva.ano > intervencoes[k].dataIntervencao.ano) {
            if (dataConsecutiva.mes > 1) {
                contadorDiasConsecutivos++;
            } else {
                if (dataConsecutiva.dia )
            }
        }
    }*/
}

void mostrarPontosIpTecnologia(tipoIp pontosIp[], int nPontos) {
    float percMercurio = 0.0;
    float percSodio = 0.0;
    float percLED = 0.0;

    percTecnologia(pontosIp, nPontos, TECNOLOGIA_MERCURIO, &percMercurio);
    percTecnologia(pontosIp, nPontos, TECNOLOGIA_SODIO, &percSodio);
    percTecnologia(pontosIp, nPontos, TECNOLOGIA_LED, &percLED);

    printf("\nPercentagens de Tecnologias de Luminaria: {");
    printf("\n\t%s: %.2f", TECNOLOGIA_MERCURIO, percMercurio);
    printf("\n\t%s: %.2f", TECNOLOGIA_SODIO, percSodio);
    printf("\n\t%s: %.2f", TECNOLOGIA_LED, percLED);
    printf("\n}\n");
}

void mostrarCustoMedioIntervencoes(tipoIntervencao intervencoes[], int nIntervencoes) {
    float custoTotalIntervencao = 0.0;
    float mediaCustoIntervencao = 0.0;

    for(int i = 0; i < nIntervencoes; i++) {
        custoTotalIntervencao += intervencoes[i].custoIntervencao;
    }

    mediaCustoIntervencao = custoTotalIntervencao / nIntervencoes;
    printf("\nCusto media de Intervencoes: %.2f", mediaCustoIntervencao);
}

void mostrarPontoMaisAvarias(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias) {
    if (nAvarias == 0) {
        printf("\nNenhum ponto esta avariado.");
    } else {
        int id = -1;
        int idaux = -1;
        int contador = 0;
        int aux = 0;

        for(int i = 0; i < nAvarias; i++) {
            id = avarias[i].idPontoIp;
            for(int j = 0; j < nPontos; i++) {
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
    }
}

void mostrarAvariasAteData(tipoAvaria avarias, int nAvarias) {
    tipoData novaData;
    int contadorMenorData = 0;

    printf("Insira a data limite para consultar o numero as avarias: ");
    novaData = lerData();

    for(int i = 0; i < nAvarias; i++) {
        if(avarias[i].dataAvaria.ano <= novaData.ano){
            if(avarias[i].dataAvaria.mes <= novaData.mes){
                if(avarias[i].dataAvaria.dia < novaData.dia) {
                    contadorMenorData++;
                }
            }
        }
    }
    printf("\nNumero de avarias ate %d-%d-%d: %d", novaData.dia, novaData.mes, novaData.ano, contadorMenorData);
}

void mostrarPontoMaisSubstituicao(tipoIp pontosIp[], int nPontos, tipoIntervencao intervencoes[], int nIntervencoes) {
    int id = -1;
    int auxId = -1;
    int contador = 0;
    int aux = 0;

    if (nIntervencoes == 0) {
        printf("\nNao foram realizadas intervencoes.");
    } else {
        for (int i = 0; i < nPontos; i++) {
            id = pontosIp[i].id;

            for (int j = 0; j < nIntervencoes; j++) {
                if(intervencoes[i].substituicaoLuminaria == 1){
                    contador++;
                }
                if(contador > aux){
                    aux= contador;
                    auxId = id;
                }
            }
        }

        printf("\nPonto IP com maior numero de substituicao de luminarias: %d", auxId);
    }
}

void mostrarAvariadoMais10Dias(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes) {
    tipoData dataConsecutiva;
    int contadorDiasConsecutivos = 0;

    for(int i = 0; i < nPontos; i++) {
        for (int j = 0; j < nAvarias; j++) {
            if (avarias[j].idPontoIp == pontosIp[i].id) {
                dataConsecutiva.ano = avarias[j].dataAvaria.ano;
                dataConsecutiva.mes = avarias[j].dataAvaria.mes;
                dataConsecutiva.dia = avarias[j].dataAvaria.dia;
                soma10Dias(&dataConsecutiva);

                for (int k = 0; k < nIntervencoes; k++) {
                    if (avarias[j].codRegisto == intervencoes[k].codRegisto) {
                        if (intervencoes[k].operacional == 1) {
                            if (dataConsecutiva.ano > intervencoes[k].dataIntervencao.ano) {
                                contadorDiasConsecutivos++;
                            } else {
                                if (intervencoes[k].dataIntervencao.ano == dataConsecutiva.ano) {
                                    if (intervencoes[k].dataIntervencao.mes == dataConsecutiva.mes) {
                                        if (dataConsecutiva.dia >= intervencoes[k].dataIntervencao.dia) {
                                            contadorDiasConsecutivos++;
                                        }
                                    } else {
                                        if (intervencoes[k].dataIntervencao.mes > dataConsecutiva.mes) {
                                            contadorDiasConsecutivos++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("\nNumero de Avarias nao resolvidas durante 10 ou mais dias: %d", contadorDiasConsecutivos);
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

    if (dataConsecutiva->mes > 12) {
        dataConsecutiva->mes = 1;
        dataConsecutiva->ano++;
    }
}
