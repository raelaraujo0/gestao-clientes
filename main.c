#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "cbclho.h"

int main(){
    int escolha;
    
    TelaPrincipal();

    scanf("%d", &escolha);
    getchar();

    switch (escolha)
    {
    case 1:
        SubTelaCadUsu();
        break;
    case 2:
        SubTelaDelUsu();
        break;
    case 3:
        SubTelaAttUsu();
        break;
    case 4:
        SubTelaLerUsu();
        break;
    case 5:
        SubTelaListarUsu();
        break;
    case 6:
        menuV();
    case 0:
        Sobre();
        getchar();
        main();
        break;

    default:
        printf("opcao invalida,tente novamente \n");
        system("pause");
        main();
        break;
    }
}
