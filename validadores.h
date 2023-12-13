#ifndef VALIDADORES_H
#define VALIDADORES_H

int validardata(char* dia, char* mes, char* ano);

int validarnome(char* nome, char* sobrenome);

int validarcategoria(const char* categoria);

int validarcpf(char* cpf);

int validartelefone(const char* telefone);

int validaremail(const char* email);

int comparador(const void* a, const void* b);

int verificapreco(const char* preco);
#endif
