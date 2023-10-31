#ifndef VALIDADORES_H
#define VALIDADORES_H
#include <stdbool.h>

bool validardata(int dia, int mes, int ano);

bool validarnome(char* nome, char* sobrenome);

bool validarcategoria(const char* categoria);

bool validarcpf(char* cpf);

bool validartelefone(const char* telefone);

bool validaremail(const char* email);

#endif