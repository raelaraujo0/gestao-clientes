#include <stdio.h>
#include <stdlib.h>
#include "cbclho.h"

void pausa(){
    printf("Pressione Enter para voltar");
    while (getchar() != '\n');
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void opcoeslistagens(){
    int escolha;
    
    do{   
        system("clear || cls");
        Tela_Listagem();

        scanf("%d", &escolha); limparBuffer();
        switch(escolha){
            case 1:
            listagem_usuarios(); break;

            case 2:
            listagem_alf(); break;

            case 0:  
                menu_principal(); break;

            default:
                printf("Opcao invalida \n");
                continue;
        }
    } while (escolha != '0');
}

void menu_principal(void){
    int escolha;
    int n = 7;
    do{
        system("clear || cls");
        TelaPrincipal();

        scanf("%d", &escolha);
        limparBuffer();

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
            menuVendas();
        case 0:
            system("clear || cls");
            Sobre();
            pausa();

        default:
            printf("opcao invalida,tente novamente \n");
            continue;
        }
    } while (escolha != 'n' || 'n+1');
}
