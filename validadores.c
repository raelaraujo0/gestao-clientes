#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cbclho.h"
#include <stdbool.h>

int validardata(int dia, int mes, int ano){    
    if (ano < 0 && ano > 2023 && mes < 1 && mes > 12 && dia < 1 && dia > 31) {
        return false;
    }
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
        if (mes == 2 && (dia > 29 || dia < 1)){
            return false;
        } 
        // É bissexto
    } else {
        if (mes == 2 && (dia > 28 || dia < 1)){
            return false;
        }
        // Não é bissexto
    }
    return true;
}

int validarnome(char* nome, char* sobrenome){
    for (int i = 0; i < strlen(nome); i++) {
    if (!isalpha(nome[i]) && nome[i] != ' ') {
    return false;
        }
    }
    for (int i = 0; i < strlen(sobrenome); i++) {
    if (!isalpha(sobrenome[i]) && sobrenome[i] != ' ') {
        return false;
        }
    }

    if (strlen(nome) < 3){
    return false;
        }
    if (strlen(sobrenome) < 3){
    return false;
        }
    if (strlen(nome) == 0 || strlen(sobrenome) == 0) {
    return false;
        }
    return true;
}

int validarcategoria(const char* categoria){
    if (strlen(categoria) == 0) {
        return false;
    }
    for (int i = 0; categoria[i] != '\0'; i++) {
        if (!isalpha(categoria[i])) {
            return false;
        }
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
    return strcmp(((Usuario*)a)->nome, ((Usuario*)b)->nome);
}
