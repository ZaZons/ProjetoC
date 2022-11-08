#ifndef FUNCOESIP_H_INCLUDED
#define FUNCOESIP_H_INCLUDED

#define MAX_IP 50
#define MIN_IP_ID 1
#define MAX_IP_ID 9999
#define MAX_CPE 20
#define MAX_TECNOLOGIA 20

typedef struct {
  int id;
  char cpe[MAX_CPE];
  int potencia;
  int estadoFuncionamento;
  char tipoTecnologia[MAX_TECNOLOGIA];
} tipoIp;

/**
 * Adiciona um ponto IP ao vetor de pontos ja existentes e devolve a quantidade de pontos atualizada.
*/
int novoPontoIp(tipoIp pontosIp[], int n);

/**
 * Obtem os dados dos pontos IP introduzidos pelo utilizador e armazena-as numa nova estrutura do tipo "tipoIp".
 * Devolve a estrutura do novo Ponto IP.
*/
tipoIp lerDadosPontoIp(tipoIp pontosIp[], int n);

/**
 * Procura por um ponto IP com o mesmo codigo unico que o utilizador inseriu.
 * Caso ja exista um ponto com o mesmo codigo a funcao retorna a posicao desse ponto no vetor.
 * Caso nao exista nenhum ponto com o mesmo codigo entao a funcao retorna -1.
*/
int procuraPontoIp(tipoIp pontosIp[], int n, int id);

/**
 * Calcula o numero de pontos que utilizam luminarias LED.
*/
int calcularPontosLed(tipoIp pontosIp[], int n);

#endif // FUNCOESIP_H_INCLUDED
