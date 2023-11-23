#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Pilha.c"

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
            case 1: 
                inicio();
                break;
           case 2:
                tutorial(); 
                printf("\n\nEstá pronto para jogar? ");
                system("PAUSE");
                system("cls");
                inicio();
                break;
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

    int inicio() {
    Pilha *pino1 = criar();
    Pilha *pino2 = criar();
    Pilha *pino3 = criar();

    printf("\nQuantidade de discos (mÃ­nimo 3 e no mÃ¡ximo 10): ");
    int disco = 0;
    scanf("%d", &disco);
    fflush(stdin);
    printf("\n");
    printf("\n----------- INÃCIO DO JOGO -----------\n");

    if (disco >= 3 && disco <= 10) {
        int i;
        for (i = 0; i < disco; i++) {
            empilhar(pino1, i);
        }
        inverter3(pino1);
        imprimir(pino1);
    //Finalizando    
    return 0;
    }

void jogada(Pilha *p1, Pilha *p2, Pilha *p3) {
    printf("\n\nQual disco mover? \n");
    printf("Opção 1: Pino1 p/ pino2 \n");
    printf("Opção 2: Pino1 p/ pino3 \n");
    printf("Opção 3: Pino2 p/ pino1 \n");
    printf("Opção 4: Pino2 p/ pino3 \n");
    printf("Opção 5: Pino3 p/ pino1 \n");
    printf("Opção 6: Pino3 p/ pino2\n");
    printf("Opção 7: Sair \n");
    
    int opcao = 0;
    scanf("%d", &opcao);
    switch (opcao) {
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
        case 7:
            exit(0);
        default:
            printf("Por favor, insira uma opção válida.\n\n");
    }
}

void tutorial() {
    printf("\n-------------------------TUTORIAL-------------------------\n\nA Torre de Hanói consiste numa base contendo três pinos, num dos quais estão dispostos alguns discos uns sobre os outros, por ordem crescente de diâmetro.\nO problema consiste em passar todos os discos de um pino para outro qualquer, de maneira que um disco maior nunca fique em cima de outro menor. O número de discos pode variar, o formato mais simples contém apenas três.\nObservação: Neste jogo, você deverá inserir no mínimo 3 discos e no máximo 10.");
}
