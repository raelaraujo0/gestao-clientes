#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cbclho.h"

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
    arquivousuarios = fopen("usuarios.dat", "a");
    if (arquivousuarios == NULL){
        printf("erro");
        exit(1);
    }

    while (1) {
        system("clear || cls");
        Tela_CadUsu();

        do {
            printf("Digite seu nome: ");
            scanf("%15s", usuario->nome);
            usuario->nome[strcspn(usuario->nome, "\n")] = '\0';

            printf("Digite seu sobrenome: ");
            scanf("%15s", usuario->sobrenome);
            usuario->sobrenome[strcspn(usuario->sobrenome, "\n")] = '\0';

            nomevalido = validarnome(usuario->nome, usuario->sobrenome);

            if (!nomevalido) {
                printf("Nome ou sobrenome inválidos, tente novamente.\n");
            }
            } while (!nomevalido);

        do {
            printf("Digite seu CPF: ");
            scanf("%11s", usuario->cpf);
            cpf_valido = validarcpf(usuario->cpf);
            limparBuffer();

            if (!cpf_valido) {
                printf("CPF invalido, tente novamente.\n");
            }
            } while (!cpf_valido);

        do {
            printf("insira dia do nascimento: ");
            scanf("%2s", &usuario->dia);
            limparBuffer();
            printf("insira mes da nascimento: ");
            scanf("%2s", &usuario->mes);
            limparBuffer();
            printf("insira ano da nascimento: ");
            scanf("%4s", &usuario->ano);
            limparBuffer();

            datavalida = validardata(usuario->dia, usuario->mes, usuario->ano);

            if (!datavalida) {
                printf("Data inválida, tente novamente.\n");
            }
            } while (!datavalida);

        do {
            printf("Telefone: ");
            fgets(usuario->telefone, sizeof(usuario->telefone), stdin);

            telvalido = validartelefone(usuario->telefone);

            if (!telvalido) {
                printf("Telefone invalido, tente novamente\n");
            }
            } while (!telvalido);

        do {
            printf("Email: ");
            scanf("%25s", usuario->email);
            emailvalido = validaremail(usuario->email);
            if (!emailvalido) {
                printf("Email invalido, tente novamente.\n");
            }
            } while (!emailvalido);

            printf("Crie uma senha: ");
            scanf("%50s", usuario->senha);

        free(usuario);

        printf("Seja bem-vindo %s\n", usuario->nome);

        fprintf(arquivousuarios, "Nome e sobrenome: %s %s, CPF: %s, Data de nascimento: %s/%s/%s, Telefone: %s, Email: %s, Senha: %s\n", usuario->nome, usuario->sobrenome, usuario->cpf, usuario->dia, usuario->mes, usuario->ano, usuario->telefone, usuario->email, usuario->senha);
        fclose(arquivousuarios);

        printf("Deseja adicionar outro usuario? (S/N)");
        scanf(" %c", &respt);
        limparBuffer();

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
        }
    }
}

void SubTelaAttUsu(void)
{
    Usuario *usuario_att;
    char cpf;
    char respt;

    bool datavalida = false;
    bool cpf_valido = false;
    bool nomevalido = false;
    bool telvalido = false;
    bool emailvalido = false;

    while (1)
    {
        system("clear || cls");
        Tela_AttUsu();

        FILE* arquivousuarios = fopen("usuarios.dat", "rb+");
        if (arquivousuarios == NULL)
        {
            printf("Erro\n");
            return;
        }

        int encontrado = 0;

        printf("Digite o CPF: ");
        scanf("%11s", cpf);
        limparBuffer();

        while (fread(&usuario_att, sizeof(Usuario), 1, arquivousuarios) == 1){
            if (strcmp(usuario_att->cpf, cpf) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            printf("Usuario nao encontrado\n");
            fclose(arquivousuarios);
            return;
        }

    fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);

    do {
            printf("Digite seu nome: ");
            scanf("%14s", usuario_att->nome);
            usuario_att->nome[strcspn(usuario_att->nome, "\n")] = '\0';

            printf("Digite seu sobrenome: ");
            scanf("%14s", usuario_att->sobrenome);
            usuario_att->sobrenome[strcspn(usuario_att->sobrenome, "\n")] = '\0';

            nomevalido = validarnome(usuario_att->nome, usuario_att->sobrenome);

            if (!nomevalido) {
                printf("Nome ou sobrenome invalidos, tente novamente.\n");
            }
            } while (!nomevalido);

        do {
            printf("Digite seu CPF: ");
            scanf("%12s", usuario_att->cpf);
            cpf_valido = validarcpf(usuario_att->cpf);
            limparBuffer();

            if (!cpf_valido) {
                printf("CPF invalido, tente novamente.\n");
            }
            } while (!cpf_valido);

        do {
            printf("insira dia do nascimento: ");
            scanf("%s", &usuario_att->dia);
            limparBuffer();
            printf("insira mes da nascimento: ");
            scanf("%s", &usuario_att->mes);
            limparBuffer();
            printf("insira ano da nascimento: ");
            scanf("%s", &usuario_att->ano);
            limparBuffer();

            datavalida = validardata(usuario_att->dia, usuario_att->mes, usuario_att->ano);

            if (!datavalida) {
                printf("Data invalida, tente novamente.\n");
            }
            } while (!datavalida);

        do {
            printf("Telefone: ");
            scanf("%s", usuario_att->telefone);
            usuario_att->telefone[strcspn(usuario_att->telefone, "\n")] = '\0';

            telvalido = validartelefone(usuario_att->telefone);

            if (!telvalido) {
                printf("Telefone invalido, tente novamente\n");
            }
            } while (!telvalido);

        do {
            printf("Email: ");
            fscanf("%s", usuario_att->email);
            usuario_att->email[strcspn(usuario_att->email, "\n")] = '\0';
            emailvalido = validaremail(usuario_att->email);
            if (!emailvalido) {
                printf("Email invalido, tente novamente.\n");
            }
            } while (!emailvalido);

    fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);
    fwrite(&usuario_att, sizeof(Usuario), 1, arquivousuarios);

    fclose(arquivousuarios);

    printf("Usuario com CPF %s atualizado\n", cpf);

    printf("Deseja atualizar outro usuario? (S/N)");
    scanf("%c", &respt); limparBuffer();

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
    Usuario usuario;

    char cpf[12];
    char respt;
    bool found = false;

    FILE *arquivousuarios = fopen("usuarios.dat", "rb");
    if (arquivousuarios == NULL)
    {
        printf("Erro\n");
        return;
    }

    while (1)
    {
        system("clear || cls");
        Tela_LerUsu();

        printf("Digite seu cpf: ");
        scanf(" %s", cpf);
        limparBuffer();

        while (fread(&usuario, sizeof(Usuario), 1, arquivousuarios) == 1){
            if (strcmp(usuario.cpf, cpf) == 0)
            {
                found = true;
                printf("Nome: %s %s\n", usuario.nome, usuario.sobrenome);
                printf("CPF: %s\n", usuario.cpf);
                printf("Data de nascimento:  %s/%s/%s\n", usuario.dia, usuario.mes, usuario.ano);
                printf("Telefone: %s\n", usuario.telefone);
                printf("Email: %s\n", usuario.email);
                break;
            }
        }

        if (!found)
        {
            printf("Usuario nao encontrado.\n");
        }

        printf("Deseja procurar outro usuario? (S/N) ");
        scanf(" %c", &respt);
        limparBuffer();

        if (respt == 'N' || respt == 'n')
        {
            break;
        }

        found = false;
        rewind(arquivousuarios);
    }

    fclose(arquivousuarios);
}

