#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "subtelas.h"
#include "validadores.h"

void SubTelaCadUsu(void){
    char telefone[100];
    char email[50];
    char nome[100];
    char sobrenome[100];
    int tamanhoda_nametag = strlen(nome) + strlen(sobrenome) + strlen(tresdigitos) +3;
    char *nametag = (char*)malloc(tamanhoda_nametag);
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
                nome[strcspn(nome,"\n")] = '\0';

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
        free(nametag);

        printf("Seja bem-vindo %s\n\n", nome);
        printf("Sua nametag >>> %s <<<< guarde-a para usar em outras entradas \n\n", nametag);

        printf("Deseja adicionar outro usuario?(S/N)");
        scanf(" %c", &respt);
        getchar();

    // funcao de loop para caso queira fazer a operacao dnv, voltar a funcao, senao ir ao menu principal
    switch (respt){
    case 'S':
    case 's':
        SubTelaCadUsu();
        break;
    case 'N':
    case 'n':
        return;
    default:
        printf("Funcao invalida");
        }
    }  
}

void SubTelaDelUsu(void){
    char nametag[100];
    char respt;

    while (1)
    {
        system("clear || cls");

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
            SubTelaDelUsu();
            break;
        case 'N':
        case 'n':
            return;
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaAttUsu(void){
    char nametag[100];
    char respt;

    while (1)
    {
        system("clear || cls");

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
            SubTelaAttUsu();
            break;
        case 'N':
        case 'n':
            return;
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaLerUsu(void){
    char nametag[100];
    char respt;
    while (1)
    {
        system("clear || cls");

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
            SubTelaLerUsu();
            break;
        case 'N':
        case 'n':
        return;
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaListarUsu(void){

}


void SubTelaRegVen(void){
    float preco;
    int dia, mes, ano;
    bool datavalida;
    char categoria[100];
    bool categoriaval = false;
    char respt;

    while (1)
    {
        system("clear || cls");

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
            SubTelaRegVen();
            break;
        case 'N':
        case 'n':
        return;
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaDelVen(void){
    char nametag[100];   
    char respt;

    while (1)
    {
        system("clear || cls");

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
            SubTelaDelVen();
            break;
        case 'N':
        case 'n':
        return;
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaAttVen(void){
    char respt;
    char nametag[100];
    while (1)
    {
        system("clear || cls");

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
            SubTelaAttVen();
            break;
        case 'N':
        case 'n':
        return;
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaLerVen(void){
    char nametag[100];
    char respt;

    while (1)
    {
        system("clear || cls");

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
            SubTelaLerVen();
            break;
        case 'N':
        case 'n':
        return;
        default:
            printf("Funcao invalida");
        }
    }
}

void SubTelaListarVen(void){
    
}
