#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cbclho.h"

Compra* CriarCompra(void) {
    Compra *com;
    com = (Compra*)malloc(sizeof(Compra));
    char respt;

    if (com == NULL) {
        printf("Erro na alocação de memoria\n");
        return NULL;
    }

    while (1) {
        system("clear");
        TelaCriarCompra();

        int datavalida, precocomvalido, nomevalido, categoriaval;

        do {
            printf("Digite seu nome:");
            fgets(com->nome, sizeof(com->nome), stdin);
            com->nome[strcspn(com->nome, "\n")] = '\0';
            limparBuffer();

            nomevalido = validarnome(com->nome);

            if (!nomevalido) {
                printf("Nome invalido, tente novamente.");
            }
        } while (!nomevalido);

        do {
            printf("Informe o preço (apenas numeros): ");
            scanf("%19s", com->preco);
            limparBuffer();
            com->preco[strcspn(com->preco, "\n")] = '\0';

            precocomvalido = verificapreco(com->preco);

            if (!precocomvalido) {
                printf("Isso nao é um valor valido, tente novamente\n");
            }
        } while (!precocomvalido);

        do {
            printf("Insira o dia da compra: ");
            fgets(com->dia, sizeof(com->dia), stdin);
            limparBuffer();
            printf("Insira o mes da compra: ");
            fgets(com->mes, sizeof(com->mes), stdin);
            limparBuffer();
            printf("Insira o ano da compra: ");
            fgets(com->ano, sizeof(com->ano), stdin);
            limparBuffer();

            datavalida = validardata(com->dia, com->mes, com->ano);

            if (!datavalida) {
                printf("Data invalida, tente novamente\n");
            }
        } while (!datavalida);

        do {
            printf("Informe a categoria da compra: ");
            scanf("%49s", com->produto);
            limparBuffer();

            categoriaval = validarcategoria(com->produto);

            if (!categoriaval) {
                printf("A categoria está incorreta, tente novamente\n");
            }
        } while (!categoriaval);

        printf("Informe a quantidade de itens comprados: ");
        scanf("%9s", com->quantidade);
        limparBuffer();

        com->ativa = 1;

        snprintf(com->id, sizeof(com->id), "%s%s%s%s", com->mes, com->preco, com->dia, com->ano);
        printf("Compra cadastrada! Para fazer alteracoes, o ID sera: %s\n\n", com->id);

        SalvarCompra(com);
        free(com);

        printf("Deseja registrar outra compra? (S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        switch (respt) {
            case 'S':
            case 's':
                continue;
            case 'N':
            case 'n':
                MenuCompras();
            default:
                printf("Opção inválida\n");
                MenuCompras();

        return com;
        }
    }
}

