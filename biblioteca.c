#include <stdio.h>

enum Genero //  OPÇÕES PREDEFINIDAS DE GENÊROS DE LIVROS
{
    FICCAO,
    NAO_FICCAO,
    ROMANCE,
    FANTASIA,
    HISTORIA,
    OUTRO
};

enum Status
{
    NUNCA_LI,
    LENDO,
    JA_LI
};

struct Livro //  ESTRUTURA DO LIVRO (PERMITE AGRUPAR DIFERENTES TIPOS DE DADOS EM UMA VARIAVEL)
{
    char nomeLivro[25], nomeAutor[30], generoPersonalizado[30];
    enum Genero generoLivro;
    enum Status statusLivro;
};

void limpaTerminal() //  FUNÇÃO PARA LIMPAR O TERMINAL DURANTE A EXECUÇÃO
{
#ifdef _WIN32 //  VERIFICA SE O SISTEMA E WINDOWS OU LINUX
    system("cls");
#else
    system("clear");
#endif
}
int cadastraLivro(struct Livro biblioteca[], int contadorLivros) // FUNÇÃO QUE VAI CADASTRAR OS LIVROS, RECEBE UM VETOR BIBLIOTECA, E UM CONTADOR DE LIVROS DIFERENTES CADASTRADOS
{
    if (contadorLivros >= 100) // VERIFICA SE HÁ 100 LIVROS DIFERENTES CADASTRADO (NÃO A QUANTIDADE DE CADA LIVRO)
    {
        printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
        return contadorLivros;
    }

    //  SOLICITA AS INFORMAÇÕES DO LIVRO E AS SALVAM NO VETOR BIBLIOTECA

    printf("Nome do Livro: ");
    fgets(biblioteca[contadorLivros].nomeLivro, 25, stdin);

    printf("Nome do Autor: ");
    fgets(biblioteca[contadorLivros].nomeAutor, 30, stdin);

    printf("Genero do Livro (0-Ficcao, 1-Nao Ficcao, 2-Romance, 3-Fantasia, 4-Historia, 5-Outro): ");
    scanf("%d", &biblioteca[contadorLivros].generoLivro);
    getchar(); // Limpa o caractere de nova linha do buffer

    if (biblioteca[contadorLivros].generoLivro == OUTRO)
    {
        printf("Digite o genero do livro: ");
        fgets(biblioteca[contadorLivros].generoPersonalizado, 30, stdin);
    }

    printf("Status (0-Nunca li, 1-Lendo, 2-Ja Li): ");
    scanf("%d", &biblioteca[contadorLivros].statusLivro);
    getchar(); // Limpa o caractere de nova linha do buffer

    limpaTerminal();
    printf("Livro Cadastrado com Sucesso!!!\n\n");
    return contadorLivros + 1; // Retorna o novo valor do contador
}

