#ifndef FUNCOESINFORMACAO_H_INCLUDED
#define FUNCOESINFORMACAO_H_INCLUDED

void percTecnologia(tipoIp pontosIp[], int nPontos, char tecnologia[], float *percTec);
int calcularAvariasResolvidas(tipoIntervencao intervencoes[], int nAvarias);
void informacoes(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);
void mostrarPontosIpTecnologia(tipoIp pontosIp[], int nPontos);
void mostrarCustoMedioIntervencoes(tipoIntervencao intervencoes[], int nIntervencoes);
void mostrarPontoMaisAvarias(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias);
void mostrarAvariasAteData(tipoAvaria avarias[], int nAvarias);
void mostrarPontoMaisSubstituicao(tipoIp pontosIp[], int nPontos, tipoIntervencao intervencoes[], int nIntervencoes);
void mostrarAvariadoMais10Dias(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);
void soma10Dias(tipoData *dataConsecutiva);

#endif // FUNCOESINFORMACAO_H_INCLUDED
