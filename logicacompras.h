#ifndef LOGICACOMPRAS_H
#define LOGICACOMPRAS_H

typedef struct com Compra;
struct com{
    char id[31];
    char preco[20];
    char dia[3], mes[3], ano[5];
    char produto[20];
    char quantidade[20];
    char nome[40];
    int ativa;
};

Compra* CriarCompra(void);

void AtualizarCompra(void);

void DeletarCompra(void);

void LerCompra(void);

void ListagemCompras(void);

void TresMaisCaras(void);

void SalvarCompra(Compra* com);

#endif