#include <stdio.h>
//#include <locale.h>

enum Genero
{
    FICCAO,
    NAO_FICCAO,
    ROMANCE,
    FANTASIA,
    HISTORIA,
    OUTRO
};

struct Livro
{
    char nomeLivro[25], nomeAutor[30];
    enum Genero generoLivro;
    int quantidade;
};

int cadastraLivro(struct Livro biblioteca[], int contadorLivros)
{
    if (contadorLivros >= 100)
    {
        printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
        return contadorLivros;
    }

    printf("Nome do Livro: ");
    fgets(biblioteca[contadorLivros].nomeLivro, 25, stdin);

    printf("Nome do Autor: ");
    fgets(biblioteca[contadorLivros].nomeAutor, 30, stdin);

    printf("Gênero do Livro (0-Ficção, 1-Não Ficção, 2-Romance, 3-Fantasia, 4-História, 5-Outro): ");
    scanf("%d", &biblioteca[contadorLivros].generoLivro);
    getchar(); // Limpa o caractere de nova linha do buffer

    printf("Quantidade: ");
    scanf("%d", &biblioteca[contadorLivros].quantidade);
    getchar(); // Limpa o caractere de nova linha do buffer

    limpaTerminal();
    printf("Livro Cadastrado com Sucesso!!!\n\n");
    return contadorLivros + 1; // Retorna o novo valor do contador
}

void limpaTerminal()
{
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}

void listarLivros(struct Livro biblioteca[], int contadorLivros)
{
    for (int i = 0; i < contadorLivros; i++)
    {
        printf("Livro %d:\n", i + 1);
        printf("Nome do Livro: %s", biblioteca[i].nomeLivro);
        printf("Nome do Autor: %s", biblioteca[i].nomeAutor);

        switch (biblioteca[i].generoLivro)
        {
        case FICCAO:
            printf("Gênero: Ficção\n");
            break;
        case NAO_FICCAO:
            printf("Gênero: Não Ficção\n");
            break;
        case ROMANCE:
            printf("Gênero: Romance\n");
            break;
        case FANTASIA:
            printf("Gênero: Fantasia\n");
            break;
        case HISTORIA:
            printf("Gênero: História\n");
            break;
        case OUTRO:
            printf("Gênero: Outro\n");
            break;
        default:
            printf("Gênero inválido\n");
        }

        printf("Quantidade: %d\n", biblioteca[i].quantidade);
        printf("---------------------------\n");
    }
}

int main()
{
    struct Livro biblioteca[100];
    int contadorLivros = 0;
    int ValorInicial;
    //setlocale(LC_ALL, "pt_BR.UTF-8");
    limpaTerminal();
    printf("Bem vindo a Biblioteca-Virtual\n");

    while (1)
    {
        printf("Digite 1 para cadastra um livro \nDigite 2 para consultar os livros disponíveis\nDigite 0 para sair\n");

        scanf("%d", &ValorInicial);
        getchar();

        switch (ValorInicial)
        {
        case 0:
            printf("Saindo...");
            return 0;

        case 1:
            limpaTerminal();
            contadorLivros = cadastraLivro(biblioteca, contadorLivros);
            break;

        case 2:
            limpaTerminal();
            listarLivros(biblioteca, contadorLivros);
            break;

        default:
            printf("Opção invalida. Tente novamente \n");
        }
    }

    return 0;
}