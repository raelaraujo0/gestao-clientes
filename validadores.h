#ifndef VALIDADORES_H
#define VALIDADORES_H

int validardata(char* dia, char* mes, char* ano);

int validarnome(char* nome, char* sobrenome);

int validarcategoria(const char* categoria);

int validarcpf(char* cpf);

int validartelefone(const char* telefone);

int validaremail(const char* email);

int comparador(const void* a, const void* b);

int comparador_vendas(const void* a, const void* b);

#endif
