#ifndef LOGICAUSUARIOS_H
#define LOGICAUSUARIOS_H

typedef struct usuario Usuario;
struct usuario{
    char telefone[100];
    char email[50];
    char nome[100];
    char sobrenome[100];
    char cpf[12];
    int dia[3], mes[3], ano[5];
    char senha[250];
    int ativo;
};

Usuario* SubTelaCadUsu(void);

void SubTelaDelUsu();

void SubTelaAttUsu();

void SubTelaLerUsu();

void SubTelaListarUsu();

void Login();

#endif
