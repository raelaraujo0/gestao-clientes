#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cbclho.h"

Venda* SubTelaRegVen()
{
    Venda *venda;
    venda = (Venda*)malloc(sizeof(Venda));

    bool datavalida;
    bool categoriaval = false;
    
    char respt;

    FILE *arquivovenda = fopen("vendas.dat", "w");
    if (arquivovenda == NULL){
        printf("erro");
        exit(1);
    }

    while (1)
    {
        system("clear || cls");
        Tela_RegVen();

        printf("Informe o preco:");
        scanf("%s", &venda->preco); limparBuffer();

    do {
        printf("insira dia da venda: ");
        scanf("%s", &venda->dia);
        limparBuffer();
        printf("insira mes da venda: ");
        scanf("%s", &venda->mes);
        limparBuffer();
        printf("insira ano da venda: ");
        scanf("%s", &venda->ano);
        limparBuffer();
        datavalida = validardata(venda->dia, venda->mes, venda->ano);
        if (!datavalida){
            printf("Data invalida, tente novamente \n");
            }
            } while (!datavalida); limparBuffer();

        do {
            printf("Categoria da venda:");
            fgets(venda->categoria, sizeof(venda->categoria), stdin);
            venda->categoria[strcspn (venda->categoria, "\n")] = '\0';
            categoriaval = validarcategoria(venda->categoria);

            if (!categoriaval){
                printf("A categoria esta incorreta, tente novamente \n");
            }
            } while (!categoriaval); limparBuffer();

        snprintf(venda->tag, sizeof(venda->tag), "%s.%s.%s", venda->categoria, venda->preco, venda->dia);

        printf("venda cadastrada!, para fazer alterações sera essa sua tag >> %s <<\n\n", venda->tag);

        printf("Deseja adicionar outra venda?(S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        fprintf(arquivovenda, "Preço: %s, Data: %s/%s/%s, Categoria: %s, Tag: %s\n", venda->preco, venda->dia, venda->mes, venda->ano, venda->categoria, venda->tag);   
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

void SubTelaDelVen(void)
{
    Venda venda;
    char respt;
    char tag[20];
    char respt2;

    while (1)
    {
        system("clear || cls");
        Tela_DelVen();

        printf("Digite tag da venda: ");
        scanf("%s", tag);
        limparBuffer();

        FILE *arquivovenda = fopen("vendas.dat", "rb+");

        if (arquivovenda == NULL)
        {
            printf("Erro ao abrir o arquivo de vendas.\n");
            return;
        }

        while (fread(&venda, sizeof(Venda), 1, arquivovenda) == 1)
        {
            if (strcmp(venda.tag, tag) == 0)
            {
                venda.ativa = 0;//venda nao mais ativa
                fseek(arquivovenda, -sizeof(Venda), SEEK_CUR);
                fwrite(&venda, sizeof(Venda), 1, arquivovenda);
                break;
            }
        }

        fclose(arquivovenda);

        if(venda.ativa == 0){
            printf("deseja deletar esta venda? (S/N)\n");
            scanf("%c", &respt2);
            limparBuffer();
            if (respt2 == 'S' || 's'){
                printf("venda marcada como inativa\n");
                menuVendas();
            } else {
                printf("deu errado :c \n");
            }
        } else {
            printf("Venda nao encontrada \n");


        printf("Deseja deletar outra venda? (S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        // Função de loop para caso queira fazer a operação novamente, voltar à função, senão ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            continue;
        case 'N':
        case 'n':
            menuVendas();
        default:
            printf("Funcao invalida\n");
            return;
            }
        }
    }
}

void SubTelaAttVen(void)
{   
    char tag;
    char respt;
    Venda *vendaatt;

    bool datavalida = false;
    bool categoriaval = false;

    while (1)
    {
        system("clear || cls");
        Tela_AttVen();

        printf("Digite tag da venda:");
        scanf("%s", tag);
        limparBuffer();

        FILE* arquivovenda = fopen("vendas.dat", "rb+");
        int encontrado = 0;
        while(fread(&vendaatt, sizeof(Venda), 1, arquivovenda) == 1){
            if(strcmp(vendaatt->tag, tag) == 0){
                encontrado = 1;
                break;
            }
        }
        fclose(arquivovenda);

        if(encontrado == 0){
            printf("Venda nao encontrada \n");
            continue;
        }
        do {
            printf("Categoria da venda:");
            scanf("%s", vendaatt->categoria);
            vendaatt->categoria[strcspn (vendaatt->categoria, "\n")] = '\0';
            categoriaval = validarcategoria(vendaatt->categoria);

            if (!categoriaval){
                printf("A categoria esta incorreta, tente novamente \n");
            }
        } while (!categoriaval); limparBuffer();

        printf("Preco:");
        scanf("%s", vendaatt->preco); limparBuffer();

        do {
        printf("insira dia da venda: ");
        scanf("%s", &vendaatt->dia);
        limparBuffer();
        printf("insira mes da venda: ");
        scanf("%s", &vendaatt->mes);
        limparBuffer();
        printf("insira ano da venda: ");
        scanf("%s", &vendaatt->ano);
        limparBuffer();
        datavalida = validardata(vendaatt->dia, vendaatt->mes, vendaatt->ano);
        if (!datavalida){
            printf("Data invalida, tente novamente \n");
            }
            } while (!datavalida); limparBuffer();

        arquivovenda = fopen("vendas.dat", "w");
        fprintf(arquivovenda, "%s;%s;%s/%s/%s;%s", vendaatt->categoria, vendaatt->preco, vendaatt->dia, vendaatt->mes, vendaatt->ano, vendaatt->tag);
        fclose(arquivovenda);

        printf("Deseja atualizar outra venda?(S/N)");
        scanf(" %c", &respt);
        limparBuffer();

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

void SubTelaLerVen(void)
{
    Venda venda;
    char tag[20];
    char respt;
    bool found = false;

    while (1)
    {
        system("clear || cls");
        Tela_LerVen();

        FILE *arquivovenda = fopen("vendas.dat", "rb");
        if (arquivovenda == NULL)
        {
            printf("Erro\n");
            return;
        }

        printf("Digite tag da venda: ");
        scanf("%s", tag);
        limparBuffer();

        while (fread(&venda, sizeof(Venda), 1, arquivovenda) == 1){
            if (strcmp(venda.tag, tag) == 0)
            {
                found = true;
                printf("Informacoes da venda:\n");
                printf("Categoria: %s\n", venda.categoria);
                printf("Preco: %s\n", venda.preco);
                printf("Data da venda: %s/%s/%s\n", venda.dia, venda.mes, venda.ano);
                printf("Tag: %s\n", venda.tag);
                break;
            }
        }

        fclose(arquivovenda);

        if (!found)
        {
            printf("Tag errada ou inexistente.\n");
        }

        printf("Deseja ler outra venda? (S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        // Função de loop para caso queira fazer a operação novamente, voltar à função, senão ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            continue;
        case 'N':
        case 'n':
            menuVendas();
        default:
            printf("Funcao invalida\n");
            return;
        }
    }
}

void SubTelaListarVen(void)
{
    Venda venda;
    FILE *arquivovenda = fopen("vendas.dat", "rb");

    if (arquivovenda == NULL){
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    printf("Lista das vendas:\n");
    while (fread(&venda, sizeof(Venda), 1, arquivovenda) == 1)
    {
        printf("Categoria: %s\nPreco:%s\nData da venda: %s/%s/%s, Tag: %s\n", venda.categoria, venda.preco, venda.dia, venda.mes, venda.ano, venda.tag);
    }

    fclose(arquivovenda);
}

void listarcategoria(const char* categoria)
{
    Venda venda;
    FILE* arquivovenda = fopen("vendas.dat", "rb");
    if (arquivovenda == NULL){
        printf("erro \n");
    }
    while(fread(&venda, sizeof(Venda),1, arquivovenda) == 1){
        if(strcmp(venda.categoria, categoria) == 0){
            printf("Categorias: %s\n", venda.categoria);
        }
    }
    fclose(arquivovenda);

}