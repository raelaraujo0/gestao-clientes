#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "telas.h"
#include "subtelas.h"


// funcoes usuarios
int main();
void sobre(void);
void cadastrar_usuario(void);
void deletar_usuario(void);
void atualizar_usuario(void);
void ler_usuario(void);
void listar_usuarios(void);

// funcoes vendas
void menuV(void);
void registrar_venda(void);
void deletar_venda(void);
void atualizar_venda(void);
void ler_venda(void);
void listar_vendas(void);

// validador
bool validardata(int dia, int mes, int ano){    
    if (ano < 0 || ano > 2023 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
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

bool validarnome(char* nome, char* sobrenome){
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

bool validarcategoria(const char* categoria){
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

bool validarcpf(char* cpf){
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

bool validartelefone(const char* telefone){
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

bool validaremail(const char* email){
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

void sobre(void){
    system("clear || cls");
    printf("\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                 programa desenvolvido                      ===\n");
    printf(" ===                por Rael Araujo, aluno de                   ===\n");
    printf(" ===                sistemas de informacao/UF                   ===\n");
    printf(" ===                no componente PROGRAMACAO                   ===\n");
    printf(" ===                2 periodo - JUL/DEZ - 2023                  ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ===                                                            ===\n");
    printf(" ==================================================================\n");
    printf(" ==================================================================\n");
    printf("\n");
    system("pause");
}


int main(){
    int escolha;
    printf("\n");
    
    TelaPrincipal();

    scanf("%d", &escolha);
    getchar();
    printf("\n");

    switch (escolha)
    {
    case 1:
        // chamada da tela e funcoes
        cadastrar_usuario();
        break;
    case 2:
        // chamada da tela e funcoes
        deletar_usuario();
        break;
    case 3:
        // chamada da tela e funcoes
        atualizar_usuario();
        break;
    case 4:
        // chamada da tela e funcoes
        ler_usuario();
        break;
    case 5:
        listar_usuarios();
        break;
    case 6:
        menuV();
        break;
    case 0:
        sobre();
        getchar();
        main();
        break;

    default:
        printf("opcao invalida,tente novamente \n");
        system("pause");
        main();
        break;
    }

    void cadastrar_usuario(void){
        printf("\n");
        Tela_CadUsu();
        printf("\n");
        SubTelaCadUsu();x
    }

    void deletar_usuario(void){
        printf("\n");
        Tela_DelUsu();
        printf("\n");
        SubTelaDelUsu();
    }


    void atualizar_usuario(void){
        printf("\n");
        Tela_AttUsu();
        printf("\n");
        SubTelaAttUsu();
    }

    void ler_usuario(void){
        printf("\n");
        Tela_LerUsu();
        printf("\n");
        SubTelaLerUsu();
    }

    void listar_usuarios(void){
    }

    void menuV(void){
        int escolha;

        system("clear || cls");
        printf("\n");
        Tela_MenuV();
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha)
        {
        case 1:
            registrar_venda();
            break;
        case 2:
            deletar_venda();
            break;
        case 3:
            atualizar_venda();
            break;
        case 4:
            ler_venda();
            break;
        case 5:
            listar_vendas();
            break;
        case 6:
            main();
            break;
        default:
            printf("opcao invalida,tente novamente \n");
            system("pause");
            menuV();
            break;
        }
    }

    void registrar_venda(void){
        printf("\n");
        Tela_RegVen();
        printf("\n");
        SubtelaRegVen();
    }

    void deletar_venda(void){
        printf("\n");
        Tela_DelVen();
        printf("\n");
        SubtelaDelVen();
    }

    void atualizar_venda(void){
        printf("\n");
        Tela_AttVen();
        printf("\n");
        SubTelaAttVen();
    }

    void ler_venda(void){
        printf("\n");
        Tela_LerVen();
        printf("\n");
        SubTelaLerVen();
    }

    void listar_vendas(void){
    }
}
