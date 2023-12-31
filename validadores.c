#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cbclho.h"
#include <stdbool.h>

int validardata(char* dia, char* mes, char* ano)
{
    int dia_int, mes_int, ano_int;

    if (sscanf(dia, "%d", &dia_int) != 1 ||
        sscanf(mes, "%d", &mes_int) != 1 ||
        sscanf(ano, "%d", &ano_int) != 1) {
        return false;
    }

    if (ano_int < 0 || ano_int > 2023 || mes_int < 1 || mes_int > 12 || dia_int < 1 || dia_int > 31) {
        return false;
    }

    if (ano_int % 4 == 0 && (ano_int % 100 != 0 || ano_int % 400 == 0)) {
        if (mes_int == 2 && (dia_int > 29 || dia_int < 1)) {
            return false;
        }
        // É bissexto
    } else {
        if (mes_int == 2 && (dia_int > 28 || dia_int < 1)) {
            return false;
        }
        // Não é bissexto
    }

    return true;
}

int validarnome(char* nome){
    for (int i = 0; i < strlen(nome); i++) {
    if (!isalpha(nome[i]) && nome[i] != ' ') {
    return false;
        }
    }

    if (strlen(nome) < 3){
    return false;
        }
    if (strlen(nome) == 0) {
    return false;
        }
    return true;
}

int validarcategoria(const char* categoria){
    if (!categoria || categoria[0] == '\0') {
        return false;
    }
    return true;
}

int validarcpf(char* cpf){
    if (strlen(cpf) != 11) {
    return false;
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }
    int soma = 0;
    for (int i = 0; i < 9; i++) {
    soma += (cpf[i] - '0') * (10 - i);
    }
    int resto = soma % 11;
    if (resto == 10) {
    resto = 0;
    }
    return true;
}

int validartelefone(const char* telefone){
    // pra esse validador necessitei de amparo do CHAT GPT
    char telesemespaco[12];
    int tamanho = 0;
    for (int i =0; telefone[i]; i++ ){
        if (!isspace(telefone[i])){
            telesemespaco[tamanho++] = telefone[i];
        }
    }   telesemespaco[tamanho] = '\0';

    if (strlen(telesemespaco) != 11){
        return false;
    }   for (int i = 0; i < strlen(telesemespaco); i++) {
        if (!isdigit(telesemespaco[i])) {
            return false;
        }
    }
    return true;
}

int validaremail(const char* email){
    int tamanho =strlen(email);
    bool arroba =false;
    if (tamanho == 0){
        return false;
    }

    for (int i = 0; i < tamanho; i++) {
        if (email[i] == '@') {
            if (arroba) {
                return false;
            }
            arroba = true;
        }
    }   if (!arroba){
        return false;
    }
    return true;
}

int comparador(const void* a, const void* b)
{
    const Usuario* usuario_a = (const Usuario*)a;
    const Usuario* usuario_b = (const Usuario*)b;

    return strcmp(usuario_a->nome, usuario_b->nome);
}

int verificapreco(const char* preco) {
    if (strlen(preco) > 20) {
        return 0;
    }

    int pontoEncontrado = 0;

    for (int i = 0; i < strlen(preco); i++) {
        if (!isdigit(preco[i])) {
            if (preco[i] == '.') {
                if (!pontoEncontrado) {
                    pontoEncontrado = 1;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }
    return 1; 
}