#include <stdio.h>
#include <stdlib.h>

int menu (void);

int main()
{
    int opcao;

    do
    {
    opcao = menu();

    switch(opcao)
    {
        case 1: 

            break;

        case 2:

            break;

        case 3:
            
            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;        
    }

    }while(opcao != 0);


    return 0;
}


int menu (void) // importar valores para mostrar no menu
{
    int opcao = 0;

    printf("\tGestão de Pontos de Iluminacao Publica(IP)");
    printf("\nTotal de pontos IP: %d\tPontos IP avariados: %d", ); //add totalpontos e pontos avariados
    printf("Avarias resolvidas: %d\tTecnologia LED (%%): %.1f", ); // add avarias resolvidas e tec led
    printf("\n   1. Novo ponto IP");
    printf("\n   2. Registo de Avaria");
    printf("\n   3. Registo de Intervencao");
    printf("\n   4. Listagens");
    printf("\n   5. Informacoes");
    printf("\n   6. Gravar");
    printf("\n   0. Sair");
    printf("\tSelecione a opcao: ");
    scanf(" %d", &opcao);
}