void AtualizarCompra(void) {
    char id[31];
    char respt;
    Compra compraatt;

    int datavalida = 0, categoriaval = 0;

    while (1) {
        LimpaTela();
        TelaAttCompra();
        printf("Digite o ID da compra que deseja atualizar: ");
        scanf("%30s", id);
        limparBuffer();

        FILE* arquivocompra = fopen("compras.dat", "rb+");
        int encontrado = 0;
        long posicaoanterior = 0;

        while (fread(&compraatt, sizeof(Compra), 1, arquivocompra) == 1) {
            if(strcmp(compraatt.id, id) == 0) {
                encontrado = 1;
                break;
            }
            posicaoanterior = ftell(arquivocompra) - sizeof(Compra);
        }

        fclose(arquivocompra);

        if (!encontrado) {
            printf("Compra nao encontrada\n");
            continue;
        }

        if (compraatt.ativa == 0) {
            printf("Esta compra esta inativa e nao pode ser atualizada\n");
            pausa();
            MenuCompras();
        }

        do {
            printf("Nova categoria da compra: ");
            scanf("%19s", compraatt.produto);
            limparBuffer();

            categoriaval = validarcategoria(compraatt.produto);

            if (!categoriaval) {
                printf("A categoria esta incorreta, tente novamente\n");
            }
        } while (!categoriaval);

        printf("Novo preço da compra: ");
        scanf("%19s", compraatt.preco);
        limparBuffer();

        do {
            printf("Insira o novo dia da compra: ");
            fgets(compraatt.dia, sizeof(compraatt.dia), stdin);
            limparBuffer();
            printf("Insira o novo mês da compra: ");
            fgets(compraatt.mes, sizeof(compraatt.mes), stdin);
            limparBuffer();
            printf("Insira o novo ano da compra: ");
            fgets(compraatt.ano, sizeof(compraatt.ano), stdin);
            limparBuffer();
            
            datavalida = validardata(compraatt.dia, compraatt.mes, compraatt.ano);

            if (!datavalida) {
                printf("Data invalida, tente novamente\n");
            }
        } while (!datavalida);

        printf("Nova quantidade de itens comprados: ");
        fgets(compraatt.quantidade, sizeof(compraatt.quantidade), stdin);
        limparBuffer();

        snprintf(compraatt.id, sizeof(compraatt.id), "%s%s%s%s", compraatt.ano, compraatt.preco, compraatt.dia, compraatt.mes);

        printf("Compra atualizada! O novo ID será: %s\n\n", compraatt.id);

        arquivocompra = fopen("compras.dat", "rb+");
        fseek(arquivocompra, posicaoanterior, SEEK_SET);
        fwrite(&compraatt, sizeof(Compra), 1, arquivocompra);
        fclose(arquivocompra);

        printf("Deseja atualizar outra compra?(S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        switch (respt) {
            case 'S':
            case 's':
                continue;
            case 'N':
            case 'n':
                MenuCompras();
            default:
                printf("Opção invalida\n");
                MenuCompras();
        }
    }
}

void DeletarCompra(void) {
    char id[31];
    char respt, respt2;
    Compra compradeletada;

    while (1) {
        LimpaTela();
        TelaDelCompra();
        printf("Digite o ID da compra que deseja deletar: ");
        scanf("%30s", id);
        limparBuffer();

        FILE *arquivocompra = fopen("compras.dat", "rb+");
        int encontrado = 0;
        long posicaoanterior = 0;

        while (fread(&compradeletada, sizeof(Compra), 1, arquivocompra) == 1) {
            if(strcmp(compradeletada.id, id) == 0) {
                encontrado = 1;
                break;
            }
            posicaoanterior = ftell(arquivocompra) - sizeof(Compra);
        }

        fclose(arquivocompra);

        if (!encontrado) {
            printf("Compra não encontrada\n");
            continue;
        }

        printf("Deseja deletar esta compra? (S/N)\n");
        scanf(" %c", &respt2);
        limparBuffer();

        if (respt2 == 'S' || respt2 == 's') {
            compradeletada.ativa = 0;

            arquivocompra = fopen("compras.dat", "rb+");
            fseek(arquivocompra, posicaoanterior, SEEK_SET);
            fwrite(&compradeletada, sizeof(Compra), 1, arquivocompra);
            fclose(arquivocompra);

            printf("Compra deletada!\n");
        } else {
            printf("Operação cancelada\n");
        }

        printf("Deseja deletar outra compra? (S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        switch (respt) {
            case 'S':
            case 's':
                continue;
            case 'N':
            case 'n':
                MenuCompras();
            default:
                printf("Opção invalida\n");
                MenuCompras();
        }
    }
}

