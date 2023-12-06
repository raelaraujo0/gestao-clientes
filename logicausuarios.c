#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cbclho.h"

typedef struct usuario Usuario;
struct usuario{
    char telefone[100];
    char email[50];
    char nome[100];
    char sobrenome[100];
    char cpf[12];
    int dia[3], mes[3], ano[5];
    char senha[250];
    int ativo;
};


 Usuario* SubTelaCadUsu(void)
{
    Usuario *usuario;
    usuario = (Usuario*)malloc(sizeof(Usuario));

    char respt;
    bool datavalida = false;
    bool cpf_valido = false;
    bool nomevalido = false;
    bool telvalido = false;
    bool emailvalido = false;

    FILE *arquivousuarios;
    arquivousuarios = fopen("usuarios.txt", "a");
    if (arquivousuarios == NULL){
        printf("erro");
        exit(1);
    }

    while (1) {
        system("clear || cls");
        Tela_CadUsu();

        do {
            printf("Digite seu nome: ");
            fgets(usuario->nome, sizeof(usuario->nome), stdin);
            usuario->nome[strcspn(usuario->nome, "\n")] = '\0';

            printf("Digite seu sobrenome: ");
            fgets(usuario->sobrenome, sizeof(usuario->sobrenome), stdin);
            usuario->sobrenome[strcspn(usuario->sobrenome, "\n")] = '\0';

            nomevalido = validarnome(usuario->nome, usuario->sobrenome);

            if (!nomevalido) {
                printf("Nome ou sobrenome inválidos, tente novamente.\n");
            }
            } while (!nomevalido);

        do {
            printf("Digite seu CPF: ");
            fgets(usuario->cpf, sizeof(usuario->cpf), stdin);
            cpf_valido = validarcpf(usuario->cpf);

            if (!cpf_valido) {
                printf("CPF inválido, tente novamente.\n");
            }
            } while (!cpf_valido);

        do {
            printf("insira dia do nascimento: ");
            scanf("%d", &usuario->dia);
            getchar();
            printf("insira mes da nascimento: ");
            scanf("%d", &usuario->mes);
            getchar();
            printf("insira ano da nascimento: ");
            scanf("%d", &usuario->ano);
            getchar();

            datavalida = validardata(usuario->dia, usuario->mes, usuario->ano);

            if (!datavalida) {
                printf("Data inválida, tente novamente.\n");
            }
            } while (!datavalida);

        do {
            printf("Telefone: ");
            fgets(usuario->telefone, sizeof(usuario->telefone), stdin);
            usuario->telefone[strcspn(usuario->telefone, "\n")] = '\0';

            telvalido = validartelefone(usuario->telefone);

            size_t len = strlen(usuario->telefone);
            if (len > 0 && usuario->telefone[len - 1] == '\n') {
                usuario->telefone[len - 1] = '\0';
            }

            if (!telvalido) {
                printf("Telefone invalido, tente novamente\n");
            }
            } while (!telvalido);

        do {
            printf("Email: ");
            fgets(usuario->email, sizeof(usuario->email), stdin);
            usuario->email[strcspn(usuario->email, "\n")] = '\0';
            emailvalido = validaremail(usuario->email);

            if (!emailvalido) {
                printf("Email inválido, tente novamente.\n");
            }
            } while (!emailvalido);
            
            printf("Crie uma senha: ");
            fgets(usuario->senha, sizeof(usuario->senha), stdin);

        printf("Seja bem-vindo %s\n", usuario->nome);

        fprintf(arquivousuarios, "Nome e sobrenome: %s %s, CPF: %s, Data de nascimento: %d/%d/%d, Telefone: %s, Email: %s, Senha: %s\n", usuario->nome, usuario->sobrenome, usuario->cpf, usuario->dia[0], usuario->mes[0], usuario->ano[0], usuario->telefone, usuario->email, usuario->senha);
        fclose(arquivousuarios);

        printf("Deseja adicionar outro usuário? (S/N)");
        scanf(" %c", &respt);
        getchar();

        // Função de loop para caso queira fazer a operação novamente, voltar à função, senão ir ao menu principal.
        switch (respt) {
        case 'S':
        case 's':
            continue;
        case 'N':
        case 'n':
            menu_principal();
        default:
            printf("Função inválida.\n");
        }
    }
}

