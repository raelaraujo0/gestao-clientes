#include <stdio.h>
#include <stdlib.h>
#include "cbclho.h"

void menuVendas() {
    int escolha;

    LimpaTela();
    Tela_MenuV();
    scanf("%d", &escolha);
    getchar();

    switch (escolha) {
    case 1:
        SubTelaRegVen();
        break;
    case 2:
        SubTelaDelVen();
        break;
    case 3:
        SubTelaAttVen();
        break;
    case 4:
        SubTelaLerVen();
        break;
    case 5:
        listagensvendas();
        break;
    case 6:
        menu_principal();
    default:
        printf("opcao invalida,tente novamente \n");
        system("pause");
        menuVendas();
        break;
    }
}

void listagensvendas() {
    int escolha;
    int n = 7;

    do {
        LimpaTela();
        ListagemCategoria();

        scanf("%d", &escolha);
        limparBuffer();
        switch (escolha) {
        case 1:
            SubTelaListarVen();
            break;

        case 2:
            ListagemCatePrec();
            break;

        case 0:
            menuVendas(); 
            break;

        default:
            printf("escolha invalida \n");
            break;
        }
    } while (escolha != 'n' || n+1);
}
