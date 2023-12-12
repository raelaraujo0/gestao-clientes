#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cbclho.h"

void Login(void)
{
    Usuario* usuario;
    char senha[50];
    char nome[12];
    while (1)
    {
        system("clear || cls");
        Tela_Login();

        printf("Digite seu nome: ");
        scanf("%s", nome); 
        limparBuffer();

        printf("Digite sua senha: ");
        scanf("%s", senha); 
        limparBuffer();

        FILE* arquivousuarios = fopen("usuarios.dat", "r");
        Usuario usuario_encontrado;
        int encontrado = 0;
        while (fread(arquivousuarios, "Nome: %s, Senha: %s\n",
            usuario_encontrado.nome, usuario_encontrado.senha) != EOF)
        {
            if (strcmp(usuario->nome, usuario_encontrado.nome) == 0 && strcmp(usuario->senha, usuario_encontrado.senha) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        fclose(arquivousuarios);

        if(encontrado == 1)
        {
            menuVendas();
            break;
        } else {
            printf("Usuario nao encontrado. Deseja cadastrar um novo usuario? (S/N)\n");
            char respt;
            scanf("%c", &respt);
            limparBuffer();

            if (respt == 'S' || respt == 's')
            {
                SubTelaCadUsu();
                break;
            } else {
                break;
            }
        }
    }
}


Venda* SubTelaRegVen(void)
{
    Venda *ven;
    ven = (Venda*)malloc(sizeof(Venda));

    bool datavalida;
    bool categoriaval = false;
    
    char respt;

    while (1)
    {
        system("clear || cls");
        Tela_RegVen();

        printf("Informe o preco:");
        scanf("%s", &ven->preco); 
        limparBuffer();

    do {
        printf("insira dia da venda: ");
        fgets(ven->dia , sizeof(ven->dia), stdin);
        limparBuffer();
        printf("insira mes da venda: ");
        fgets(ven->mes , sizeof(ven->mes), stdin);
        limparBuffer();
        printf("insira ano da venda: ");
        scanf("%2s", ven->ano);
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

        snprintf(ven->id,sizeof(ven->id), "%s%s%s%s", ven->ano, ven->preco, ven->dia, ven->mes);

        salvarvenda(ven);

        printf("venda cadastrada!, para fazer alterações sera esse seu id >> %s <<\n\n", ven->id);

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
            if (strcmp(venda.id, id) == 0)
            {
                venda.ativa = 0;//venda nao mais ativa
                fseek(arquivovenda, -sizeof(Venda), SEEK_CUR);
                fwrite(&ven, sizeof(Venda), 1, arquivovenda);
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
    char id;
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
        while(fread(&vendaatt, sizeof(Venda), 1, arquivovenda) == 1){
            if(strcmp(vendaatt.id, id) == 0){
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

        fseek(arquivovenda, -sizeof(Venda), SEEK_CUR);
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
    Venda ven;
    FILE *arquivovenda = fopen("vendas.dat", "rb");

    if (arquivovenda == NULL)
    {
        printf("Erro\n");
        return;
    }

    printf("%-8s %-15s %-12s %-10s %-s\n", "Preco", "Categoria", "Data da Venda", "id", "Quantidade");
    while (fread(&ven, sizeof(Venda), 1, arquivovenda) == 1)
    {
        listagemvendasformat(&ven);
    }

    fclose(arquivovenda);
}

void listarcategoria(const char* categoria)
{
    Venda ven;
    FILE* arquivovenda = fopen("vendas.dat", "rb");
    if (arquivovenda == NULL){
        printf("erro \n");
    }
    while(fread(&ven, sizeof(Venda),1, arquivovenda) == 1){
        if(strcmp(ven.categoria, categoria) == 0){
            printf("Categorias: %s\n", ven.categoria);
        }
    }
    fclose(arquivovenda);

}

void salvarvenda(Venda* ven){

    FILE *arquivovendas;
    arquivovendas = fopen("vendas.dat", "ab");

    if (arquivovendas == NULL){
        printf("erro\n");
        return;
    }

    fwrite(ven, sizeof(Venda), 1, arquivovendas);

    fclose(arquivovendas);
    free(ven);

}

void listagemvendasformat(Venda* ven)
{
    printf("%-8s %-15s %-12s %-10s %-s\n", venda->preco, venda->categoria, venda->dia, venda->mes, venda->ano, venda->quantidade);
}
