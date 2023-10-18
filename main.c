#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "telas.h"
#include "subtelas.h"
#include "validadores.h"

int main(){
    int escolha;
    printf("\n");
    
    TelaPrincipal();

    scanf("%d", &escolha);
    getchar();
    printf("\n");

    switch (escolha)
    {
    case 1:
        // chamada da tela e funcoes
        SubTelaCadUsu();
        break;
    case 2:
        // chamada da tela e funcoes
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
        Tela_MenuV();
        break;
    case 0:
        printf("\n");
        Sobre();
        getchar();
        printf("\n");
        system("pause");
        main();
        break;

    default:
        printf("opcao invalida,tente novamente \n");
        system("pause");
        main();
        break;
    }

    void cadastrar_usuario(void){
        printf("\n");
        Tela_CadUsu();
        printf("\n");
        SubTelaCadUsu();
    }

    void deletar_usuario(void){
        printf("\n");
        Tela_DelUsu();
        printf("\n");
        SubTelaDelUsu();
    }


    void atualizar_usuario(void){
        printf("\n");
        Tela_AttUsu();
        printf("\n");
        SubTelaAttUsu();
    }

    void ler_usuario(void){
        printf("\n");
        Tela_LerUsu();
        printf("\n");
        SubTelaLerUsu();
    }

    void listar_usuarios(void){
    }

    void menuV(void){
        int escolha;

        system("clear || cls");
        printf("\n");
        Tela_MenuV();
        scanf("%d", &escolha);
        printf("\n");

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

    void registrar_venda(void){
        printf("\n");
        Tela_RegVen();
        printf("\n");
        SubTelaRegVen();
    }

    void deletar_venda(void){
        printf("\n");
        Tela_DelVen();
        printf("\n");
        SubTelaDelVen();
    }

    void atualizar_venda(void){
        printf("\n");
        Tela_AttVen();
        printf("\n");
        SubTelaAttVen();
    }

    void ler_venda(void){
        printf("\n");
        Tela_LerVen();
        printf("\n");
        SubTelaLerVen();
    }

      void listar_vendas(void){
      }
}
