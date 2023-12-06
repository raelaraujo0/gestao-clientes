#ifndef VALIDADORES_H
#define VALIDADORES_H

int validardata(int dia, int mes, int ano);

int validarnome(char* nome, char* sobrenome);

int validarcategoria(const char* categoria);

int validarcpf(char* cpf);

int validartelefone(const char* telefone);

int validaremail(const char* email);

#endif
