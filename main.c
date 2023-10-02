#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "clientes.h"
#include "vendas.h"

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
bool validardata(int dia, int mes, int ano)
{
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

  if (resto != (cpf[9] - '0')) {
    return false;
  }
  return true;
}

bool validartelefone(char telefone[]){
    // pra esse validador necessitei de amparo do CHAT GPT
    char TelSemEspc[12];
    int j = 0;
    for (int i = 0; telefone[i] != '0'; i++){
        if (isspace (telefone[i])){
            TelSemEspc[j++] = telefone[i];
        }
    }
    TelSemEspc[j] = '\0';
    if (strlen(TelSemEspc) < 11 || strlen(TelSemEspc) > 11){
        return false;
    }
    for (int i = 0; i < strlen(TelSemEspc); i++){
        if (!isdigit(TelSemEspc[i])){
            return false;
        }
    }
    return true;
}

// telas
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

    _sleep(1000);
}

int main(){
    int escolha;

    system("clear || cls");
    printf("\n");
    printf(" ===================================================================================================== \n");
    printf(" ===================================================================================================== \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                     == MENU PRINCIPAL ==                                      === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===================================================================================================== \n");
    printf(" ===================================================================================================== \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                      1. CRIAR USUARIO                                         === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                     2. DELETAR USUARIO                                        === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                    3. ATUALIZAR USUARIO                                       === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                       4. LER USUARIO                                          === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                     5. LISTAR USUARIOS                                        === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                        = 6. VENDAS =                                          === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                          0. SOBRE                                             === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                    Escolha uma das opcoes                                     === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===                                                                                               === \n");
    printf(" ===================================================================================================== \n");
    printf(" ===================================================================================================== \n");
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
        _sleep(5000);
        main();
        break;
    }
}

void cadastrar_usuario(void){
    char telefone[100];
    int i;
    char email[50];
    char nome[100];
    char sobrenome[100];
    char cpf[12];
    char respt;
    int dia, mes, ano;
    bool datavalida = false;
    bool cpf_valido = false;
    bool nomevalido =false;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                   == CADASTRAR USUARIO ==                                     === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                     Nome e sobrenome:                                         === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                    CPF: (Apenas numeros)                                      === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                 Data de Nascimento: (dd/mm/aaaa)                              === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                          Telefone:                                            === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                           Email:                                              === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        do {
            printf("Digite seu nome: ");
            fgets(nome, sizeof(nome), stdin); 
            nome[strcspn(nome, "\n")] = '\0';
            printf("Digite seu sobrenome: ");
            fgets(sobrenome, sizeof(sobrenome), stdin);
            sobrenome[strcspn(nome, "\n")] = '\0';
            nomevalido = validarnome(nome, sobrenome);
            
            if (!nomevalido){
                printf("Nome ou sobrenome invalidos, tente nvamente \n");
                printf("Digite seu nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Digite seu sobrenome: ");
                fgets(sobrenome, sizeof(sobrenome), stdin); 
                sobrenome[strcspn(nome, "\n")] = '\0';
                nomevalido = validarnome(nome, sobrenome);
            }
        } while (!nomevalido);

        do {
            printf("Digite seu CPF: ");
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf, "\n")] = '\0';
            cpf_valido = validarcpf(cpf);
            if (!cpf_valido){
                printf("CPF invalido, tente novamente \n");
                printf("Digite seu CPF: ");
                fgets(cpf, sizeof(cpf), stdin); getchar();
            }
        } while (!cpf_valido);

        do {
            printf("insira dia de nascimento: ");
            scanf("%d", &dia);
            getchar();
            printf("insira mes de nascimento: ");
            scanf("%d", &mes);
            getchar();
            printf("insira ano de nascimento: ");
            scanf("%d", &ano);
            getchar();
            datavalida = validardata(dia, mes, ano);
        if (!datavalida){
            printf("Data invalida, tente novamente \n");
            }
        } while(!datavalida);

    
    while(1){
        printf("Telefone: ");
        scanf(" %c[^\n]", &telefone);
        getchar();

        if (validartelefone(telefone)){
            break;
        } else {
            printf("Telefone invalido, tente novamente \n");
            printf("Telefone: ");
            scanf(" %c[^\n]", &telefone);
            getchar();
        }
    }

    printf("Email:");
    scanf(" %[^\n]", email);
    getchar();

    printf("Seja bem-vindo %s\n", nome);

    printf("Deseja adicionar outro usuario?(S/N)");
    scanf(" %c", &respt);
    getchar();

    // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
    switch (respt){
    case 'S':
    case 's':
        cadastrar_usuario();
        break;
    case 'N':
    case 'n':
        main();
        break;
    default:
        printf("Funcao invalida");
        }
    }  
}

