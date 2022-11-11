#ifndef FUNCOESGRAVAR_H_INCLUDED
#define FUNCOESGRAVAR_H_INCLUDED

/**
 * Valida se o ficheiro abriu corretamento e grava os dados dos pontos, das avarias e das intervencoes.
 * Guardado em ficheiro binario chamado "parque.dat".
 */
void gravarFicheiro(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int abrirAoIniciar);

/**
 * Verifica se o ficheiro foi aberto devidamente e 
 */
void gravarAbrirAoIniciar(int abrirAoIniciar);

//Le e devolve valores que sao armazenados na estruturas tipoIp, tipoAvaria, tipoIntervencoes e as variaveis nPontos, nAvarias e nIntervencoes
void lerFicheiro(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int *nAvarias, tipoIntervencao intervencoes[], int *nIntervencoes);

//Guarda num ficheiro binario os dados das estruturas tipoIp, tipoAvaria, tipoIntervencoes e as variaveis nPontos, nAvarias e nIntervencoes no ficheiro "parque.dat"
//Verifica se o ficheiro foi aberto devidamente, apresenta mensagem de erro caso n�o seja aberto
int lerAbrirAoIniciar();


#endif // FUNCOESGRAVAR_H_INCLUDED
