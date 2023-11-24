#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pilha.c" //Importa a implementação da pilha

int main(int argc, char const *argv[]){
    int resultado;

    // Define o valor das páginas de código UTF8 e default do Windows
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    // Define codificação como sendo UTF-8
    SetConsoleOutputCP(CPAGE_UTF8);
    
    printf("\tPor Breno Reboredo, Gabriel Damasio, Leonardo Duarte, Mateus Salvador e Yann Soares\n\n");

    //Menu inicial
    while(1){
        printf("------------ MENU INICIAL ------------\n");
        printf("1 - Inicializar\n");
        printf("2 - Tutorial\n");
        printf("3 - Sair\n");

        //Obtém a escolha do usuário
        scanf("%d", &resultado);

        //Realiza a ação correspondente a escolha
        switch(resultado){
            case 1: 
                inicio(); //Chama a função de inicialização do jogo
                break;
           case 2:
                tutorial(); //Chama a função que retorna o tutorial
                printf("\n\nEstá pronto para jogar? ");
                system("PAUSE");
                system("cls"); //Limpa a tela para iniciar o jogo após o tutorial, assim que o usuário aperte qualquer tecla
                inicio();
                break;
            case 3:
                SetConsoleOutputCP(CPAGE_DEFAULT); //Retorna a codificação padrão do windows
                return 0; //Encerra o programa, caso o usuário escolha a opção de sair.
            default:
                printf("Erro. Insira uma opção válida.\n\n"); //Validação para caso o usuário selecione uma opção inválida.
        }
    }
    
    //Retorna a codificação padrão do windows
    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}

//Função de inicialização do jogo
int inicio() {
    //Criação das pilhas
    Pilha *pino1 = criar();
    Pilha *pino2 = criar();
    Pilha *pino3 = criar();

    //Solicita a quantidade de discos ao usuário
    printf("\nQuantidade de discos (mínimo 3 e no máximo 10): ");
    int disco = 0;
    scanf("%d", &disco);
    fflush(stdin);
    printf("\n");
    printf("\n----------- INÍCIO DO JOGO -----------\n");

    //Verifica se a quantidade de discos está dentro do permitido
    if (disco >= 3 && disco <= 10) {
        int i;
        //Empilha os discos no pino 1
        for (i = 0; i < disco; i++) {
            empilhar(pino1, i);
        }
        inverter3(pino1);
        imprimir(pino1);

        //Jogo roda aqui
        while (tamanho(pino3) != disco && tamanho(pino2) != disco) {
            jogada(pino1, pino2, pino3);
        }

        //Encerrando o jogo, mostrando o resultado e o menu, que pergunta se quer jogar novamente.
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
        /*Caso os discos estejam fora da faixa permitida, esta mensagem é mostrada e
        o jogo não roda.*/
        printf("\nDisco fora da faixa permitida.\n\n");
    }
        
    return 0;
}

//Função que gerencia a jogada do usuário
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
    //switch case para cada opção de movimento.
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

//Função para mover um disco entre pilhas
/*Esta função, além de mover, também verifica se aquele movimento é ou não válido.*/
void mover(Pilha *origem, Pilha *destino) {
    if (tamanho(origem) > 0 && (tamanho(destino) == 0 || topo(destino) > topo(origem))) {
        empilhar(destino, desempilhar(origem));
    } else {
        printf("\t\t\tJogada inválida\n");
    }
}

//Função que exibe o tutorial do jogo
void tutorial() {
    printf("\n-------------------------TUTORIAL-------------------------\n\nA Torre de Hanói consiste numa base contendo três pinos, num dos quais estão dispostos alguns discos uns sobre os outros, por ordem crescente de diâmetro.\nO problema consiste em passar todos os discos de um pino para outro qualquer, de maneira que um disco maior nunca fique em cima de outro menor. O número de discos pode variar, o formato mais simples contém apenas três.\nObservação: Neste jogo, você deverá inserir no mínimo 3 discos e no máximo 10.");
}