void deletar_usuario(void){
    char id[10];
    int i;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                     == DELETAR USUARIO ==                                     === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        while (1) {
        printf("Id: ");
        scanf(" %11s", id);
        getchar();

        int tamanho = strlen(id);
        int idValido = 1;

        for (i = 0; i < tamanho; i++) {
            if (id[i] == ' ') {
                printf("Id incorreto por conter espaço em branco, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (isalpha(id[i])) {
                printf("Id incorreto por conter letra, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (idValido) {
                sscanf(id, "%d", &idValido);
                if (idValido < 0 || idValido > 999999999) {
                    printf("Id incorreto por conter mais de 10 dígitos, tente novamente.\n");
                    printf("Id: ");
                    scanf(" %11s", id);
                    getchar();
                } else {
                    break;
                }
            }
        }

        if (idValido) {
            break;
        }
    }

        getchar();

        printf("Deseja deletar outro usuario?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            deletar_usuario();
            break;
        case 'N':
        case 'n':
            main();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void atualizar_usuario(void){
    char id[10];
    int i;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                    == ATUALIZAR USUARIO ==                                    === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        while (1) {
        printf("Id: ");
        scanf(" %11s", id);
        getchar();

        int tamanho = strlen(id);
        int idValido = 1;

        for (i = 0; i < tamanho; i++) {
            if (id[i] == ' ') {
                printf("Id incorreto por conter espaço em branco, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (isalpha(id[i])) {
                printf("Id incorreto por conter letra, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (idValido) {
                sscanf(id, "%d", &idValido);
                if (idValido < 0 || idValido > 999999999) {
                    printf("Id incorreto por conter mais de 10 dígitos, tente novamente.\n");
                    printf("Id: ");
                    scanf(" %11s", id);
                    getchar();
                } else {
                    break;
                }
            }
        }

        if (idValido) {
            break;
        }
    }
        getchar();

        printf("Deseja atualizar outro usuario?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            atualizar_usuario();
            break;
        case 'N':
        case 'n':
            main();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void ler_usuario(void){
    char id[10];
    int i;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       == LER USUARIO ==                                       === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");

        while (1) {
        printf("Id: ");
        scanf(" %11s", id);
        getchar();

        int tamanho = strlen(id);
        int idValido = 1;

        for (i = 0; i < tamanho; i++) {
            if (id[i] == ' ') {
                printf("Id incorreto por conter espaço em branco, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (isalpha(id[i])) {
                printf("Id incorreto por conter letra, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (idValido) {
                sscanf(id, "%d", &idValido);
                if (idValido < 0 || idValido > 999999999) {
                    printf("Id incorreto por conter mais de 10 dígitos, tente novamente.\n");
                    printf("Id: ");
                    scanf(" %11s", id);
                    getchar();
                } else {
                    break;
                }
            }
        }

        if (idValido) {
            break;
        }
    }
        getchar();

        printf("Deseja ler outro usuario?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            ler_usuario();
            break;
        case 'N':
        case 'n':
            main();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void listar_usuarios(void){
}

void menuV(void){
    int escolha;

    system("clear || cls");
    printf("\n");
    printf(" =====================================================================================================\n");
    printf(" =====================================================================================================\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                     == MENU PRINCIPAL ==                                      ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" =====================================================================================================\n");
    printf(" =====================================================================================================\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                     1. REGISTRAR VENDA                                        ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                      2. DELETAR VENDA                                         ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                     3. ATUALIZAR VENDA                                        ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                        4. LER VENDA                                           ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                      5 - LISTAS VENDAS                                        ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                          6 - MENU                                             ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                     Escolha uma das opcoes                                    ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" ===                                                                                               ===\n");
    printf(" =====================================================================================================\n");
    printf(" =====================================================================================================\n");
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

void deletar_venda(void){
    char id[10];
    int i;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                      == DELETAR VENDA ==                                      === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        while (1) {
        printf("Id: ");
        scanf(" %11s", id);
        getchar();

        int tamanho = strlen(id);
        int idValido = 1;

        for (i = 0; i < tamanho; i++) {
            if (id[i] == ' ') {
                printf("Id incorreto por conter espaço em branco, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (isalpha(id[i])) {
                printf("Id incorreto por conter letra, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (idValido) {
                sscanf(id, "%d", &idValido);
                if (idValido < 0 || idValido > 999999999) {
                    printf("Id incorreto por conter mais de 10 dígitos, tente novamente.\n");
                    printf("Id: ");
                    scanf(" %11s", id);
                    getchar();
                } else {
                    break;
                }
            }
        }

        if (idValido) {
            break;
        }
    }

        getchar();

        printf("Deseja deletar outra venda?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            deletar_venda();
            break;
        case 'N':
        case 'n':
            menuV();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void registrar_venda(void){
    char id[10];
    int i;
    float preco;
    int dia, mes, ano;
    bool data_val;
    char categoria[100];
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" =====================================================================================================\n");
        printf(" =====================================================================================================\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                     == REGISTRAR VENDA ==                                     ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" =====================================================================================================\n");
        printf(" =====================================================================================================\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                        Informe preco:                                         ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                       Id: (so numeros)                                        ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                   Data da venda: (dd/mm/aaaa)                                 ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                      Categoria do item:                                       ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" ===                                                                                               ===\n");
        printf(" =====================================================================================================\n");
        printf(" =====================================================================================================\n");
        printf("\n");

        printf("Informe o preco:");
        scanf("%f", &preco);

        while (1) {
        printf("Id: ");
        scanf(" %11s", id);
        getchar();

        int tamanho = strlen(id);
        int idValido = 1;

        for (i = 0; i < tamanho; i++) {
            if (id[i] == ' ') {
                printf("Id incorreto por conter espaço em branco, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (isalpha(id[i])) {
                printf("Id incorreto por conter letra, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (idValido) {
                sscanf(id, "%d", &idValido);
                if (idValido < 0 || idValido > 999999999) {
                    printf("Id incorreto por conter mais de 10 dígitos, tente novamente.\n");
                    printf("Id: ");
                    scanf(" %11s", id);
                    getchar();
                } else {
                    break;
                }
            }
        }

        if (idValido) {
            break;
        }
    }

        printf("Dia da venda:");
        scanf("%d", &dia);
        printf("Mes da venda:");
        scanf("%d", &mes);
        printf("Ano da venda:");
        scanf("%d", &ano);

        data_val = validardata(dia, mes, ano);
        if (!data_val){
            printf("Data invalida \n");
        }

        getchar();

        printf("Categoria da venda:");
        scanf("%[^\n]", categoria);

        getchar();

        printf("Deseja adicionar outra venda?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            registrar_venda();
            break;
        case 'N':
        case 'n':
            menuV();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void atualizar_venda(void){
    char id[10];
    int i;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                     == ATUALIZAR VENDA ==                                     === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                       Id: (so numeros)                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        while (1) {
        printf("Id: ");
        scanf(" %11s", id);
        getchar();

        int tamanho = strlen(id);
        int idValido = 1;

        for (i = 0; i < tamanho; i++) {
            if (id[i] == ' ') {
                printf("Id incorreto por conter espaço em branco, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (isalpha(id[i])) {
                printf("Id incorreto por conter letra, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (idValido) {
                sscanf(id, "%d", &idValido);
                if (idValido < 0 || idValido > 999999999) {
                    printf("Id incorreto por conter mais de 10 dígitos, tente novamente.\n");
                    printf("Id: ");
                    scanf(" %11s", id);
                    getchar();
                } else {
                    break;
                }
            }
        }

        if (idValido) {
            break;
        }
    }

        getchar();

        printf("Deseja atualizar outra venda?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            atualizar_venda();
            break;
        case 'N':
        case 'n':
            menuV();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void ler_venda(void){
    char id[10];
    int i;
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                         == LER VENDA ==                                       === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                        Id: (so numeros)                                       === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        while (1) {
        printf("Id: ");
        scanf(" %11s", id);
        getchar();

        int tamanho = strlen(id);
        int idValido = 1;

        for (i = 0; i < tamanho; i++) {
            if (id[i] == ' ') {
                printf("Id incorreto por conter espaço em branco, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (isalpha(id[i])) {
                printf("Id incorreto por conter letra, tente novamente \n");
                printf("Id: ");
                scanf(" %11s", id);
                getchar();
                break;
            }

            if (idValido) {
                sscanf(id, "%d", &idValido);
                if (idValido < 0 || idValido > 999999999) {
                    printf("Id incorreto por conter mais de 10 dígitos, tente novamente.\n");
                    printf("Id: ");
                    scanf(" %11s", id);
                    getchar();
                } else {
                    break;
                }
            }
        }

        if (idValido) {
            break;
        }
    }

        getchar();

        printf("Deseja ler outra venda?(S/N)");
        scanf(" %c", &respt);
        getchar();

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            ler_venda();
            break;
        case 'N':
        case 'n':
            menuV();
            break;
        default:
            printf("Funcao invalida");
        }
    }
}

void listar_vendas(void)
{
}
