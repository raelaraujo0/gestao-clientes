void menuVendas();


#include <stdio.h>
#include <stdlib.h>
#include "cbclho.h"

char nome[15];

void listagensvendas() {
    int escolha;
    int n = 7;

    do {
        system("clear || cls");
        ListagemCategoria();

        scanf("%d", &escolha);
        limparBuffer();
        switch (escolha) {
        case 1:
            SubTelaListarVen();
            break;

        case 2:
            ListagemCategoria();
            break;

        case 0:
            menuVendas(); 
            break;

        default:
            printf("escolha invalida \n");
            break;
        }
    } while (escolha != 'n' || 'n+1');
}

void menuVendas() {
    int escolha;

    system("clear || cls");
    Tela_MenuV();
    scanf("%d", &escolha);
    getchar();

    switch (escolha) {
    case 1:
        SubTelaRegVen(nome);
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
