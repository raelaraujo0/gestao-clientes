#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cbclho.h"


Venda* SubTelaRegVen(void)
{
    Venda *ven;
    ven = (Venda*)malloc(sizeof(Venda));

    if(ven == NULL){
        printf("erro na alocacao de memoia \n");
        return NULL;
    }

    bool datavalida;
    bool categoriaval = false;
    bool precovalido = false;
    bool nomevalido = false;
    
    char respt;

    while (1)
    {
        system("clear || cls");
        Tela_RegVen();

    do{
        printf("Digite seu nome:");
        fgets(ven->nome, sizeof(ven->nome), stdin);
        ven->nome[strcspn(ven->nome, "\n")] = '\0';
        limparBuffer();

        nomevalido = validarnome(ven->nome);

        if (!nomevalido){
            printf("Nome invalido, tente novamente.");
        }

    }while(!nomevalido);

    do{
        printf("Informe o preço (apenas numeros): ");
        scanf("%20s", ven->preco);
        limparBuffer();
        ven->preco[strcspn(ven->preco, "\n")] = '\0';

        precovalido = verificapreco(ven->preco);

        if(!precovalido){
            printf("isso nao e um valor, tente novamente\n");
        }
    } while (!precovalido);


    do {
        printf("insira dia da venda: ");
        fgets(ven->dia, sizeof(ven->dia), stdin);
        limparBuffer();

        printf("insira mes da venda: ");
        fgets(ven->mes, sizeof(ven->mes), stdin);
        limparBuffer();

        printf("insira ano da venda: ");
        fgets(ven->ano, sizeof(ven->ano), stdin);
        limparBuffer();

        datavalida = validardata(ven->dia, ven->mes, ven->ano);

        if (!datavalida){
            printf("Data invalida, tente novamente \n");
            }
            } while (!datavalida); limparBuffer();

        do {
            printf("Categoria da venda:");
            scanf("%s", ven->categoria);
            limparBuffer();

            categoriaval = validarcategoria(ven->categoria);

            if (!categoriaval){
                printf("A categoria esta incorreta, tente novamente \n");
            }
            } while (!categoriaval);

        printf("Informe a quantidade de itens vendidos:");
        scanf("%s", ven->quantidade);
        limparBuffer();

        ven->ativa = 1;

        ven->nome;

        snprintf(ven->id,sizeof(ven->id), "%s%s%s%s", ven->ano, ven->preco, ven->dia, ven->mes);

        salvarvenda(ven);
        free(ven);

        printf("venda cadastrada!, para fazer alterações sera esse seu id >> %s%s%s%s <<\n\n", ven->ano, ven->preco, ven->dia, ven->mes);

        printf("Deseja adicionar outra venda?(S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            SubTelaRegVen();
            break;
        case 'N':
        case 'n':
            menuVendas();
            break;
        default:
            printf("Funcao invalida");
            return ven;
        }
    }
}

