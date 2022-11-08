#ifndef FUNCOESLISTAGEM_H_INCLUDED
#define FUNCOESLISTAGEM_H_INCLUDED

void mostrarListagem(tipoIp pontosIp[], int nPontos, 
    tipoAvaria avarias[], int nAvarias,
    /* tipoIntervencao intervencoes[] */, int nIntervencoes);

void mostrarPontosIp(tipoIp pontosIp[], int nPontos, 
    tipoAvaria avarias[], int nAvarias,
    /* tipoIntervencao intervencoes[] */, int nIntervencoes);

void mostrarPontosLed(tipoIp pontosIp[], int nPontos);

#endif // FUNCOESLISTAGEM_H_INCLUDED
