#include <stdio.h>
#include <stdlib.h>
#include "cbclho.h"

void pausa() {
    printf("Pressione Enter para voltar");
    while (getchar() != '\n');
}

void menu_principal(void){
    int escolha;
    do{
        system("pause");
        TelaPrincipal();

        scanf("%d", &escolha);
        getchar();

        switch (escolha)
        {
        case '1':
            SubTelaCadUsu(); break;

        case '2':
            SubTelaDelUsu(); break;

        case '3':
            SubTelaAttUsu(); break;

        case '4':
            SubTelaLerUsu(); break;

        case '5':
            opcoeslistagens(); break;

        case '6':
            Tela_Login(); break;

        case '0':
            system("clear || cls");
            Sobre();
            pausa();

        default:
            printf("opcao invalida,tente novamente \n");
            continue;
        }
    } while (escolha != '0');
}


void opcoeslistagens(){
    int escolha;
    
    do{   
        system("pause");
        Tela_Listagem();

        scanf("%d", &escolha); getchar();
        switch(escolha){
            case '1':
            SubTelaListarUsu(); break;

            case '2':
            listagem_por_nome(); break;

            case '0': break;

            default:
                printf("Opcao invalida \n");
                continue;
        }
    } while (escolha != '0');
}