void SubTelaDelVen(void)
{
    Venda ven;
    char respt;
    char respt2;
    char id[20];

    while (1)
    {
        system("clear || cls");
        Tela_DelVen();

        printf("Digite id da venda: ");
        scanf("%s", id);
        limparBuffer();

        FILE *arquivovenda = fopen("vendas.dat", "rb+");

        if (arquivovenda == NULL)
        {
            printf("Erro\n");
            return;
        }

        while (fread(&ven, sizeof(Venda), 1, arquivovenda) == 1){
            if (strcmp(ven.id, id) == 0)
            {
                ven.ativa = 0;//venda nao mais ativa
                fseek(arquivovenda, -sizeof(Venda), SEEK_CUR);
                fwrite(&ven, sizeof(Venda), 1, arquivovenda);
                break;
            }
        }

        fclose(arquivovenda);

        if(ven.ativa == 0){
            printf("deseja deletar esta venda? (S/N)\n");
            scanf(" %c", &respt2);
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
    char id[20];
    char respt;
    Venda vendaatt;

    bool datavalida = false;
    bool categoriaval = false;

    while (1)
    {
        system("clear || cls");
        Tela_AttVen();

        printf("Digite id da venda:");
        scanf("%s", id);
        limparBuffer();

        FILE* arquivovenda = fopen("vendas.dat", "rb+");
        int encontrado = 0;
        long posicao_anterior = 0;

        while (fread(&vendaatt, sizeof(Venda), 1, arquivovenda) == 1){
            if(strcmp(vendaatt.id, id) == 0){
                encontrado = 1;
                break;
            }
            posicao_anterior = ftell(arquivovenda) - sizeof(Venda);
        }

        fclose(arquivovenda);

        if(encontrado == 0){
            printf("Venda nao encontrada \n");
            continue;
        }
        do {
            printf("Categoria da venda:");
            scanf("%s", vendaatt.categoria);
            categoriaval = validarcategoria(vendaatt.categoria);

            if (!categoriaval){
                printf("A categoria esta incorreta, tente novamente \n");
            }
        } while (!categoriaval); limparBuffer();

        printf("Preco:");
        scanf("%s", vendaatt.preco); limparBuffer();

        do {
            printf("insira dia da venda: ");
            fgets(vendaatt.dia , sizeof(vendaatt.dia), stdin);
            limparBuffer();
            printf("insira mes da venda: ");
            fgets(vendaatt.mes , sizeof(vendaatt.mes), stdin);
            limparBuffer();
            printf("insira ano da venda: ");
            fgets(vendaatt.ano , sizeof(vendaatt.ano), stdin);
            limparBuffer();
        datavalida = validardata(vendaatt.dia, vendaatt.mes, vendaatt.ano);
        if (!datavalida){
            printf("Data invalida, tente novamente \n");
            }
            } while (!datavalida); limparBuffer();

        printf("Informe a quantidade:");
        fgets(vendaatt.quantidade, sizeof(vendaatt.quantidade), stdin); limparBuffer();

        snprintf(vendaatt.id,sizeof(vendaatt.id), "%s%s%s%s", vendaatt.ano, vendaatt.preco, vendaatt.dia, vendaatt.mes);
        printf("venda alterada!, para fazer alterações sera esse seu id >> %s%s%s%s <<\n\n", vendaatt.ano, vendaatt.preco, vendaatt.dia, vendaatt.mes);

        // Vá para a posição anterior no arquivo para sobrescrever a venda
        arquivovenda = fopen("vendas.dat", "rb+");
        fseek(arquivovenda, posicao_anterior, SEEK_SET);
        fwrite(&vendaatt, sizeof(Venda), 1, arquivovenda);
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
    Venda vendaencontrada;
    char id[20];
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

        printf("Digite id da venda: ");
        scanf("%s", id);
        limparBuffer();

        while (fread(&vendaencontrada, sizeof(Venda), 1, arquivovenda) == 1){
            if (strcmp(vendaencontrada.id, id) == 0)
            {
                found = true;
                printf("Informacoes da venda:\n");
                printf("Vendedor: %s\n", vendaencontrada.nome);
                printf("Categoria: %s\n", vendaencontrada.categoria);
                printf("Preco: %s\n", vendaencontrada.preco);
                printf("Data da venda: %s/%s/%s\n", vendaencontrada.dia, vendaencontrada.mes, vendaencontrada.ano);
                printf("id: %s\n", vendaencontrada.id);
                printf("Quantidade: %s\n", vendaencontrada.quantidade);
                break;
            }
        }

        fclose(arquivovenda);

        if (!found)
        {
            printf("id errada ou inexistente.\n");
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
    FILE* arquivovendas = fopen("vendas.dat", "rb");
    if (arquivovendas == NULL)
    {
        printf("Erro\n");
        return;
    }

    fseek(arquivovendas, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivovendas);
    rewind(arquivovendas);

    int num_vendas = tamanho_arquivo / sizeof(Venda);
    Venda* vendas = (Venda*)malloc(num_vendas * sizeof(Venda));

    fread(vendas, sizeof(Venda), num_vendas, arquivovendas);

    if (num_vendas > 0)
    {
        printf("Lista de vendas:\n");

        for (int i = 0; i < num_vendas; i++)
        {
            printf("==================================================================\n");
            printf("\n");
            printf("Vendedor: %s\n", vendas[i].nome);
            printf("Preco: %s\n", vendas[i].preco);
            printf("Data: %s/%s/%s\n", vendas[i].dia, vendas[i].mes, vendas[i].ano);
            printf("Categoria: %s\n", vendas[i].categoria);
            printf("Id: %s\n", vendas[i].id);
            printf("Quantidade: %s\n", vendas[i].quantidade);
            printf("\n");
            printf("\t> tecle <ENTER> para pular a venda <\n");
            getchar();
        }
    }

    free(vendas);
    fclose(arquivovendas);
}

void ListagemCatePrec(void)
{
    FILE* arquivovendas = fopen("vendas.dat", "rb");
    if (arquivovendas == NULL)
    {
        printf("Erro\n");
        return;
    }

    fseek(arquivovendas, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivovendas);
    rewind(arquivovendas);

    int num_vendas = tamanho_arquivo / sizeof(Venda);
    Venda* vendas = (Venda*)malloc(num_vendas * sizeof(Venda));

    fread(vendas, sizeof(Venda), num_vendas, arquivovendas);

    if (num_vendas > 0)
    {
        printf("Lista de vendas:\n");

        for (int i = 0; i < num_vendas; i++)
        {
            printf("==================================================================\n");
            printf("Categoria: %s\n", vendas[i].categoria);
            printf("Preco: %s\n", vendas[i].preco);
            printf("Quantidade: %s\n", vendas[i].quantidade);
            printf("\n");
            printf("\t> tecle <ENTER> para pular a venda <\n");
            getchar();
        }
    }
    else
    {
        printf("Nenhuma venda cadastrada.\n");
    }

    free(vendas);
    fclose(arquivovendas);
}

void salvarvenda(Venda* ven){

    FILE* arquivovendas;
    arquivovendas = fopen("vendas.dat", "ab");

    if (arquivovendas == NULL){
        printf("erro\n");
        return;
    }

    fwrite(ven, sizeof(Venda), 1, arquivovendas);

    fclose(arquivovendas);
}


