#ifndef FUNCOESINFORMACAO_H_INCLUDED
#define FUNCOESINFORMACAO_H_INCLUDED

void percTecnologia(int n, int nTotal, float *percN);
void avariasResolvidas(tipoIntervencao intervencoes[], int nAvarias,int *avariasR);
void informacoes(int nPontos, tipoIp pontosIp[], tipoIntervencao intervencoes[], int nIntervencoes, tipoAvaria avarias[], int nAvarias);
void soma10Dias(tipoData *dataConsecutiva);

#endif // FUNCOESINFORMACAO_H_INCLUDED