void SubTelaDelUsu()
{   char cpf[12];
    char respt;
    Usuario usuario;

  while (1)
  {
    system("clear || cls");
    Tela_DelUsu();

    printf("Digite seu cpf: (somente numeros) ");
    scanf("%s", cpf);

    FILE* arquivousuarios = fopen("usuarios.txt", "rb+");

        while (fread(&usuario, sizeof(Usuario), 1, arquivousuarios) == 1) {
            if (strcmp(usuario.cpf, cpf) == 0) {
                usuario.ativo = 0; // Marcar usuário como inativo
                fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);
                fwrite(&usuario, sizeof(Usuario), 1, arquivousuarios);
                break;
            }
        }

        fclose(arquivousuarios);

        if (usuario.ativo == 0) {
            printf("Deseja deletar este usuario? (S/N)");
            scanf(" %c", &respt);
            getchar();

            if (respt == 'S' || respt == 's') {
                printf("Usuario marcado como inativo\n");
            } else {
                printf("Operação cancelada\n");
            }
        } else {
            printf("Usuario nao encontrado\n");
        }
    }
}

void SubTelaLerUsu(Usuario *usuario)
{
    char respt;
    char line[255];
    bool found = false;
    while (1)
    {
        system("clear || cls");
        Tela_LerUsu();

        FILE *arquivousuarios;
        arquivousuarios = fopen("usuarios.txt", "r");
        if (arquivousuarios == NULL){
            printf("erro");
        }

        printf("Digite seu cpf: ");
        scanf(" %11[^\n]", usuario->cpf); getchar();

        
        while(fgets(line, sizeof(line), arquivousuarios) != NULL){
            char* token = strtok(line, ",");
            if (token != NULL && strncmp(token, usuario->cpf, 11) == 0){
                found = true;
                printf("Informacoes do usuario:\n");
                printf("Nome: %s\n", usuario->nome);
                printf("Sobrenome: %s\n", usuario->sobrenome);
                printf("Data de nascimento: %d/%d/%d\n", &usuario->dia, &usuario->mes, &usuario->ano);
                printf("CPF: %s\n", usuario->cpf);
                printf("Telefone: %s\n", usuario->telefone);
                printf("Email: %s\n", usuario->email);
                continue;
            }
        }

        fclose(arquivousuarios);

        if (!found){
            printf("Esse cpf esta incorreto ou nao existe \n");
        }

        printf("Deseja ler outro usuario?(S/N)");
        scanf(" %c", &respt);

        // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
        switch (respt)
        {
        case 'S':
        case 's':
            continue;
        case 'N':
        case 'n':
            menu_principal();
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaListarUsu(Usuario *usuario)
{
    FILE* arquivousuarios = fopen("usuarios.txt", "r");

    printf("Lista de usuarios:\n");
    while (1) {
        if (fscanf(arquivousuarios, "Nome e sobrenome: %[^,], CPF: %[^,], Data de nascimento: %d/%d/%d, Telefone: %[^,], Email: %[^\n]\n",
            usuario->nome, usuario->cpf, &usuario->dia[0], &usuario->mes[0], &usuario->ano[0], usuario->telefone, usuario->email) != EOF) {
            printf("Nome: %s\n", usuario->nome);
            printf("CPF: PRIVADO\n");
            printf("Data de nascimento: %d/%d/%d\n", usuario->dia[0], usuario->mes[0], usuario->ano[0]);
            printf("Telefone: %s\n", usuario->telefone);
            printf("Email: %s\n", usuario->email);

        } else {
            break;
        }
    }
    fclose(arquivousuarios);
}

void listagem_por_nome(Usuario *usuario)
{
    FILE* arquivousuarios = fopen("usuarios.txt", "r");

    printf("Lista de usuarios pelo seu nome:\n");
    while (1) {
        if (fscanf(arquivousuarios, "Nome:", usuario->nome) != EOF){
            printf("Nome: %s\n", usuario->nome);
        } else {
            break;
        }
    }
    fclose(arquivousuarios);
}

void Login(Usuario *usuario)
{
    while (1)
    {
        system("clear || cls");
        Tela_Login();

        printf("Digite seu cpf: ");
        scanf(" %11[^\n]", usuario->cpf); getchar();

        printf("Digite sua senha: ");
        scanf(" %[^\n]", usuario->senha); getchar();

        FILE* arquivousuarios = fopen("usuarios.txt", "r");
        Usuario usuario_encontrado;
        int encontrado = 0;
        while (fscanf(arquivousuarios, "CPF: %[^,], Senha: %[^\n]\n",
            usuario_encontrado.cpf, usuario_encontrado.senha) != EOF)
        {
            if (strcmp(usuario->cpf, usuario_encontrado.cpf) == 0 && strcmp(usuario->senha, usuario_encontrado.senha) == 0)
            {
                encontrado = 1;
                continue;
            }
        }

        fclose(arquivousuarios);

        if (encontrado == 1)
        {
            menuVendas();
        } else {
            printf("Usuario nao encontrado. Deseja cadastrar um novo usuario? (S/N)\n");
            char respt;
            scanf(" %c", &respt);
            getchar();

            if (respt == 'S' || respt == 's')
            {
                SubTelaCadUsu();
            } else {
                continue;
            }
        }
    }
}