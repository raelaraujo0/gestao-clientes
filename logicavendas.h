#ifndef LOGICAVENDAS_H
#define LOGICAVENDAS_H

typedef struct venda Venda;
struct venda{
    char preco[10];
    char dia[2], mes[2], ano[4];
    char categoria[20];
    char tag[10];
    char quantidade[4];
    int ativa;
};

Venda* SubTelaRegVen(void);

void SubTelaDelVen(void);

void SubTelaAttVen(void);

void SubTelaLerVen(void);

void SubTelaListarVen(void);

#endif