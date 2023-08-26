#include <stdio.h>
#include <stdlib.h>

void sobre()
{
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
}

int main()
{
    int escolha;
    char resp;

    do
    {
        printf(" ==================================================================\n");
        printf(" ==================================================================\n");
        printf(" ===                                                            ===\n");
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

        switch (escolha)
        {
        case 1:
            printf("Criando usuario");
            break;
        case 2:
            printf("Deletando usuario");
            break;
        case 3:
            printf("Atualizando usuario");
            break;
        case 4:
            printf("Lendo usuario");
            break;
        case 0:
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
