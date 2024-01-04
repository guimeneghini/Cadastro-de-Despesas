#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char descricao[50];
    float valor;
    int mes;
    int ano;
} Despesa;

void acoes() {
    printf("Escolha o numero da acao que deseja fazer\n\n");
    printf("1- Inclusao de despesa\n");
    printf("2- Alteracao de despesa\n");
    printf("3- Relatorio\n");
    printf("4- Pesquisa\n");
    printf("5- Exclusao de despesa\n\n");
}

void corrigeErroUsuario(int *p) {
    int aux;
    printf("Opcao invalida.\n");
    printf("Por favor selecione uma opcao de 1 a 5: \n");
    scanf("%d", &aux);
    *p = aux;
}

void corrigeErroEscolha(int *p) {
    int aux;
    printf("Opcao invalida.\n");
    printf("Por favor selecione a opcao 1 ou 2: \n");
    scanf("%d", &aux);
    *p = aux;
}

void inclusaoDeDespesa(FILE *arq) {
    Despesa var, var2;
    int verificadora = 0;

    printf("Voce escolheu a opcao 1\n");
    printf("Escreva a descricao:\n");
    scanf(" %[^\n]s", var.descricao);
    printf("Insira o valor da despesa:\n");
    scanf("%f", &var.valor);
    printf("Insira o numero do mes da despesa:\n");
    scanf("%d", &var.mes);
    printf("Insira o numero do ano da despesa:\n");
    scanf("%d", &var.ano);

    arq = fopen("despesas.txt", "a+b");
    if (!arq) {
        printf("O arquivo não pode ser aberto.");
        exit(1);
    }

    fseek(arq, 0, SEEK_SET);

    while (fread(&var2, sizeof(Despesa), 1, arq) != 0) {
        if (strcmp(var2.descricao, var.descricao) == 0) {
            printf("Nao pode ser incluida uma despesa de mesma descricao.\n");
            verificadora = 1;
            break;
        }
    }

    fseek(arq, 0, SEEK_END);

    if (verificadora == 0) {
        fwrite(&var, sizeof(Despesa), 1, arq);
    }

    fclose(arq);
}

void alteracaoDeDespesa(FILE *arq) {
    char descricao[15];
    FILE *arqNew;
    Despesa var;
    int verificadora = 0;

    printf("Voce escolheu a opcao 2\n");

    printf("Insira a descricao da despesa:\n");
    scanf(" %[^\n]s", descricao);

    arq = fopen("despesas.txt", "rb");
    rewind(arq);

    if (!arq) {
        printf("O arquivo não pode ser aberto.");
        exit(1);
    }

    arqNew = fopen("despesas2.txt", "a+b");
    if (!arqNew) {
        printf("O arquivo não pode ser aberto.");
        exit(1);
    }

    while (fread(&var, sizeof(Despesa), 1, arq) == 1) {
        if (strcmp(var.descricao, descricao) == 0) {
            printf("Descricao: %s\n", var.descricao);
            printf("Valor: %.2f\n", var.valor);
            printf("Mes: %d\n", var.mes);
            printf("Ano: %d\n", var.ano);

            printf("Qual o novo valor:\n");
            scanf("%f", &var.valor);

            printf("Qual o novo mes:\n");
            scanf("%d", &var.mes);

            printf("Qual o novo ano:\n");
            scanf("%d", &var.ano);

            verificadora++;

        }
        fwrite(&var, sizeof(Despesa), 1, arqNew);
    }

    if (verificadora == 0) {
        printf("Nao ha arquivos para serem alterados com essa descricao.\n");
    }

    fclose(arqNew);
    fclose(arq);

    remove("despesas.txt");
    rename("despesas2.txt", "despesas.txt");
}

