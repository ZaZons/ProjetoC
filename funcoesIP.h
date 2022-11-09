#ifndef FUNCOESIP_H_INCLUDED
#define FUNCOESIP_H_INCLUDED

#define MAX_IP 50
#define MIN_IP_ID 1
#define MAX_IP_ID 9999
#define MAX_CPE 20
#define MAX_TECNOLOGIA 20

#define POTENCIA_1 33
#define POTENCIA_2 50
#define POTENCIA_3 100

#define TECNOLOGIA_MERCURIO "Vapor de mercurio"
#define TECNOLOGIA_SODIO "Vapor de sodio"
#define TECNOLOGIA_LED "LED"

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
int novoPontoIp(tipoIp pontosIp[], int nPontos);

/**
 * Obtem os dados dos pontos IP introduzidos pelo utilizador e armazena-as numa nova estrutura do tipo "tipoIp".
 * Devolve a estrutura do novo Ponto IP.
*/
tipoIp lerDadosPontoIp(tipoIp pontosIp[], int nPontos);

/**
 * Procura por um ponto IP com o mesmo codigo unico que o utilizador inseriu.
 * Caso ja exista um ponto com o mesmo codigo a funcao retorna a posicao desse ponto no vetor.
 * Caso nao exista nenhum ponto com o mesmo codigo entao a funcao retorna -1.
*/
int procuraPontoIp(tipoIp pontosIp[], int nPontos, int id);

/**
 * Calcula e devolve o numero de pontos que utilizam luminarias de um certo tipo de tecnologia.
*/
int calcularTecnologiaPontos(tipoIp pontosIp[], int nPontos, char tecnologia[]);

#endif // FUNCOESIP_H_INCLUDED