int verificaLivros(int contadorLivros)
{
    if (contadorLivros == 0)
    {
        printf("Sem livros cadastrados...\n\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

void editarLivro(struct Livro biblioteca[], int contadorLivros)
{
    int livrosVerificados = verificaLivros(contadorLivros);

    if (livrosVerificados == 0)
    {
        return;
    }

    else
    {
        listarLivros(biblioteca, contadorLivros);
        char verificaLivro[25];
        printf("\nBem vindo a edicao de livros\n\nPor favor, digite o nome do livro que voce deseja editar: ");
        fgets(verificaLivro, 25, stdin);

        int editar;

        for (int i = 0; i < contadorLivros; i++)
        {
            if (strcmp(biblioteca[i].nomeLivro, verificaLivro) == 0)
            {
                printf("Digite 1 para editar o nome\nDigite 2 para editar o autor\nDigite 3 para editar o genero\nDigite 4 para editar o status\nDigite 0 para excluir o livro\n");
                scanf("%d", &editar);

                switch (editar)
                {
                case 1:
                    printf("\nnome do livro: %s", biblioteca[i].nomeLivro);
                    fgets(biblioteca[i].nomeLivro, 25, stdin);
                    break;

                case 2:
                    printf("\nnome do autor: %s", biblioteca[i].nomeAutor);
                    fgets(biblioteca[i].nomeAutor, 25, stdin);
                    break;

                case 3:
                    switch (biblioteca[i].generoLivro)
                    {
                    case FICCAO:
                        printf("Genero: Ficcao\n");
                        break;
                    case NAO_FICCAO:
                        printf("Genero: Nao Ficcao\n");
                        break;
                    case ROMANCE:
                        printf("Genero: Romance\n");
                        break;
                    case FANTASIA:
                        printf("Genero: Fantasia\n");
                        break;
                    case HISTORIA:
                        printf("Genero: Historia\n");
                        break;
                    case OUTRO:
                        printf("Genero: %s", biblioteca[i].generoPersonalizado);
                        break;
                    default:
                        printf("Genero invalido\n");
                    }
                    printf("\nGenero do Livro (0-Ficcao, 1-Nao Ficcao, 2-Romance, 3-Fantasia, 4-Historia, 5-Outro): ");
                    scanf("%d", &biblioteca[i].generoLivro);
                    getchar(); // Limpa o caractere de nova linha do buffer

                    if (biblioteca[i].generoLivro == OUTRO)
                    {
                        printf("\nDigite o genero do livro: ");
                        fgets(biblioteca[i].generoPersonalizado, 30, stdin);
                    }
                    break;

                case 4:

                    switch (biblioteca[i].statusLivro)
                    {
                    case NUNCA_LI:
                        printf("Status: Nunca Li\n");
                        break;

                    case LENDO:
                        printf("Status: Lendo\n");
                        break;

                    case JA_LI:
                        printf("Status: Ja Li\n");
                        break;

                    default:
                        break;
                    }

                    printf("\nStatus (0-Nunca li, 1-Lendo, 2-Ja Li): ");
                    scanf("%d", &biblioteca[i].statusLivro);
                    getchar(); // Limpa o caractere de nova linha do buffer
                    break;

                default:
                    break;
                }

                break;
            }
        }
    }
}
void listarLivroUnico(struct Livro livro)
{
    printf("Nome do Livro: %s", livro.nomeLivro);
    printf("Nome do Autor: %s", livro.nomeAutor);

    switch (livro.generoLivro)
    {
    case FICCAO:
        printf("Genero: Ficcao\n");
        break;
    case NAO_FICCAO:
        printf("Genero: Nao Ficcao\n");
        break;
    case ROMANCE:
        printf("Genero: Romance\n");
        break;
    case FANTASIA:
        printf("Genero: Fantasia\n");
        break;
    case HISTORIA:
        printf("Genero: Historia\n");
        break;
    case OUTRO:
        printf("Genero: %s", livro.generoPersonalizado);
        break;
    default:
        printf("Genero invalido\n");
    }

    switch (livro.statusLivro)

    {
    case NUNCA_LI:
        printf("Status: Nunca Li\n");
        break;

    case LENDO:
        printf("Status: Lendo\n");
        break;

    case JA_LI:
        printf("Status: Ja Li\n");
        break;

    default:
        break;
    }
    printf("---------------------------\n");
}
void listarLivros(struct Livro biblioteca[], int contadorLivros) //  PERCORRE O VETOR LIVROS, EXIBINDO AS INFORMAÇ~EOS SALVAS DE CADA LIVRO
{
    int livrosVerificado = verificaLivros(contadorLivros);
    if (livrosVerificado == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < contadorLivros; i++)
        {

            if (contadorLivros == 1)
            {
                // printf("Livro: %s", biblioteca[i].nomeLivro);
                listarLivroUnico(biblioteca[0]);
            }
            else
            {

                printf("Livro %d: %s", i + 1, biblioteca[i].nomeLivro);

                printf("Nome do Autor: %s", biblioteca[i].nomeAutor);

                switch (biblioteca[i].generoLivro)
                {
                case FICCAO:
                    printf("Genero: Ficcao\n");
                    break;
                case NAO_FICCAO:
                    printf("Genero: Nao Ficcao\n");
                    break;
                case ROMANCE:
                    printf("Genero: Romance\n");
                    break;
                case FANTASIA:
                    printf("Genero: Fantasia\n");
                    break;
                case HISTORIA:
                    printf("Genero: Historia\n");
                    break;
                case OUTRO:
                    printf("Genero: %s", biblioteca[i].generoPersonalizado);
                    break;
                default:
                    printf("Genero invalido\n");
                }

                switch (biblioteca[i].statusLivro)

                {
                case NUNCA_LI:
                    printf("Status: Nunca Li\n");
                    break;

                case LENDO:
                    printf("Status: Lendo\n");
                    break;

                case JA_LI:
                    printf("Status: Ja Li\n");
                    break;

                default:
                    break;
                }
                printf("---------------------------\n");
            }
        }
    }
}

int menu(struct Livro biblioteca[], int contadorLivros)
{
    int escolha, opcao = 1;
    do
    {
        printf("Digite 1 para cadastrar um livro \nDigite 2 para consultar os livros disponiveis\nDigite 3 para editar os livros \nDigite 0 para sair\n");
        scanf("%d", &escolha);
        getchar();

        switch (escolha)
        {

        case 0:
            limpaTerminal();
            printf("Saindo...");
            opcao = 0;
            return 0;

        case 1:
            limpaTerminal();
            contadorLivros = cadastraLivro(biblioteca, contadorLivros);
            break;

        case 2:
            limpaTerminal();
            listarLivros(biblioteca, contadorLivros);
            break;

        case 3:
            limpaTerminal();
            editarLivro(biblioteca, contadorLivros);
            break;

        default:
            printf("Opcao invalida. Tente novamente \n");
        }
    } while (opcao);
}

int main()
{
    struct Livro biblioteca[100];
    int contadorLivros = 0;
    limpaTerminal();
    printf("Bem vindo a Biblioteca-Virtual\n\n");
    menu(biblioteca, contadorLivros);
    /*
        while(executa)
        {
            if (verificaLivros(contadorLivros) == 0)
            {
               executa = menu(biblioteca, contadorLivros, executa);
            }
            else
            {
                printf("\n\tRetornando ao menu...\n");
                sleep(5);
                executa = (biblioteca, contadorLivros, executa);
            }
        }*/
    return 0;
}