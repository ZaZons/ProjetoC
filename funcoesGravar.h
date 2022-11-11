#ifndef FUNCOESGRAVAR_H_INCLUDED
#define FUNCOESGRAVAR_H_INCLUDED

//Valida se o ficheiro abriu corretamento e grava as estruturas tipoIp, tipoAvaria, tipoIntervencoes e as variaveis nPontos, nAvarias e nIntervencoes
//Guardado em ficheiro binario chamado "parque.dat"
void gravarFicheiro(tipoIp pontosIp[], int nPontos, tipoAvaria avarias[], int nAvarias, tipoIntervencao intervencoes[], int nIntervencoes, int abrirAoIniciar);

//Permite a utilizacao de dados guardados anteriormente quando se inicia o programa
//Verifica se o ficheiro foi aberto devidamente, apresenta mensagem caso não seja aberto
void gravarAbrirAoIniciar(int abrirAoIniciar);

//Le e devolve valores que sao armazenados na estruturas tipoIp, tipoAvaria, tipoIntervencoes e as variaveis nPontos, nAvarias e nIntervencoes
void lerFicheiro(tipoIp pontosIp[], int *nPontos, tipoAvaria avarias[], int *nAvarias, tipoIntervencao intervencoes[], int *nIntervencoes);

//Guarda num ficheiro binario os dados das estruturas tipoIp, tipoAvaria, tipoIntervencoes e as variaveis nPontos, nAvarias e nIntervencoes no ficheiro "parque.dat"
//Verifica se o ficheiro foi aberto devidamente, apresenta mensagem de erro caso não seja aberto
int lerAbrirAoIniciar();


#endif // FUNCOESGRAVAR_H_INCLUDED
