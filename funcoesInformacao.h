#ifndef FUNCOESINFORMACAO_H_INCLUDED
#define FUNCOESINFORMACAO_H_INCLUDED

/**
 * Calcula e devolve por ponteiro a percentagem de pontos de um certo tipo de tecnologia de Luminaria.
 */
void percTecnologia(tipoIp pontosIp[], int nPontos, char tecnologia[], float *percTec);

/**
 * Calcula e devolve a quantidade de avarias resolvidas.
 */
int calcularAvariasResolvidas(tipoIntervencao intervencoes[], int nAvarias);

/**
 * Mostra no ecra as informacoes do parque.
 */
void informacoes(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

/** 
 * Mostra no ecra as percentagens de tecnologias de luminarias utilizadas.
 */
void mostrarPontosIpTecnologia(tipoIp pontosIp[], int nPontos);

/**
 * Calcula e mostra no ecra o custo medio das intervencoes.
 */
void mostrarCustoMedioIntervencoes(tipoIntervencao intervencoes[], int nIntervencoes);

/**
 * Determina e mostra no ecra o ID do pontoIp com maior numero de avarias. 
 */
void mostrarPontoMaisAvarias(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias);

/**
 * Pede para ser inserida uma data e determina o numero de avarias registadas ate esse dia.
 */
void mostrarAvariasAteData(tipoAvaria avarias[], int nAvarias);

/**
 * Valida se existem intervencoes registadas, caso existam determina o id do pontoIp com maior numero de substituicao de luminarias.
 */
void mostrarPontoMaisSubstituicao(tipoIp pontosIp[], int nPontos, tipoIntervencao intervencoes[], int nIntervencoes);

/**
 * Mostra as avarias que nao tiveram uma intervencao durante 10 ou mais dias.
 */
void mostrarAvariadoMais10Dias(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

/**
 * Adiciona 10 dias a data do registo da avaria, tendo em conta os meses e anos.
 */
void soma10Dias(tipoData *dataConsecutiva);

#endif // FUNCOESINFORMACAO_H_INCLUDED
