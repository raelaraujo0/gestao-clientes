#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cbclho.h"

Usuario* SubTelaCadUsu(void)
{
    Usuario *usu;
    usu = (Usuario*)malloc(sizeof(Usuario));

    char respt;
    char respt3;
    bool datavalida = false;
    bool cpf_valido = false;
    bool nomevalido = false;
    bool telvalido = false;
    bool emailvalido = false;
    bool cpfduplo = false;
    bool valido = false;

    while (1) {
        system("clear || cls");
        Tela_CadUsu();

        do {
            printf("Digite seu nome: ");
            fgets(usu->nome, sizeof(usu->nome), stdin);
            usu->nome[strcspn(usu->nome, "\n")] = '\0';
            limparBuffer();

            nomevalido = validarnome(usu->nome);

            if (!nomevalido) {
                printf("Nome invalido, tente novamente.\n");
            }
            } while (!nomevalido);

        do {
    printf("Digite seu CPF: (apenas numeros) ");
    scanf("%11s", usu->cpf);
    limparBuffer();
    cpf_valido = validarcpf(usu->cpf);
    cpfduplo = cpfjaexiste(usu->cpf);   
    
    if (cpfduplo) {
        printf("Esse CPF ja esta cadastrado. Deseja (S)sair ou (C)continuar?\n");
        scanf(" %c", &respt3);
        if (respt3 == 'S' || respt3 == 's') {
            menu_principal();
        }
    } else if (!cpf_valido) {
        printf("CPF inválido, tente novamente.\n");
    }

} while (!cpf_valido || cpfduplo);

    valido = 0;

        do {
            printf("insira dia do nascimento: (DD)");
            fgets(usu->dia , sizeof(usu->dia), stdin);
            limparBuffer();
            printf("insira mes da nascimento: (MM)");
            fgets(usu->mes , sizeof(usu->mes), stdin);
            limparBuffer();
            printf("insira ano da nascimento: (AAAA)");
            fgets(usu->ano , sizeof(usu->ano), stdin);
            limparBuffer();

            datavalida = validardata(usu->dia, usu->mes, usu->ano);

            if (!datavalida) {
                printf("Data invalida, tente novamente.\n");
            }
            } while (!datavalida);

        do {
            printf("Telefone (apenas numeros): ");
            scanf("%11s", usu->telefone);
            limparBuffer();

            telvalido = validartelefone(usu->telefone);

            if (!telvalido) {
                printf("Telefone invalido, tente novamente\n");
            }
            } while (!telvalido);

        do {
            printf("Email (deve conter arroba): ");
            scanf("%25s", usu->email);
            limparBuffer();
            
            emailvalido = validaremail(usu->email);
            if (!emailvalido) {
                printf("Email invalido, tente novamente.\n");
            }
            } while (!emailvalido);

            
        printf("Seja bem-vindo %s\n", usu->nome);

        usu->ativo = 1;

        salvarusuario(usu);

        printf("Deseja adicionar outro usuario? (S/N)");
        scanf(" %c", &respt);
        

        // Função de loop para caso queira fazer a operação novamente, voltar à função, senão ir ao menu principal.
        switch (respt) {
        case 'S':
        case 's':
            continue;
        case 'N':
        case 'n':
            menu_principal();
        default:
            printf("opcao invalida.\n");

        limparBuffer();
        return usu;
        }
    }
}

