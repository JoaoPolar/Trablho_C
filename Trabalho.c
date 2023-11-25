#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Registro
{
    char nome[50];
    int idade;
    char telefone[15];
    char endereco[100];
};

void adicionarRegistro(struct Registro *registros, int *quantidade)
{
    struct Registro novoRegistro;

    printf("Nome: ");
    scanf(" %[^\n]s", novoRegistro.nome);
    printf("Idade: ");
    scanf("%d", &novoRegistro.idade);
    printf("Telefone: ");
    scanf(" %[^\n]s", novoRegistro.telefone);
    printf("Endereco: ");
    scanf(" %[^\n]s", novoRegistro.endereco);

    registros[*quantidade] = novoRegistro;
    (*quantidade)++;
    printf("------------------------------------\n| Registro adicionado com sucesso! |\n------------------------------------");
}

void listarRegistros(const struct Registro *registros, int quantidade)
{
    if (quantidade == 0)
    {
        printf("-----------------------------\n|Nenhum registro encontrado.|\n-----------------------------");
        return;
    }

    printf("-----------\n|Registros|\n-----------");
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nQuantidade de registros: %d\n", i + 1);
        printf("Nome: %s\n", registros[i].nome);
        printf("Idade: %d\n", registros[i].idade);
        printf("Telefone: %s\n", registros[i].telefone);
        printf("Endereco: %s\n", registros[i].endereco);
    }
}

void excluirRegistro(struct Registro *registros, int *quantidade, int id)
{
    if (id < 1 || id > *quantidade)
    {
        printf("ID de registro invalido!\n");
        return;
    }

    for (int i = id - 1; i < *quantidade - 1; i++)
    {
        registros[i] = registros[i + 1];
    }

    (*quantidade)--;
    printf("Registro com ID %d excluido com sucesso!\n", id);
}

void atualizarRegistro(struct Registro *registros, int quantidade, int id)
{
    if (id < 1 || id > quantidade)
    {
        printf("ID de registro invalido!\n");
        return;
    }

    printf("Atualizando registro com ID %d:\n", id);

    struct Registro novoRegistro;

    printf("Nome: ");
    scanf(" %[^\n]s", novoRegistro.nome);
    printf("Idade: ");
    scanf("%d", &novoRegistro.idade);
    printf("Telefone: ");
    scanf(" %[^\n]s", novoRegistro.telefone);
    printf("Endereco: ");
    scanf(" %[^\n]s", novoRegistro.endereco);

    registros[id - 1] = novoRegistro;
    printf("Registro com ID %d atualizado com sucesso!\n", id);
}

int main()
{
    struct Registro registros[100];
    int quantidade = 0;

    int opcao;
    while (1)
    {
        printf("\nMenu Principal:\n");
        printf("1. Adicionar um novo registro\n");
        printf("2. Listar todos os registros\n");
        printf("3. Excluir um registro\n");
        printf("4. Atualizar um registro\n");
        printf("5. Sair do programa\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            adicionarRegistro(registros, &quantidade);
            break;
        case 2:
            system("cls");
            listarRegistros(registros, quantidade);
            break;
        case 3:
        {
            system("cls");
            int id_excluir;
            printf("Digite o ID do registro que deseja excluir: ");
            scanf("%d", &id_excluir);
            excluirRegistro(registros, &quantidade, id_excluir);
            break;
        }
        case 4:
        {
            system("cls");
            int id_atualizar;
            printf("Digite o ID do registro que deseja atualizar: ");
            scanf("%d", &id_atualizar);
            atualizarRegistro(registros, quantidade, id_atualizar);
            break;
        }
        case 5:
            system("cls");
            printf("Encerrando o programa.\n");
            return 0;
        default:
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
}