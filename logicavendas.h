#ifndef LOGICAVENDAS_H
#define LOGICAVENDAS_H

typedef struct ven Venda;
struct ven{
    char id[31];
    char preco[20];
    char dia[3], mes[3], ano[5];
    char categoria[20];
    char quantidade[20];
    char nome[40];
    int ativa;
};

Venda* SubTelaRegVen(void);

void SubTelaDelVen(void);

void SubTelaAttVen(void);

void SubTelaLerVen(void);

void SubTelaListarVen(void);

void ListagemCatePrec(void);

void salvarvenda(Venda* venda);

#endif