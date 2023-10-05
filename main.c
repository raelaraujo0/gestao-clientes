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
    char email[50];
    char nome[100];
    char sobrenome[100];
    char cpf[12];
    char respt;
    int dia, mes, ano;
    bool datavalida = false;
    bool cpf_valido = false;
    bool nomevalido =false;
    bool telvalido =false;
    bool emailvalido= false;


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
            sobrenome[strcspn(sobrenome, "\n")] = '\0';
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
        } while (!datavalida);

    
        do{
            printf("Telefone: ");
            fgets(telefone, sizeof(telefone), stdin);
            telefone[strcspn(telefone, "\n")] = '\0';
            telvalido = validartelefone(telefone);

            size_t len = strlen(telefone);
            if (len > 0 && telefone[len - 1] == '\n') {
             telefone[len - 1] = '\0';
            }
            
            if (!telvalido){
                printf("Telefone invalido, tente novamente \n");
                }
            } while (!telvalido);

        do {
            printf("Email:");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';
            emailvalido = validaremail(email);
            
            if (!emailvalido){
                printf("Email invalido, tente novamente \n");
            }
        } while (!emailvalido);

        char tresdigitos[4];
        strncpy(tresdigitos, cpf, 3);
        tresdigitos[3] ='\0';
        char nametag[100];
        snprintf(nametag, sizeof(nametag), "%s.%s.%s", nome, sobrenome, tresdigitos);

        printf("Seja bem-vindo %s\n\n", nome);
        printf("Sua nametag >>> %s <<<< guarde-a para usar em outras entradas \n\n", nametag);

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
    char nametag[100];
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
        printf(" ===                                           Nametag:                                            === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Digite sua nametag: ");
        fgets(nametag, sizeof(nametag), stdin);
        nametag[strcspn(nametag, "\n")] = '\0';
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
    char nametag[100];
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
        printf(" ===                                           Nametag:                                            === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Digite sua nametag: ");
        fgets(nametag, sizeof(nametag), stdin);
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
    char nametag[100];
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
        printf(" ===                                           Nametag:                                            === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");

        printf("Digite sua nametag: ");
        fgets(nametag, sizeof(nametag), stdin);
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

void registrar_venda(void){
    float preco;
    int dia, mes, ano;
    bool datavalida;
    char categoria[100];
    bool categoriaval = false;
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
        scanf("%f", &preco); getchar();

       do {
            printf("insira dia da venda: ");
            scanf("%d", &dia);
            getchar();
            printf("insira mes da venda: ");
            scanf("%d", &mes);
            getchar();
            printf("insira ano da venda: ");
            scanf("%d", &ano);
            getchar();
            datavalida = validardata(dia, mes, ano);
        if (!datavalida){
            printf("Data invalida, tente novamente \n");
            }
        } while (!datavalida); getchar();

        do {
            printf("Categoria da venda:");
            fgets(categoria, sizeof(categoria), stdin);
            categoria[strcspn (categoria, "\n")] = '\0';
            categoriaval = validarcategoria(categoria);

            if (!categoriaval){
                printf("A categoria esta incorreta, tente novamente \n");
            }
        } while (!categoriaval); getchar();

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

void deletar_venda(void){
    char nametag[100];   
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
        printf(" ===                                           Nametag:                                            === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Digite sua nametag: ");
        fgets(nametag, sizeof(nametag), stdin);
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

void atualizar_venda(void){
    char respt;
    char nametag[100];
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
        printf(" ===                                           Nametag:                                            === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Digite sua nametag: ");
        fgets(nametag, sizeof(nametag), stdin);
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
    char nametag[100];
    char respt;

    while (1)
    {
        system("clear || cls");
        printf("\n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                        == LER VENDA ==                                        === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                           Nametag:                                            === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===                                                                                               === \n");
        printf(" ===================================================================================================== \n");
        printf(" ===================================================================================================== \n");
        printf("\n");

        printf("Digite sua nametag: ");
        fgets(nametag, sizeof(nametag), stdin);
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

void listar_vendas(void){

}
