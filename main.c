#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char const *argv[]){
    int resultado;

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);
    
    printf("\tPor Breno Reboredo, Gabriel Damasio, Leoanrdo Duarte, Mateus Salvador e Yann Soares\n\n");

    while(1){
        printf("------------ MENU INICIAL ------------\n");
        printf("1 - Inicializar\n");
        printf("2 - Tutorial\n");
        printf("3 - Sair\n");

        scanf("%d", &resultado);

        switch(resultado){
            /*case 1: 
                //função para iniciar o game
                break;
            case 2:
                //função que retorna o tutorial do jogo
                printf("\n\nEstá pronto para jogar? ");
                break;*/
            case 3:
                SetConsoleOutputCP(CPAGE_DEFAULT);
                return 0; 
            default:
                printf("Erro. Insira uma opção válida.\n\n");
        }
    }
    
    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}