void relatorio(FILE *arq) {
    printf("Voce escolheu a opcao 3\n");

    Despesa var;
    arq = fopen("despesas.txt", "rb");

    if (!arq) {
        printf("O arquivo não pode ser aberto.");
        exit(1);
    }

    rewind(arq);

    while (fread(&var, sizeof(Despesa), 1, arq) == 1) {
        printf("Descricao: %s\n", var.descricao);
        printf("Valor: %.2f\n", var.valor);
        printf("Mes: %d\n", var.mes);
        printf("Ano: %d\n", var.ano);
        printf("\n\n");
    }

    fclose(arq);
}

void pesquisa(FILE *arq) {
    Despesa var;
    char descricao[15];

    printf("Voce escolheu a opcao 4\n");

    printf("Escreva a descricao:\n");
    scanf(" %[^\n]s", descricao);

    arq = fopen("despesas.txt", "rb");

    if (!arq) {
        printf("O arquivo não pode ser aberto.");
        exit(1);
    }

    rewind(arq);

    while (fread(&var, sizeof(Despesa), 1, arq) == 1) {
        if (strcmp(descricao, var.descricao) == 0) {
            printf("Descricao: %s\n", var.descricao);
            printf("Valor: %.2f\n", var.valor);
            printf("Mes: %d\n", var.mes);
            printf("Ano: %d\n", var.ano);
        }
    }

    fclose(arq);
}

void exclusaoDeDespesa(FILE *arq) {
    printf("Voce escolheu a opcao 5\n");

    FILE *arqNew;
    char descricao[15];
    int opcao;

    Despesa var;
    int verificadora = 0;

    arq = fopen("despesas.txt", "rb");
    if (!arq) {
        printf("O arquivo não pode ser aberto.\n");
        exit(1);
    }

    printf("Informe a descricao da despesa que deseja excluir:\n");
    scanf(" %[^\n]s", descricao);

    printf("Deseja mesmo excluir a despesa?\n1- sim\n2- nao\n");
    scanf("%d", &opcao);
    fflush(stdin);

    if(opcao==1){

        arqNew = fopen("despesas2.txt", "a+b");
        if (!arqNew) {
            printf("O arquivo não pode ser aberto.\n");
            exit(1);
        }

        while (fread(&var, sizeof(Despesa), 1, arq) == 1) {
            if (strcmp(var.descricao, descricao) == 0) {
                verificadora++;
            } else {
                fwrite(&var, sizeof(Despesa), 1, arqNew);
            }
        }

        if (verificadora != 0) {
            fclose(arqNew);
            fclose(arq);

            remove("despesas.txt");
            rename("despesas2.txt", "despesas.txt");

        } else {
            printf("Nao ha despesas com essa descricao para serem excluidas.\n");
            fclose(arqNew);
            fclose(arq);
        }

        printf("O programa executou.\n");
    }
}

void chamaFuncao(int opcao, FILE *arq) {
    switch (opcao) {
        case 1:
            inclusaoDeDespesa(arq);
            break;
        case 2:
            alteracaoDeDespesa(arq);
            break;
        case 3:
            relatorio(arq);
            break;
        case 4:
            pesquisa(arq);
            break;
        default:
            exclusaoDeDespesa(arq);
            break;
    }
}

int main() {
    int opcao, escolha;
    int *p_opcao, *p_escolha;
    FILE *arq;

    printf("CADASTRO DE DESPESAS\n\n");
    printf("Bem vindo ao menu de escolhas\n\n");

    do {
        acoes();
        scanf("%d", &opcao);
        fflush(stdin);
        p_opcao = &opcao;

        while (opcao > 5 || opcao < 1) {
            corrigeErroUsuario(p_opcao);
        }

        chamaFuncao(opcao, arq);

        printf("Deseja continuar no programa?\n");
        printf("Escolha o numero da opcao\n");
        printf("1- Sim\n");
        printf("2- Nao\n\n");

        scanf("%d", &escolha);

        p_escolha = &escolha;

        while (escolha > 2 || escolha < 1) {
            corrigeErroEscolha(p_escolha);
        }

    } while (escolha != 2);

    return 0;
}