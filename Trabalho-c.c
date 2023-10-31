#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura de dados para um registro
struct Registro
{
    char nome[50];
    int idade;
    char telefone[15];
    char endereco[100];
};

// função para adicionar um novo registro
void adicionarRegistro(struct Registro *registros, int *quantidade)
{
    struct Registro novoRegistro;

    // lê cada topico com espaços
    printf("Nome: ");
    scanf(" %[^\n]s", novoRegistro.nome);
    printf("Idade: ");
    scanf("%d", &novoRegistro.idade);
    printf("Telefone: ");
    scanf(" %[^\n]s", novoRegistro.telefone);
    printf("Endereco: ");
    scanf(" %[^\n]s", novoRegistro.endereco);

    system("cls");

    registros[*quantidade] = novoRegistro;
    (*quantidade)++; // Incrementa o número de registros
    printf("------------------------------------\n| Registro adicionado com sucesso! |\n------------------------------------");

}

// lista de todos os registros
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

int main()
{

    system("mode 55,25");

    struct Registro registros[100]; // array de registros
    int quantidade = 0;             // numero atual de registros

    int opcao;
    while (1)
    {
        printf("\nMenu Principal:\n");
        printf("1. Adicionar um novo registro\n");
        printf("2. Listar todos os registros\n");
        printf("3. Sair do programa\n");
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

            system("cls");
            printf("Encerrando o programa.\n");

            return 0;

        default:

            system("cls");
            printf("Opcao invalida. Tente novamente.\n");

        }
    }
}