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
    bool datavalida = false;
    bool cpf_valido = false;
    bool nomevalido = false;
    bool telvalido = false;
    bool emailvalido = false;

    while (1) {
        system("clear || cls");
        Tela_CadUsu();

        do {
            printf("Digite seu nome: ");
            scanf("%14s", usu->nome);
            limparBuffer();

            printf("Digite seu sobrenome: ");
            scanf("%14s", usu->sobrenome); 
            limparBuffer();

            nomevalido = validarnome(usu->nome, usu->sobrenome);

            if (!nomevalido) {
                printf("Nome ou sobrenome inválidos, tente novamente.\n");
            }
            } while (!nomevalido);

        do {
            printf("Digite seu CPF: (apenas numeros) ");
            scanf("%11s", usu->cpf);
            cpf_valido = validarcpf(usu->cpf);
            limparBuffer();

            if (!cpf_valido) {
                printf("CPF invalido, tente novamente.\n");
            }
            } while (!cpf_valido);

        do {
            printf("insira dia do nascimento: ");
            fgets(usu->dia , sizeof(usu->dia), stdin);
            limparBuffer();
            printf("insira mes da nascimento: ");
            fgets(usu->mes , sizeof(usu->mes), stdin);
            limparBuffer();
            printf("insira ano da nascimento: ");
            fgets(usu->ano , sizeof(usu->ano), stdin);
            limparBuffer();

            datavalida = validardata(usu->dia, usu->mes, usu->ano);

            if (!datavalida) {
                printf("Data invalida, tente novamente.\n");
            }
            } while (!datavalida);

        do {
            printf("Telefone: (apenas numeros) ");
            fgets(usu->telefone, sizeof(usu->telefone), stdin);
            limparBuffer();

            telvalido = validartelefone(usu->telefone);

            if (!telvalido) {
                printf("Telefone invalido, tente novamente\n");
            }
            } while (!telvalido);

        do {
            printf("Email: (deve conter arroba) ");
            scanf("%25s", usu->email);
            limparBuffer();
            
            emailvalido = validaremail(usu->email);
            if (!emailvalido) {
                printf("Email invalido, tente novamente.\n");
            }
            } while (!emailvalido);

            printf("Crie uma senha: ");
            scanf("%50s", usu->senha);
            

        usu->ativo = 1;

        salvarusuario(usu);

        printf("Seja bem-vindo %s\n", usu->nome);

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
    bool cpf_valido = false;
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
            return;
        }

    fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);

    do {
            printf("Digite seu nome: ");
            scanf("%14s", usuarioatt.nome);
            usuarioatt.nome[strcspn(usuarioatt.nome, "\n")] = '\0';

            printf("Digite seu sobrenome: ");
            scanf("%14s", usuarioatt.sobrenome);
            usuarioatt.sobrenome[strcspn(usuarioatt.sobrenome, "\n")] = '\0';

            nomevalido = validarnome(usuarioatt.nome, usuarioatt.sobrenome);

            if (!nomevalido) {
                printf("Nome ou sobrenome invalidos, tente novamente.\n");
            }
            } while (!nomevalido);

        do {
            printf("Digite seu CPF: ");
            scanf("%12s", usuarioatt.cpf);
            cpf_valido = validarcpf(usuarioatt.cpf);
            limparBuffer();

            if (!cpf_valido) {
                printf("CPF invalido, tente novamente.\n");
            }
            } while (!cpf_valido);

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

            telvalido = validartelefone(usuarioatt.telefone);

            if (!telvalido) {
                printf("Telefone invalido, tente novamente\n");
            }
            } while (!telvalido);

        do {
            printf("Email: ");
            fscanf("%s", usuarioatt.email);
            usuarioatt.email[strcspn(usuarioatt.email, "\n")] = '\0';
            emailvalido = validaremail(usuarioatt.email);
            if (!emailvalido) {
                printf("Email invalido, tente novamente.\n");
            }
            } while (!emailvalido);

    fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);
    fwrite(&usuarioatt, sizeof(Usuario), 1, arquivousuarios);

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
                printf("Nome: %s %s\n", usuarioEncontrado.nome, usuarioEncontrado.sobrenome);
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

void SubTelaDelUsu(void)
{   
    Usuario usu;
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
                if (strcmp(usu.cpf, cpf) == 0) {
                    usu.ativo = 0; // marca usuario como ausente
                    fseek(arquivousuarios, -sizeof(Usuario), SEEK_CUR);
                    fwrite(&usuario, sizeof(Usuario), 1, arquivousuarios);
                    break;
                }
            }

        fclose(arquivousuarios);

    if (usu.ativo == 0){
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
    if(arquivousuarios == NULL){
        printf("Erro\n");
        return;
    }

    printf("%-20s %-15s %-14s %-15s %-20s\n", "Nome", "Data de Nasc.", "CPF", "Telefone", "Email");
    
    while(fread(&usuario, sizeof(Usuario), 1, arquivousuarios) == 1){
        printf("%-20s %-15s %-14s %-15s %-20s\n", 
               strcat(usuario.nome, usuario.sobrenome),
               strcat(usuario.dia, strcat("/", strcat(usuario.mes, strcat("/", usuario.ano)))), 
               usuario.cpf,
               usuario.telefone,
               usuario.email);
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
    qsort(usuarios, num_usuarios, sizeof(Usuario), comparador);

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

void salvarusuario(Usuario* usu){

    FILE *arquivousuarios;
    arquivousuarios = fopen("usuarios.dat", "ab");

    if(arquivousuarios == NULL){
        printf("erro abrindo arquivo");
        return;

        fwrite(usu, sizeof(Usuario), 1, arquivousuarios);

    fclose(arquivousuarios);
    free(usu);
    }
}
