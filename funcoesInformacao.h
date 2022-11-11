#ifndef FUNCOESINFORMACAO_H_INCLUDED
#define FUNCOESINFORMACAO_H_INCLUDED
//calcula e devolve por ponteiro a percentagem de pontos de um certo tipo de tecnologia de Luminária
void percTecnologia(tipoIp pontosIp[], int nPontos, char tecnologia[], float *percTec);

//Calcula e devolve por ponteiro a quantidade de avarias resolvidas
int calcularAvariasResolvidas(tipoIntervencao intervencoes[], int nAvarias);

//Mostra no ecra as percentagens de tecnologias de luminaria, custo medio de intervencoes, o ponto Ip com maior numero de avarias registadas,
//avarias registadas ate determinada data, pontoIp com maior numero de substituicao de luminarias, e avarias que demoraram mais de 10 dias consecutivos a serem intervencionadas
void informacoes(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

//Executa a funcao percTecnologias e mostra no ecra as percentagens de tecnologias de luminarias utilizadas
void mostrarPontosIpTecnologia(tipoIp pontosIp[], int nPontos);

//Calcula e mostra no ecra o custo medio das intervencoes
void mostrarCustoMedioIntervencoes(tipoIntervencao intervencoes[], int nIntervencoes);

//Determina e mostra no ecra o ID do pontoIp com maior numero de avarias
void mostrarPontoMaisAvarias(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias);

//Pede para ser inserida uma data e determina o numero de avarias registadas antes desse dia
void mostrarAvariasAteData(tipoAvaria avarias[], int nAvarias);

//Valida se existe intervencoes registadas, caso existam determina o id do pontoIp com maior numero de substituicao de luminarias
void mostrarPontoMaisSubstituicao(tipoIp pontosIp[], int nPontos, tipoIntervencao intervencoes[], int nIntervencoes);

//Verifica por cada pontoIp se existe uma avaria associada, é executada a funcao soma10Dias, validado se existe uma intervencao para a avaria registada,
//se a data devolvida pela funcao soma10Dias tiver um ano maior que a da avaria é feito um incremento na variavel, senao é verificado se o mes é igual
//e verificado se o dia é maior, incrementada a variavel  se for, senao é verificado se o mes e maior, se sim incrementada a variavel
//Mostra no ecra o numero final de avarias que nao foram resolvidas no espaço de 10 dias consecutivos
void mostrarAvariadoMais10Dias(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes);

//Adiciona 10 dias à data do registo da avaria, caso esta ultrapasse o dia maximo do respetivo mes, é feito incremento ao mes, se o valor do mes for superior a 12 é feito um incremento ao ano
void soma10Dias(tipoData *dataConsecutiva);

#endif // FUNCOESINFORMACAO_H_INCLUDED