void SubTelaDelUsu(void)
{   
    Usuario usuario;
    char cpf[12];
    char respt;
    char respt2;
    while (1)
    {
        system("clear || cls");
        Tela_DelUsu();

        printf("Digite seu cpf: (somente numeros) ");
        scanf("%s", cpf); limparBuffer();

        FILE* arquivousuarios = fopen("usuarios.dat", "rb+");

            while (fread(&usuario, sizeof(Usuario), 1, arquivousuarios) == 1) {
                if (strcmp(usuario.cpf, cpf) == 0) {
                    usuario.ativo = 0; // marca usuario como ausente
                    fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);
                    fwrite(&usuario, sizeof(Usuario), 1, arquivousuarios);
                    break;
                }
            }

        fclose(arquivousuarios);

    if (usuario.ativo == 0){
            printf("Deseja deletar este usuario? (S/N)");
            scanf(" %c", &respt2);
            limparBuffer();

            if (respt2 == 'S' || respt2 == 's') {
                printf("Usuario marcado como inativo\n");
                menu_principal();
                break;
            } else {
                printf("deu errado po\n");
            }
        } else {
            printf("Usuario nao encontrado\n");

    printf("Deseja deletar outro usuario? (S/N)");
    scanf("%c", &respt); limparBuffer();

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
}

void SubTelaListarUsu(void)
{
    Usuario usuario;

    FILE* arquivousuarios = fopen("usuarios.dat", "rb"); 
    printf("Lista de usuarios:\n");
    while(fread(&usuario, sizeof(Usuario), 1, arquivousuarios) == 1){
        printf("Nome: %s %s\n", usuario.nome, usuario.sobrenome);
        printf("CPF: %s\n", usuario.cpf);
        printf("Data de nascimento:  %s/%s/%s\n", usuario.dia, usuario.mes, usuario.ano);
        printf("Telefone: %s\n", usuario.telefone);
        printf("Email: %s\n", usuario.email);
    }if(arquivousuarios == NULL){
        printf("erro");
        return;
    }

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
    qsort(usuarios, num_usuarios, sizeof(Usuario), comparador());

    printf("Lista de usuarios em ordem alfabetica:\n");
    for (int i = 0; i < num_usuarios; i++)
    {
        printf("Nome: %s %s\n", usuarios[i].nome, usuarios[i].sobrenome);
    }

    free(usuarios);
    fclose(arquivousuarios);
}

void Login(void)
{
    Usuario* usuario;
    char senha[50];
    char cpf[12];
    while (1)
    {
        system("clear || cls");
        Tela_Login();

        printf("Digite seu cpf: ");
        scanf("%s", cpf); 
        limparBuffer();

        printf("Digite sua senha: ");
        scanf("%s", senha); 
        limparBuffer();

        FILE* arquivousuarios = fopen("usuarios.dat", "r");
        Usuario usuario_encontrado;
        int encontrado = 0;
        while (fread(arquivousuarios, "CPF: %s, Senha: %s\n",
            usuario_encontrado.cpf, usuario_encontrado.senha) != EOF)
        {
            if (strcmp(usuario->cpf, usuario_encontrado.cpf) == 0 && strcmp(usuario->senha, usuario_encontrado.senha) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        fclose(arquivousuarios);

        if(encontrado == 1)
        {
            menuVendas();
            break;
        } else {
            printf("Usuario nao encontrado. Deseja cadastrar um novo usuario? (S/N)\n");
            char respt;
            scanf("%c", &respt);
            limparBuffer();

            if (respt == 'S' || respt == 's')
            {
                SubTelaCadUsu();
                break;
            } else {
                break;
            }
        }
    }
}
