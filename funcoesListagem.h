#ifndef FUNCOESLISTAGEM_H_INCLUDED
#define FUNCOESLISTAGEM_H_INCLUDED

/**
 * Funcao principal da listagem, chama todas as outras funcoes de listagem de forma ordenada.
 * Usada para uma maior organizacao.
 * */
void mostrarListagem(tipoIp pontosIp[], int nPontos,
    tipoAvaria avarias[], int nAvarias,
    tipoIntervencao intervencoes[], int nIntervencoes);

/**
 * Mostra os dados completos de todos os pontos IP do parque, incluindo a quantidade de avarias e o
 * custo total com a sua reparação.
*/
void mostrarPontosIp(tipoIp pontosIp[], int nPontos,
    tipoAvaria avarias[], int nAvarias,
    tipoIntervencao intervencoes[], int nIntervencoes);

/**
 * Mostra os pontos IP que utilizam luminárias LED.
*/
void mostrarPontosLed(tipoIp pontosIp[], int nPontos);

/**
 * Mostra os dados de todos os registos de avaria.
*/
void mostrarAvarias(tipoAvaria avarias[], int nAvarias);

/**
 * Mostra o historico de avarias de um determinado ponto IP.
*/
void mostrarHistoricoAvarias(tipoAvaria avarias[], int nAvarias);

/**
 * Mostra os dados de um determinado ponto a partir do codigo de uma das suas avarias.
*/
void mostrarPontoPorAvaria(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

#endif // FUNCOESLISTAGEM_H_INCLUDED
