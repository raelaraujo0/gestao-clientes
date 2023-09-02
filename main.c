#include <stdio.h>
#include <stdlib.h>

// funcoes
int main();
void sobre(void);
void cadastrar_usuario(void);
void deletar_usuario(void);
void atualizar_usuario(void);
void ler_usuario(void);
// funcoes

// telas
void sobre(void)
{
    system("clear || cls");
    printf("\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                 programa desenvolvido                      ===\n");
    printf(" ===                por Rael Araujo, aluno de                   ===\n");
    printf(" ===                sistemas de informacao/UF                   ===\n");
    printf(" ===                no componente PROGRAMAÇÃO                   ===\n");
    printf(" ===                2 periodo - JUL/DEZ - 2023                  ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf("\n");
}

void cadastrar_usuario(void)
{
    int telefone;
    int datansm;
    int id;
    char nome[75];
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf(" ===                                                            ===\n");
        printf(" ===                 == CADASTRAR USUARIO ==                    ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                     Nome completo:                         ===\n");
        printf(" ===                    Id: (só numeros)                        ===\n");
        printf(" ===             Data de Nascimento: (dd/mm/aaaa)               ===\n");
        printf(" ===                Telefone: (só numeros)                      ===\n");
        printf(" ===                                                            ===\n");
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf("\n");

        printf("Nome Completo:");
        scanf("%s", nome);

        printf("Id:");
        scanf("%d", &id);

        printf("Telefone:");
        scanf("%d", &telefone);

        getchar();

        printf("Seja bem-vindo %s\n", nome);

        printf("Deseja adicionar outro usuario?(S/N)");
        scanf(" %c", &respt);

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
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf(" ===                                                            ===\n");
        printf(" ===                   == DELETAR USUARIO ==                    ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                     Id: (só numeros)                       ===\n");
        printf(" ===                                                            ===\n");
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf("\n");

        printf("Id:");
        scanf("%d", &id);
        getchar();
        printf("Deseja deletar outro usuario?(S/N)");
        scanf(" %c", &respt);
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
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf(" ===                                                            ===\n");
        printf(" ===                   == ATUALIZAR USUARIO ==                  ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                     Id: (só numeros)                       ===\n");
        printf(" ===                                                            ===\n");
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf("\n");

        printf("Id:");
        scanf("%d", &id);
        getchar();

        printf("Deseja ler outro usuario?(S/N)");
        scanf(" %c", &respt);
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
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf(" ===                                                            ===\n");
        printf(" ===                     == LER USUARIO ==                      ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                     Id: (só numeros)                       ===\n");
        printf(" ===                                                            ===\n");
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf("\n");

        printf("Id:");
        scanf("%d", &id);
        getchar();

        printf("Deseja atualizar outro usuario?(S/N)");
        scanf(" %c", &respt);
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


int main()
{
    int escolha;
    char resp;

    system("clear || cls");
    printf("\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ===                                                            ===\n");
    printf(" ===                   == MENU PRINCIPAL ==                     ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                     1. CRIAR USUARIO                       ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                    2. DELETAR USUARIO                      ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                   3. ATUALIZAR USUARIO                     ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                      4. LER USUARIO                        ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                         0. SOBRE                           ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                  Escolha uma das opcoes                    ===\n");
    printf(" ===                                                            ===\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
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
    case 0:
        // chamada da tela e funcoes
        sobre();
        break;

    default:
        printf("opcao invalida \n");
        break;
    }
}