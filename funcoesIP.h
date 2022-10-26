#ifndef FUNCOESIP_H_INCLUDED
#define FUNCOESIP_H_INCLUDED

#define MAX_IP 50
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
 * Adiciona um ponto IP ao vetor de pontos já existentes e devolve a quantidade de pontos atualizada.
 * */
int adicionarPontoIp(tipoIp pontosIp[], int n);

/**
 * Obtém os dados dos pontos IP introduzidos pelo utilizador e armazena-as numa nova estrutura do tipo "tipoIp". 
 * Devolve a estrutura do novo Ponto IP.
 * */
tipoIp lerDadosPontoIp(tipoIp pontosIp[], int n);

/**
 * Procura por um ponto IP com o mesmo código único que o utilizador inseriu.
 * Caso já exista um ponto com o mesmo código a função retorna a posição desse ponto no vetor.
 * Caso não exista nenhum ponto com o mesmo código então a função retorna -1.
 * */
int procuraPontoIp(tipoIp pontosIp[], int n, int id);

#endif // FUNCOESIP_H_INCLUDED
