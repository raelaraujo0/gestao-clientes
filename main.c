#include <stdio.h>
#include <stdlib.h>

// funcoes
int main();
void sobre(void);
void cadastrar_usuario(void);
void deletar_usuario(void);
void atualizar_usario(void);
void ler_usuario(void);
// funcoes

// telas
void sobre(void)
{
    system("clear || cls");
    pritnf("\n");
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
    system("clear || cls");
    printf("\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ===                                                            ===\n");
    printf(" ===                 == CADASTRAR USUARIO ==                    ===\n");
    prinft(" ===                                                            ===\n");
    printf(" ===                     Nome completo:                         ===\n");
    printf(" ===                     Id: (só numeros)                       ===\n");
    printf(" ===               Data de Nascimento: (dd/mm/aaaa)             ===\n");
    printf(" ===                   Telefone: (só numeros)                   ===\n");
    printf(" ===                                                            ===\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf("\n");
    getchar();
}

void deletar_usuario(void);
{
    system("clear || cls");
    pritnf("\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ===                                                            ===\n");
    printf(" ===                   == DELETAR USUARIO ==                    ===\n");
    prinft(" ===                                                            ===\n");
    printf(" ===                     Id: (só numeros)                       ===\n");
    printf(" ===                                                            ===\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    pritnf("\n");
    getchar();
}

void atualizar_usuario(void);
{
    system("clear || cls");
    pritnf("\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ===                                                            ===\n");
    printf(" ===                   == ATUALIZAR USUARIO ==                  ===\n");
    prinft(" ===                                                            ===\n");
    printf(" ===                     Id: (só numeros)                       ===\n");
    printf(" ===                                                            ===\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    pritnf("\n");
    getchar();
}

void ler_usuario();
{
    system("clear || cls");
    pritnf("\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ===                                                            ===\n");
    printf(" ===                     == LER USUARIO ==                      ===\n");
    prinft(" ===                                                            ===\n");
    printf(" ===                     Id: (só numeros)                       ===\n");
    printf(" ===                                                            ===\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    pritnf("\n");
    getchar();
}

int main()
{
    int escolha;
    char resp;

    do
    {
        system("clear || cls");
        printf("\n");
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf(" ===                                                            ===\n");
        printf(" ===                   == MENU PRINCIPAL ==                     ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                     1. CRIAR USUARIO                       ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                   2. DELETAR USUARIO                       ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                   3. ATUALIZAR USUARIO                     ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                      4. LER USUARIO                        ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                         0. SOBRE                           ===\n");
        printf(" ===                                                            ===\n");
        printf(" ===                  Escolha uma das opcoes                    ===\n");
        scanf("%d", &escolha);
        printf(" ===                                                            ===\n");
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
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
            atualizar_usario();
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

        if (escolha != 0)
            ;
        printf("quer realizar outra operacao? (S/N) ");
        scanf("%c", resp);
    }

    while (resp == "S" || resp == "s");
    return 0;
}