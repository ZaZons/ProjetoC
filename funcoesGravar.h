#ifndef FUNCOESGRAVAR_H_INCLUDED
#define FUNCOESGRAVAR_H_INCLUDED

/**
 * Valida se o ficheiro abriu corretamente e grava os dados dos pontos, das avarias e das intervencoes.
 * Guardado em ficheiro binario chamado "parque.dat".
 */
void gravarFicheiro(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int abrirAoIniciar);

/**
 * Verifica se o ficheiro foi aberto devidamente e grava a opcao de carregar os dados quando o programa iniciar.
 */
void gravarAbrirAoIniciar(int abrirAoIniciar);

/**
 * Le e devolve valores armazenados no ficheiro com os dados.
 */
void lerFicheiro(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int *nAvarias, tipoIntervencao intervencoes[], int *nIntervencoes);

/**
 * Le se a opcao de carregar os dados quando o programa iniciar.
 */
int lerAbrirAoIniciar();


#endif // FUNCOESGRAVAR_H_INCLUDED
