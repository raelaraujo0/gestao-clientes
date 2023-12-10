#ifndef LOGICAUSUARIOS_H
#define LOGICAUSUARIOS_H

typedef struct usu Usuario;
struct usu{
    char nome[15];
    char sobrenome[15];
    char cpf[12];
    char dia[3], mes[3], ano[5];
    char telefone[12];
    char email[25];
    char senha[30];
    int ativo;
};

Usuario* SubTelaCadUsu(void);

void SubTelaDelUsu(void);

void SubTelaAttUsu(void);

void SubTelaLerUsu(void);

void SubTelaListarUsu(void);

void listagem_alf(void);

void Login(void);

void salvarusuario(Usuario *usuario);

#endif
