#ifndef FUNCOESGRAVAR_H_INCLUDED
#define FUNCOESGRAVAR_H_INCLUDED

void gravarFicheiro(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int abrirAoIniciar);

void gravarAbrirAoIniciar(int abrirAoIniciar);

void lerFicheiro(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int *nAvarias, tipoIntervencao intervencoes[], int *nIntervencoes);

int lerAbrirAoIniciar();

#endif // FUNCOESGRAVAR_H_INCLUDED
