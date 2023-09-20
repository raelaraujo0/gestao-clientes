#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "vendas.h"


// funcoes usuarios 
int main();
void sobre(void);
void cadastrar_usuario(void);
void deletar_usuario(void);
void atualizar_usuario(void);
void ler_usuario(void);
void listar_usuarios(void);

// funcoes vendas
void menuV(void);
void registrar_venda(void);
void deletar_venda(void);
void atualizar_venda(void);
void ler_venda(void);
void listar_vendas(void);


// telas
void sobre(void)
{
    system("clear || cls");
    printf("\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                 programa desenvolvido                      ===\n");
    printf(" ===                por Rael Araujo, aluno de                   ===\n");
    printf(" ===                sistemas de informacao/UF                   ===\n");
    printf(" ===                no componente PROGRAMACAO                   ===\n");
    printf(" ===                2 periodo - JUL/DEZ - 2023                  ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf("\n");

    system("pause");
}

int main()
{
    int escolha;

    system("clear || cls");
    printf("\n");
    printf(" ===================================================================================================== \n");
    printf(" ===================================================================================================== \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                     == MENU PRINCIPAL ==                                      === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===================================================================================================== \n");
    printf(" ===================================================================================================== \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                      1. CRIAR USUARIO                                         === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                     2. DELETAR USUARIO                                        === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                    3. ATUALIZAR USUARIO                                       === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                       4. LER USUARIO                                          === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                     5. LISTAR USUARIOS                                        === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                        = 6. VENDAS =                                          === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                          0. SOBRE                                             === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                    Escolha uma das opcoes                                     === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===================================================================================================== \n");
    printf(" ===================================================================================================== \n");
    scanf("%d", &escolha);
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
    case 0:
        // chamada da tela e funcoes
        sobre();
        break;

    default:
        printf("opcao invalida \n");
        break;
    }
}

void cadastrar_usuario(void)
{
    int telefone;
    int id;
    char nome[75];
    char email[30];
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                   == CADASTRAR USUARIO ==                                     === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Nome completo:                                          === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                      Id: (so numeros)                                         === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                 Data de Nascimento: (dd/mm/aaaa)                              === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                   Telefone: (so numeros)                                      === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                           Email:                                              === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Nome Completo:");
        scanf("%s", nome);

        printf("Id:");
        scanf("%d", &id);

        printf("Telefone:");
        scanf("%d", &telefone);

        printf("Email:");
        scanf("%s", email);

        getchar();

        printf("Seja bem-vindo %s\n", nome);

        printf("Deseja adicionar outro usuario?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            cadastrar_usuario();
            break;
        case 'N':
        case 'n':
            main();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void deletar_usuario(void)
{
    int id;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                     == DELETAR USUARIO ==                                     === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Id:");
        scanf("%d", &id);
        getchar();

        printf("Deseja deletar outro usuario?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            deletar_usuario();
            break;
        case 'N':
        case 'n':
            main();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void atualizar_usuario(void)
{
    int id;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                    == ATUALIZAR USUARIO ==                                    === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Id:");
        scanf("%d", &id);

        getchar();

        printf("Deseja atualizar outro usuario?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            atualizar_usuario();
            break;
        case 'N':
        case 'n':
            main();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void ler_usuario(void)
{
    int id;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       == LER USUARIO ==                                       === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");

        printf("Id:");
        scanf("%d", &id);

        getchar();

        printf("Deseja ler outro usuario?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            ler_usuario();
            break;
        case 'N':
        case 'n':
            main();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void listar_usuarios(void)
{

}


void menuV(void)
{
    int escolha;

    system("clear || cls");
    printf("\n");
    printf(" =====================================================================================================\n");
    printf(" =====================================================================================================\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                     == MENU PRINCIPAL ==                                      ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" =====================================================================================================\n");
    printf(" =====================================================================================================\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                     1. REGISTRAR VENDA                                        ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                      2. DELETAR VENDA                                         ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                     3. ATUALIZAR VENDA                                        ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                        4. LER VENDA                                           ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                      5 - LISTAS VENDAS                                        ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                          0 - MENU                                             ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                     Escolha uma das opcoes                                    ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" =====================================================================================================\n");
    printf(" =====================================================================================================\n");
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
    case 6:
        main();
    default:
        printf("opcao invalida \n");
        break;
    }
}

void deletar_venda(void)
{
    int id;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                      == DELETAR VENDA ==                                      === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Id:");
        scanf("%d", &id);
        getchar();

        printf("Deseja deletar outra venda?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            deletar_venda();
            break;
        case 'N':
        case 'n':
            menuV();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void registrar_venda(void)
{   
    int id;
    float preco;
    int data;
    char categoria[30];
    char respt;

    while(1)
    {   system("clear || cls");
        printf("\n");
        printf(" =====================================================================================================\n");
        printf(" =====================================================================================================\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                     == REGISTRAR VENDA ==                                     ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" =====================================================================================================\n");
        printf(" =====================================================================================================\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                        Informe preco:                                         ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                       Id: (so numeros)                                        ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                   Data da venda: (dd/mm/aaaa)                                 ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                      Categoria do item:                                       ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" =====================================================================================================\n");
        printf(" =====================================================================================================\n");
        printf("\n");

        printf("Informe o preco:");
        scanf("%f", &preco);

        printf("Id:");
        scanf("%d", &id);

        printf("Data da venda:");
        scanf("%d", &data);

        printf("Categoria da venda:");
        scanf("%s", categoria);

        getchar();

        printf("Deseja adicionar outra venda?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            registrar_venda();
            break;
        case 'N':
        case 'n':
            menuV();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void atualizar_venda(void)

{
    int id;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                     == ATUALIZAR VENDA ==                                     === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Id:");
        scanf("%d", &id);

        getchar();

        printf("Deseja atualizar outra venda?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            atualizar_venda();
            break;
        case 'N':
        case 'n':
            menuV();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void ler_venda(void)
{
    int id;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                         == LER VENDA ==                                       === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                        Id: (so numeros)                                       === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Id:");
        scanf("%d", &id);

        getchar();

        printf("Deseja ler outra venda?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            ler_venda();
            break;
        case 'N':
        case 'n':
            menuV();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void listar_vendas(void)
{

}
