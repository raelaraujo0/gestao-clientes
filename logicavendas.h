#ifndef LOGICAVENDAS_H
#define LOGICAVENDAS_H

typedef struct ven Venda;
struct ven{
    char id;
    char preco[10];
    char dia[3], mes[3], ano[5];
    char categoria[20];
    char quantidade[4];
    char nome[15];
    int ativa;
};

Venda* SubTelaRegVen(const char* nomeVendedor);

void SubTelaDelVen(void);

void SubTelaAttVen(void);

void SubTelaLerVen(void);

void SubTelaListarVen(void);

void salvarvenda(Venda* venda);

void listagemvendasformat(Venda* venda);

#endif