void SubTelaAttUsu(void)
{
    Usuario usuarioatt;
    char cpf[12];
    char respt;

    bool datavalida = false;
    bool nomevalido = false;
    bool telvalido = false;
    bool emailvalido = false;

    while (1)
    {
        system("clear || cls");
        Tela_AttUsu();

        int encontrado = 0;

        printf("Digite o CPF: ");
        scanf("%11s", cpf);
        limparBuffer();

        FILE* arquivousuarios = fopen("usuarios.dat", "rb+");
        if (arquivousuarios == NULL)
        {
            printf("Erro\n");
            return;
        }

        while (fread(&usuarioatt, sizeof(Usuario), 1, arquivousuarios) == 1){
            if (strcmp(usuarioatt.cpf, cpf) == 0){
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            printf("Usuario nao encontrado\n");
            fclose(arquivousuarios);
            printf("Deseja tentar outro CPF? (S/N)");
            scanf(" %c", &respt);
            limparBuffer();

            if (respt == 'S' || respt == 's') {
                continue;
            } else {
                menu_principal();
            }
        }

    fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);

    do {
            printf("Digite seu nome: ");
            fgets(usuarioatt.nome, sizeof(usuarioatt.nome), stdin);
            usuarioatt.nome[strcspn(usuarioatt.nome, "\n")] = '\0';
            limparBuffer();

            nomevalido = validarnome(usuarioatt.nome);

            if (!nomevalido) {
                printf("Nome invalidos, tente novamente.\n");
            }
            } while (!nomevalido);

        do {
            printf("insira dia do nascimento: ");
            scanf("%s", &usuarioatt.dia);
            limparBuffer();
            printf("insira mes da nascimento: ");
            scanf("%s", &usuarioatt.mes);
            limparBuffer();
            printf("insira ano da nascimento: ");
            scanf("%s", &usuarioatt.ano);
            limparBuffer();

            datavalida = validardata(usuarioatt.dia, usuarioatt.mes, usuarioatt.ano);

            if (!datavalida) {
                printf("Data invalida, tente novamente.\n");
            }
            } while (!datavalida);

        do {
            printf("Telefone: ");
            scanf("%s", usuarioatt.telefone);
            usuarioatt.telefone[strcspn(usuarioatt.telefone, "\n")] = '\0';
            limparBuffer();
            telvalido = validartelefone(usuarioatt.telefone);

            if (!telvalido) {
                printf("Telefone invalido, tente novamente\n");
                limparBuffer();
            }
            } while (!telvalido);

        do {
            printf("Email: ");
            scanf("%s", usuarioatt.email);
            limparBuffer();
            usuarioatt.email[strcspn(usuarioatt.email, "\n")] = '\0';
            emailvalido = validaremail(usuarioatt.email);
            if (!emailvalido) {
                printf("Email invalido, tente novamente.\n");
            }
            } while (!emailvalido);

    fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);
    fwrite(&usuarioatt, sizeof(Usuario), 1, arquivousuarios);

    printf("Usuario com CPF %s atualizado\n", cpf);

    fclose(arquivousuarios);

        printf("Deseja atualizar outro usuario? (S/N)");
        scanf(" %c", &respt);
        limparBuffer();

        switch (respt){
            case 'S':
            case 's':
                continue;
            case 'N':
            case 'n':
                menu_principal();
            default:
                printf("opcao invalida\n");
        }
    }
}

void SubTelaLerUsu(void)
{
    Usuario usuarioEncontrado;
    char cpf[12];
    char respt;
    bool found = false;


    while (1)
    {
        system("clear || cls");
        Tela_LerUsu();

        printf("Digite seu cpf: ");
        scanf("%s", cpf);
        limparBuffer();

        FILE *arquivousuarios = fopen("usuarios.dat", "rb");
        if (arquivousuarios == NULL){
            printf("Erro\n");
            return;
        }

        while (fread(&usuarioEncontrado, sizeof(Usuario), 1, arquivousuarios) == 1){
            if (strcmp(usuarioEncontrado.cpf, cpf) == 0)
            {
                found = 1;
                printf("Nome: %s\n", usuarioEncontrado.nome);
                printf("CPF: %s\n", usuarioEncontrado.cpf);
                printf("Data de nascimento:  %s/%s/%s\n", usuarioEncontrado.dia, usuarioEncontrado.mes, usuarioEncontrado.ano);
                printf("Telefone: %s\n", usuarioEncontrado.telefone);
                printf("Email: %s\n", usuarioEncontrado.email);
                break;
            }
        }

        if (!found)
        {
            printf("Usuario nao encontrado\n");
        }

        printf("Deseja procurar outro usuario? (S/N) ");
        scanf(" %c", &respt);
        limparBuffer();

        if (respt == 'N' || respt == 'n'){
            break;
        fclose(arquivousuarios);
        }
    } 
}