void LerCompra(void) {
    char id[31];
    char respt;
    Compra compralencontrada;

    while (1) {
        LimpaTela();
        TelaLerCompra();
        printf("Digite o ID da compra que deseja ler: ");
        scanf("%30s", id);
        limparBuffer();

        FILE *arquivocompra = fopen("compras.dat", "rb");
        int encontrado = 0;

        while (fread(&compralencontrada, sizeof(Compra), 1, arquivocompra) == 1) {
            if(strcmp(compralencontrada.id, id) == 0) {
                encontrado = 1;
                printf("Detalhes da compra:\n");
                printf("Nome : %s\n", compralencontrada.nome);
                printf("Categoria: %s\n", compralencontrada.produto);
                printf("Preço: %s\n", compralencontrada.preco);
                printf("Data da compra: %s/%s/%s\n", compralencontrada.dia, compralencontrada.mes, compralencontrada.ano);
                printf("ID: %s\n", compralencontrada.id);
                printf("Quantidade: %s\n", compralencontrada.quantidade);
                break;
            }
        }

        fclose(arquivocompra);

        if (!encontrado) {
            printf("Compra não encontrada\n");
        }

        printf("Deseja ler outra compra? (S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        switch (respt) {
            case 'S':
            case 's':
                continue;
            case 'N':
            case 'n':
                MenuCompras(0);
            default:
                printf("Opção inválida\n");
                MenuCompras(0);
        }
    }
}

void ListagemCompras(void) {
    Compra compralistagem;

    LimpaTela();
    printf("Lista de todas as compras:\n\n");

    FILE *arquivocompra = fopen("compras.dat", "rb");
    
    if (arquivocompra == NULL) {
        printf("Erro ao abrir o arquivo de compras.dat\n");
        return;
    }

    while (fread(&compralistagem, sizeof(Compra), 1, arquivocompra) == 1) {
        if (compralistagem.ativa) {
            printf("============================================================================\n");
            printf("\n");
            printf("Nome: %s\n", compralistagem.nome);
            printf("Categoria: %s\n", compralistagem.produto);
            printf("Preço: %s\n", compralistagem.preco);
            printf("Data da compra: %s/%s/%s\n", compralistagem.dia, compralistagem.mes, compralistagem.ano);
            printf("ID: %s\n", compralistagem.id);
            printf("Quantidade: %s\n", compralistagem.quantidade);
            printf("\n");
            printf("\t> tecle <ENTER> para pular a próxima compra < <\n");
            printf("============================================================================\n");
            getchar(); 
        }
    }

    fclose(arquivocompra);

    printf("\nVoltando ao menu de compras\n");
    pausa();
    MenuCompras();
}

void TresMaisCaras(void){
    LimpaTela();
    FILE *arquivoCompra = fopen("compras.dat", "rb");

    if (arquivoCompra == NULL) {
        printf("Eerro ao abrir arquivo compras.dat\n");
        return;
    }

    Compra com[3];
    int numCompras = 0;

    while (fread(&com[numCompras], sizeof(Compra), 1, arquivoCompra) == 1) {
        numCompras++;
    }

    fclose(arquivoCompra);

    for (int i = 0; i < numCompras - 1; i++) {
        for (int j = i + 1; j < numCompras; j++) {
            if (atof(com[i].preco) < atof(com[j].preco)) {
                Compra temp = com[i];
                com[i] = com[j];
                com[j] = temp;
            }
        }
    }

    printf("Tres compras mais caras:\n");
    int limite = numCompras < 3 ? numCompras : 3;
    for (int i = 0; i < limite; i++) {
        printf("============================================================================\n");
        printf("\n");
        printf("Categoria: %s\n", com[i].produto);
        printf("Preço: %s\n", com[i].preco);
        printf("Data da compra: %s/%s/%s\n", com[i].dia, com[i].mes, com[i].ano);
        printf("ID: %s\n", com[i].id);
        printf("Quantidade: %s\n", com[i].quantidade);
        printf("\t> tecle <ENTER> para pular a proxima compra < <\n");
        printf("============================================================================\n");
        getchar(); 
        printf("\n");
    }
    printf("\nVoltando ao menu de compras\n");
    pausa();
    MenuCompras();
}

void SalvarCompra(Compra* com){
    FILE* arquivocompras;
    arquivocompras = fopen("compras.dat", "ab");

    if (arquivocompras == NULL){
        printf("erro\n");
        return;
    }

    fwrite(com, sizeof(Compra), 1, arquivocompras);

    fclose(arquivocompras);
}