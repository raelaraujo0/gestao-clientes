#include <stdio.h>
#include <stdlib.h>
#include "cbclho.h"

void pausa() {
    printf("Pressione Enter para voltar");
    while (getchar() != '\n');
}

void opcoeslistagens(){
    int escolha;
    
    do{   
        system("clear || cls");
        Tela_Listagem();

        scanf("%d", &escolha); getchar();
        switch(escolha){
            case 1:
            SubTelaListarUsu(); 

            case 2:
            listagem_por_nome();

            case 0:  menu_principal(); break;

            default:
                printf("Opcao invalida \n");
                continue;
        }
    } while (escolha != '0');
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
        case 1:
            SubTelaCadUsu(); break;

        case 2:
            SubTelaDelUsu(); break;

        case 3:
            SubTelaAttUsu(); break;

        case 4:
            SubTelaLerUsu(); break;

        case 5:
            opcoeslistagens(); break;

        case 6:
            Login();
        case 0:
            system("clear || cls");
            Sobre();
            pausa();

        default:
            printf("opcao invalida,tente novamente \n");
            continue;
        }
    } while (escolha != '0');
}
