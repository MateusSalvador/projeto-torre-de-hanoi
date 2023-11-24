#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Pilha.c"

int main(int argc, char const *argv[]){
    int resultado;

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);
    
    printf("\tPor Breno Reboredo, Gabriel Damasio, Leonardo Duarte, Mateus Salvador e Yann Soares\n\n");

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

    printf("\nQuantidade de discos (mínimo 3 e no máximo 10): ");
    int disco = 0;
    scanf("%d", &disco);
    fflush(stdin);
    printf("\n");
    printf("\n----------- INÍCIO DO JOGO -----------\n");

    if (disco >= 3 && disco <= 10) {
        int i;
        for (i = 0; i < disco; i++) {
            empilhar(pino1, i);
        }
        inverter3(pino1);
        imprimir(pino1);

        while (tamanho(pino3) != disco && tamanho(pino2) != disco) {
            jogada(pino1, pino2, pino3);
        }

        printf("--------------------------------------\n");
		printf("Parabéns, você ganhou!\n");
        printf("\nDeseja jogar novamente?\n Digite 1 - Sim\n Digite 2 - Não\n");
        int resultado2;
        scanf("%d", &resultado2);

        if (resultado2 == 1) {
            free(pino1);
            free(pino2);
            free(pino3);
        } else if (resultado2 == 2) {
            exit(0);
        } else {
            printf("Sem resposta.");
            exit(0);
        }
    } else {
        printf("\nDisco fora da faixa permitida.\n\n");
    }
        
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
    printf("Opção 8: Reiniciar \n");
    int opcao = 0;
    scanf("%d", &opcao);
    switch (opcao) {
       case 1:
            mover(p1, p2);
            imprimir(p1);
            imprimir(p2);
            imprimir(p3);
            break;
        case 2:
            mover(p1, p3);
            imprimir(p1);
            imprimir(p2);
            imprimir(p3);
            break;
        case 3:
            mover(p2, p1);
            imprimir(p1);
            imprimir(p2);
            imprimir(p3);
            break;
        case 4:
            mover(p2, p3);
            imprimir(p1);
            imprimir(p2);
            imprimir(p3);
            break;
        case 5:
            mover(p3, p1);
            imprimir(p1);
            imprimir(p2);
            imprimir(p3);
            break;
        case 6:
            mover(p3, p2);
            imprimir(p1);
            imprimir(p2);
            imprimir(p3);
            break;
        case 7:
            exit(0);
	case 8:
            free(p1);
            free(p2);
            free(p3);
            inicio(); 
            break;
        default:
            printf("Por favor, insira uma opção válida.\n\n");
    }
}


void mover(Pilha *origem, Pilha *destino) {
    if (tamanho(origem) > 0 && (tamanho(destino) == 0 || topo(destino) > topo(origem))) {
        empilhar(destino, desempilhar(origem));
    } else {
        printf("\t\t\tJogada inválida\n");
    }
}

void tutorial() {
    printf("\n-------------------------TUTORIAL-------------------------\n\nA Torre de Hanói consiste numa base contendo três pinos, num dos quais estão dispostos alguns discos uns sobre os outros, por ordem crescente de diâmetro.\nO problema consiste em passar todos os discos de um pino para outro qualquer, de maneira que um disco maior nunca fique em cima de outro menor. O número de discos pode variar, o formato mais simples contém apenas três.\nObservação: Neste jogo, você deverá inserir no mínimo 3 discos e no máximo 10.");
}
