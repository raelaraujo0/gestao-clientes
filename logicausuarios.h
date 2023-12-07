#ifndef LOGICAUSUARIOS_H
#define LOGICAUSUARIOS_H

typedef struct usuario Usuario;
struct usuario{
    char telefone[11];
    char email[20];
    char nome[15];
    char sobrenome[15];
    char cpf[12];
    int dia[2], mes[2], ano[4];
    char senha[50];
    int ativo;
};

Usuario* SubTelaCadUsu(void);

void SubTelaDelUsu();

void SubTelaAttUsu();

void SubTelaLerUsu();

void SubTelaListarUsu();

void Login();

#endif