void SubTelaDelUsu(void) {
    Usuario usu;
    char cpf[12];
    char respt;
    char respt2;

    while (1) {
        system("clear || cls");
        Tela_DelUsu();

        printf("Digite seu cpf: (somente numeros) ");
        scanf("%s", cpf);
        limparBuffer();

        FILE* arquivousuarios = fopen("usuarios.dat", "rb+");

        while (fread(&usu, sizeof(Usuario), 1, arquivousuarios) == 1) {
            if (strcmp(usu.cpf, cpf) == 0) {
                usu.ativo = 0; // Marca usuário como ausente
                fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);
                fwrite(&usu, sizeof(Usuario), 1, arquivousuarios);
                fclose(arquivousuarios);

                printf("Usuario marcado como inativo\n");
                pausa();
                menu_principal();
                return; 
            }
        }

        fclose(arquivousuarios);

        printf("Usuario nao encontrado\n");
        pausa();
        menu_principal();
        return; 
    }
}


void listagem_usuarios(void)
{
    FILE* arquivousuarios = fopen("usuarios.dat", "rb");
    if (arquivousuarios == NULL)
    {
        printf("Erro\n");
        return;
    }

    fseek(arquivousuarios, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivousuarios);
    rewind(arquivousuarios);

    int num_usuarios = tamanho_arquivo / sizeof(Usuario);
    Usuario* usuarios = (Usuario*)malloc(num_usuarios * sizeof(Usuario));

    fread(usuarios, sizeof(Usuario), num_usuarios, arquivousuarios);

    if (num_usuarios > 0)
    {
        printf("Lista de usuários:\n");

        for (int i = 0; i < num_usuarios; i++)
        {
            printf("============================================================================\n");
            printf("\n");
            printf("Nome: %s\n", usuarios[i].nome);
            printf("CPF: %s\n", usuarios[i].cpf);
            printf("Data de Nascimento: %s/%s/%s\n", usuarios[i].dia, usuarios[i].mes, usuarios[i].ano);
            printf("Telefone: %s\n", usuarios[i].telefone);
            printf("Email: %s\n", usuarios[i].email);
            printf("\n");
            printf("\t> Pressione <ENTER> para pular o usuario< <\n");
            printf("============================================================================\n");
            getchar();
        }
    }

    free(usuarios);
    fclose(arquivousuarios);
}

void listagem_alf(void)
{
     FILE* arquivousuarios = fopen("usuarios.dat", "rb");
    if (arquivousuarios == NULL)
    {
        printf("Erro \n");
        return;
    }

    fseek(arquivousuarios, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivousuarios);
    rewind(arquivousuarios);

    int num_usuarios = tamanho_arquivo / sizeof(Usuario);
    Usuario* usuarios = (Usuario*)malloc(num_usuarios * sizeof(Usuario));

    fread(usuarios, sizeof(Usuario), num_usuarios, arquivousuarios);

    if (num_usuarios > 0)
    {
        qsort(usuarios, num_usuarios, sizeof(Usuario), comparador);

        printf("Lista de usuarios em ordem alfabetica:\n");

        for (int i = 0; i < num_usuarios; i++)
        {
            printf("Nome: %s\n", usuarios[i].nome);
            printf("\n");
            printf("\t> aperte <ENTER> para pular o usuario <\n");
            getchar();

        }

    }

    free(usuarios);
    fclose(arquivousuarios);
}

void salvarusuario(Usuario* usu){

    FILE *arquivousuarios;
    arquivousuarios = fopen("usuarios.dat", "ab");

    if(arquivousuarios == NULL){
        printf("erro abrindo arquivo");
        return;
    }
        fwrite(usu, sizeof(Usuario), 1, arquivousuarios);

        fclose(arquivousuarios);
        free(usu);
}

int cpfjaexiste(const char* cpf){

    Usuario readuser;
    FILE* arquivousuarios = fopen("usuarios.dat", "rb");

    if(arquivousuarios == NULL){
        printf("erro\n");
        return;
    }

    while(fread(&readuser, sizeof(Usuario), 1, arquivousuarios) == 1){
        if (strcmp(readuser.cpf, cpf)==0){
            fclose(arquivousuarios);
            return true;
        }
    }
    fclose(arquivousuarios);

    return false;
}