#include <stdio.h>
#include <stdlib.h>
#include "cbclho.h"

void LimpaTela(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void MenuCompras() {
    int escolha;

    LimpaTela();
    TelaMenuCompras();
    scanf("%d", &escolha);
    limparBuffer();

    switch (escolha) {
    case 1:
        CriarCompra();
        break;
    case 2:
        AtualizarCompra();
        break;
    case 3:
        DeletarCompra();
        break;
    case 4:
        LerCompra();
        break;
    case 5:
        ListagemCompras();
        break;
    case 6:
        TresMaisCaras();
        break;
    case 7:
        menu_principal();
        break;
    default:
        printf("opcao invalida,tente novamente \n");
        pausa();
        MenuCompras();
        break;
    }
}