#include "cbclho.h"

void menuV(void){
    int escolha;

    system("clear || cls");
    Tela_MenuV();
    scanf("%d", &escolha);
    getchar();

    switch (escolha)
    {
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
        SubTelaListarVen();
        break;
    case 6:
        main();
        break;
    default:
        printf("opcao invalida,tente novamente \n");
        system("pause");
        menuV();
        break;
        }
    }