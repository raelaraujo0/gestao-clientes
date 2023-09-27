#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
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

// validador
bool validardata(int dia, int mes, int ano)
{
    if (dia < 1 || dia > 31)
    {
        printf("Dia invalido \n");
        return false;
    }
    if (mes < 1 || mes > 12)
    {
        printf("Mes invalido \n");
        return false;
    }
    if (ano < 1)
    {
        printf("Ano invalido \n");
        return false;
    }

    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        // É bissexto
    }
    else
    {
        // Não é bissexto
    }

    return true;
}

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

    _sleep(10000);
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
        break;
    case 0:
        sobre();
        getchar();
        main();
        break;

    default:
        printf("opcao invalida,tente novamente \n");
        _sleep(5000);
        main();
        break;
    }
}

void cadastrar_usuario(void)
{
    char telefone[12];
    char id[10];
    int i;
    char nome[75];
    char email[50];
    char respt;
    int dia, mes, ano;
    bool data_val;

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
        printf(" ===                                  Telefone: (000 0000 0000)                                    === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                           Email:                                              === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Nome Completo:");
        scanf(" %[^\n]*c", nome);
        getchar();

        int tamanho = strlen(nome);

        for (int i = 0; i < tamanho; i++){
            if(!isalpha(nome[i]) && nome[i] != " "){
            printf("O nome esta errado por conter caracter indevido ou estar vazio \n");
            printf("Tente novamente atualizando \n");
            }
        }
            if (tamanho > 75 || strcmp(nome, "") == 0) {
                printf("O nome e invalido por conter mais de 75 caracteres ou ser uma string vazia.\n");
                printf("Tente novamente atualizando.\n");
                strcpy(nome, "");
            }

        printf("Id:");
        scanf(" %[^\n]", id);

    // a funcao de verificador de ID foi reaproveitada para as outras telas
    for (i = 0; i < strlen(id); i++){
        if (!isdigit(id[i]))
        {
            printf("Id incorreto ter algum nao numero, a entrada ID estara constada como vazia \n");
            printf("Tente novamente \n");
            id[10] = "";
            break;
            ;
        }
        if (i > 10)
        {
            printf("Id incorreto por conter mais de 10 digitos, a entrada ID estara constada como vazia \n");
            printf("Tente novamente \n");
            id[10] = "";
            break;
        }
    }

    if (i == strlen(id))
    {
        getchar();

        // amparo do google bard
        printf("insira dia de nascimento:");
        scanf("%d", &dia);
        printf("insira mes de nascimento:");
        scanf("%d", &mes);
        printf("insira ano de nascimento:");
        scanf("%d", &ano);

        data_val = validardata(dia, mes, ano);
        if (!data_val)
        {
            printf("Data de nascimeto invalida \n");
        }
    }

    printf("Telefone:");
    scanf(" %11s", &telefone);
    int valido = true;
    if (strlen(telefone) != 11)
    {
        valido = false;
    }
    else
    { // verificacoes de DD
        if (telefone[0] < '1' || telefone[0] > '9'){
            valido = false;
        }
        else if (telefone[1] < '2' || telefone[1] > '9'){
            valido = false;
        }
        else if (telefone[2] < '2' || telefone[2] > '9'){
            valido = false;
        }

        for (int i = 3; i < 11; i++){
            if (telefone[i] < '0' || telefone[i] > '9')
                ;
            valido = false;
            break;
        }
        if (!isdigit(telefone[0]) || !isdigit(telefone[1]) || !isdigit(telefone[2])){
            printf("Numero invalido por conter caractere inapropriado \n");
            printf("Tente novamente atualizando os dados \n");
            strcpy(telefone,"");
            break;
        }

        if (i > 12)
        {
            printf("Numero invalido por exceder 12 caracteres, o numero estara constado como vazio \n");
            printf("Tente atualizando depois");
            telefone[12] = "";
            break;
        }
    }

    printf("Email:");
    scanf(" %[^\n]", email);

    printf("Seja bem-vindo %s\n", nome);

    printf("Deseja adicionar outro usuario?(S/N)");
    scanf(" %c", &respt);

    // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
    switch (respt){
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
    char id[10];
    int i;
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

        printf("Id:\n");
        scanf(" %[^\n]", id);
        for (i = 0; i < strlen(id); i++)
        {
            if (!isdigit(id[i]))
            {
                printf("Id incorreto ter algum nao numero \n");
                printf("Tente novamente \n");
                break;
            }
            if (i > 10)
            {
                printf("Id incorreto por conter mais de 10 digitos \n");
                printf("Tente novamente \n");
                _sleep(5000);
                break;
            }
        }

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
    char id[10];
    int i;
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
        scanf(" %[^\n]", id);
        for (i = 0; i < strlen(id); i++)
        {
            if (!isdigit(id[i]))
            {
                printf("Id incorreto ter algum nao numero \n");
                printf("Tente novamente \n");
                break;
            }
            if (i > 10)
            {
                printf("Id incorreto por conter mais de 10 digitos \n");
                printf("Tente novamente \n");
                _sleep(5000);
                break;
            }
        }

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
    char id[10];
    int i;
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
        scanf(" %[^\n]", id);
        for (i = 0; i < strlen(id); i++)
        {
            if (!isdigit(id[i]))
            {
                printf("Id incorreto ter algum nao numero \n");
                printf("Tente novamente \n");
                break;
            }
            if (i > 10)
            {
                printf("Id incorreto por conter mais de 10 digitos \n");
                printf("Tente novamente \n");
                _sleep(5000);
                break;
            }
        }
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
    printf(" ===                                          6 - MENU                                             ===\n");
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

void deletar_venda(void)
{
    char id[10];
    int i;
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
        scanf(" %[^\n]", id);
        for (i = 0; i < strlen(id); i++)
        {
            if (!isdigit(id[i]))
            {
                printf("Id incorreto ter algum nao numero \n");
                printf("Tente novamente \n");
                break;
            }
            if (i > 10)
            {
                printf("Id incorreto por conter mais de 10 digitos \n");
                printf("Tente novamente \n");
                _sleep(5000);
                break;
            }
        }

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
    char id[10];
    int i;
    float preco;
    int dia, mes, ano;
    bool data_val;
    char categoria[100];
    char respt;

    while (1)
    {
        system("clear || cls");
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
        scanf(" %[^\n]", id);
        for (i = 0; i < strlen(id); i++)
        {
            if (!isdigit(id[i]))
            {
                printf("Id incorreto ter algum nao numero \n");
                printf("Tente novamente \n");
                break;
            }
            if (i > 10)
            {
                printf("Id incorreto por conter mais de 10 digitos \n");
                printf("Tente novamente \n");
                _sleep(5000);
                break;
            }
        }

        printf("Dia da venda:");
        scanf("%d", &dia);
        printf("Mes da venda:");
        scanf("%d", &mes);
        printf("Ano da venda:");
        scanf("%d", &ano);

        data_val = validardata(dia, mes, ano);
        if (!data_val){
            printf("Data invalida \n");
        }

        getchar();

        printf("Categoria da venda:");
        scanf("%[^\n]", categoria);

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
    char id[10];
    int i;
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
        scanf(" %[^\n]", id);
        for (i = 0; i < strlen(id); i++)
        {
            if (!isdigit(id[i]))
            {
                printf("Id incorreto ter algum nao numero \n");
                printf("Tente novamente \n");
                break;
            }
            if (i > 10)
            {
                printf("Id incorreto por conter mais de 10 digitos \n");
                printf("Tente novamente \n");
                _sleep(5000);
                break;
            }
        }

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
    char id[10];
    int i;
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
        scanf(" %[^\n]", id);
        for (i = 0; i < strlen(id); i++)
        {
            if (!isdigit(id[i]))
            {
                printf("Id incorreto ter algum nao numero \n");
                printf("Tente novamente \n");
                break;
            }
            if (i > 10)
            {
                printf("Id incorreto por conter mais de 10 digitos \n");
                printf("Tente novamente \n");
                _sleep(5000);
                break;
            }
        }

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
