#ifndef LOGICAVENDAS_H
#define LOGICAVENDAS_H

typedef struct venda Venda;
struct venda{
    float preco[1000];
    int dia[3], mes[3], ano[5];
    char categoria[100];
    char tag[450];
};

Venda* SubTelaRegVen(void);

void SubTelaDelVen();

void SubTelaAttVen();

void SubTelaLerVen();

void SubTelaListarVen();

#endif