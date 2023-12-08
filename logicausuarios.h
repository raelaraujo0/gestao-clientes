#ifndef LOGICAUSUARIOS_H
#define LOGICAUSUARIOS_H

typedef struct usuario Usuario;
struct usuario{
    char nome[15];
    char sobrenome[15];
    char cpf[12];
    char dia[2], mes[2], ano[4];
    char telefone[12];
    char email[25];
    char senha[50];
    int ativo;
};

Usuario* SubTelaCadUsu(void);

void SubTelaDelUsu(void);

void SubTelaAttUsu(void);

void SubTelaLerUsu(void);

void SubTelaListarUsu(void);

void listagem_alf(void);

void Login(void);

#endif
