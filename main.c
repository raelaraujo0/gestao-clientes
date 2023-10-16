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
        cadastrar_usuario();
        break;
    case 2:
        // chamada da tela e funcoes
        deletar_usuario();
        break;
    case 3:
        // chamada da tela e funcoes
        atualizar_usuario();
        break;
    case 4:
        // chamada da tela e funcoes
        ler_usuario();
        break;
    case 5:
        listar_usuarios();
        break;
    case 6:
        menuV();
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
        SubTelaCadUsu();x
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
            registrar_venda();
            break;
        case 2:
            deletar_venda();
            break;
        case 3:
            atualizar_venda();
            break;
        case 4:
            ler_venda();
            break;
        case 5:
            listar_vendas();
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
        SubtelaRegVen();
    }

    void deletar_venda(void){
        printf("\n");
        Tela_DelVen();
        printf("\n");
        SubtelaDelVen();
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
