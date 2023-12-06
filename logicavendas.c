#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cbclho.h"

Venda* SubTelaRegVen()
{
    Venda *venda;
    bool datavalida;
    bool categoriaval = false;
    char respt;

    FILE *arquivovenda;
    arquivovenda = fopen("vendas.txt", "a");
    if (arquivovenda == NULL){
        printf("erro");
        exit(1);
    }

    while (1)
    {
        system("clear || cls");
        Tela_RegVen();

        printf("Informe o preco:");
        scanf("%f", &venda->preco); getchar();

    do {
        printf("insira dia da venda: ");
        scanf("%d", &venda->dia);
        getchar();
        printf("insira mes da venda: ");
        scanf("%d", &venda->mes);
        getchar();
        printf("insira ano da venda: ");
        scanf("%d", &venda->ano);
        getchar();
        datavalida = validardata(venda->dia, venda->mes, venda->ano);
        if (!datavalida){
            printf("Data invalida, tente novamente \n");
            }
            } while (!datavalida); getchar();

        do {
            printf("Categoria da venda:");
            fgets(venda->categoria, sizeof(venda->categoria), stdin);
            venda->categoria[strcspn (venda->categoria, "\n")] = '\0';
            categoriaval = validarcategoria(venda->categoria);

            if (!categoriaval){
                printf("A categoria esta incorreta, tente novamente \n");
            }
            } while (!categoriaval); getchar();

        snprintf(venda->tag, sizeof(venda->tag), "%s.%.2f.%d", venda->categoria, venda->preco, venda->dia);

        printf("venda cadastrada!, para fazer alterações sera essa sua tag >> %s <<\n\n", venda->tag);

        printf("Deseja adicionar outra venda?(S/N)");
        scanf(" %c", &respt);
        getchar();

        fprintf(arquivovenda, "Preço: %.2f, Data: %d/%d/%d, Categoria: %s\n, Tag: %s\n", venda->preco[0], venda->dia[0], venda->mes[0], venda->ano[0], venda->categoria, venda->tag);   
        fclose(arquivovenda);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            SubTelaRegVen();
        case 'N':
        case 'n':
            menuVendas();
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaDelVen(Venda *venda)
{
    char line[255];  
    char respt;
    char tag;

    while (1)
    {
        system("clear || cls");
        Tela_DelVen();

        printf("Digite tag da venda: ");
        scanf("%s", tag);
        getchar();

        FILE* arquivovenda = fopen("vendas.txt", "r");
        FILE* novoarquivovenda = fopen("novoarquivovenda->txt", "w");
        while(fgets(line, sizeof(line), arquivovenda) != NULL){
            if(strcmp(line, tag) != 0){
                fputs(line, novoarquivovenda);
            }
        }
        fclose(arquivovenda);
        fclose(novoarquivovenda);

        // exclusao fisica do arquivo de vendas
        remove("vendas.txt");
        rename("novoarquivovendas.txt", "vendas.txt");

        printf("Deseja deletar outra venda?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            continue;
        case 'N':
        case 'n':
            menuVendas();
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaAttVen(Venda *venda)
{   
    char tag;
    char respt;
    while (1)
    {
        system("clear || cls");
        Tela_AttVen();

        printf("Digite tag da venda:");
        scanf("%s", tag);
        getchar();

        FILE* arquivovenda = fopen("vendas.txt", "r+b");
        Venda venda_encontrada;
        int encontrado = 0;
        while(fscanf(arquivovenda, "%s;%f;%d/%d/%d;%s", venda_encontrada.categoria, venda_encontrada.preco, &venda_encontrada.dia, &venda_encontrada.mes, &venda_encontrada.ano, venda_encontrada.tag) != EOF){
            if(strcmp(venda_encontrada.tag, venda->tag) == 0){
                encontrado = 1;
                break;
            }
        }
        fclose(arquivovenda);

        if(encontrado == 0){
            printf("Venda nao encontrada \n");
            continue;
        }
        printf("Categoria:");
        fgets(venda->categoria, sizeof(venda->categoria), stdin); getchar();

        printf("Preco:");
        fgets(venda->preco, sizeof(venda->preco), stdin); getchar();

        printf("Dia da venda:");
        fgets(venda->dia, sizeof(venda->dia), stdin); getchar();
        printf("Mes da venda:");
        fgets(venda->mes, sizeof(venda->mes), stdin); getchar();
        printf("Ano da venda:");
        fgets(venda->ano, sizeof(venda->ano), stdin); getchar();

        arquivovenda = fopen("vendas.txt", "w");
        fprintf(arquivovenda, "%s;%f;%d/%d/%d;%s", venda->categoria, venda->preco, venda->dia, venda->mes, venda->ano, venda->tag);
        fclose(arquivovenda);

        printf("Deseja atualizar outra venda?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            continue;
        case 'N':
        case 'n':
            menuVendas();
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaLerVen(Venda *venda)
{   char tag;
    char respt;
    char line[255];
    bool found = false;
    while (1)
    {
        system("clear || cls");
        Tela_LerVen();

        FILE* arquivovenda;
        arquivovenda = fopen("vendas.txt", "r");
        if (arquivovenda == NULL){
            printf("erro");
        }

        printf("Digite tag da venda: ");
        scanf("%s", tag);
        getchar();

        while(fgets(line, sizeof(line), arquivovenda) != NULL){
            char* token = strtok(line, ",");
            if (token != NULL && strcmp(token, venda->tag) == 0){
                found = true;
                printf("Informacoes da venda:\n");
                printf("Categoria: %s\n", venda->categoria);
                printf("Preco: %s\n", venda->preco);
                printf("Data da venda:%d/%d/%d\n", &venda->dia, &venda->mes, &venda->ano);
                printf("Tag: %s\n", venda->tag);
                break;
            }
        } fclose(arquivovenda);
        if (found == false){
            printf("Tag errada ou inexistente \n");
        }

        printf("Deseja ler outra venda?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            continue;
        case 'N':
        case 'n':
            menuVendas();
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaListarVen(Venda *venda)
{
    FILE* arquivovenda = fopen("vendas.txt", "r");

    printf("Lista das vendas:\n");
    while(true){
        if (fscanf(arquivovenda, "%s;%s;%d/%d/%d", venda->categoria, venda->preco, venda->dia[0], venda->mes[0], venda->ano[0]) != EOF){
            printf("Categoria: %s\nPreco:%s\nData da venda: %d/%d/%d, Tag: %s\n", venda->categoria, venda->preco, venda->dia[0], venda->mes[0], venda->ano[0], venda->tag);   
        } else {
            break;
        }
    }
    fclose(arquivovenda);
}
