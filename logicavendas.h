#ifndef LOGICAVENDAS_H
#define LOGICAVENDAS_H

typedef struct venda Venda;
struct venda{
    float preco[50];
    int dia[2], mes[2], ano[4];
    char categoria[20];
    char tag[20];
};

Venda* SubTelaRegVen(void);

void SubTelaDelVen();

void SubTelaAttVen();

void SubTelaLerVen();

void SubTelaListarVen();

#endif