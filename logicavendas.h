#ifndef LOGICAVENDAS_H
#define LOGICAVENDAS_H

typedef struct ven Venda;
struct ven{
    char id[12];;
    char preco[40];
    char dia[2], mes[2], ano[5];
    char categoria[15];
    char quantidade[20];
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