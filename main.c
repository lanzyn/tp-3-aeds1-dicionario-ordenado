#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/tad_sorting.h"

#define UPPER_A 65
#define UPPER_Z 90

#define LOWER_A 97
#define LOWER_Z 122

void clrscr() {
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else
    #endif
}

int main() {
    tipo_dicionario dicionario;
    new_dicionario new_dicionario;
    sorting_informations information;

    char nome_arquivo[100] = {};// Variável que recebe o nome do arquivo para ser lido
    char palavra_menu[100]; // Variável que recebe palavras para serem verificadas ou removidas
    char letra_desejada;  // Variável que recebe uma letra para associar com determinada lista
    int num_letra; num_letra = 0; // Variável que recebe o número da letra
    int cont_num_palavras; cont_num_palavras = 0; // Variável que recebe o número total de palavras do texto
    int loop; loop = 1; // Variável de loop para o menu
    int option; // Variável que recebe a opção do menu
    int loop_sort; loop_sort = 1; // // Variável de loop para o menu de ordenação
    int option_sort; // Variável que recebe a opção do menu de ordenação
    int sorting; // Variável que recebe a ordenação desejada

    while (loop) {
        // Operações disponíveis no menu
        printf("\n---------------------- DICIONÁRIO DE AEDS ----------------------\n");
        printf("Opções do dicionário:\n");
        printf("Nome do arquivo: %s\n", nome_arquivo); // Exibe o nome do arquivo que foi aberto
        printf("1. Inserir nome do arquivo\n"); // Inserir o nome do arquivo desejado
        printf("2. Construir o dicionário do texto\n"); // Constrói o dicionário
        printf("3. Exibir a lista de palavras de determinada letra\n"); // Exibe a lista de palavras de uma determinada letra
        printf("4. Exibir toda a lista de palavras do texto\n"); // Exibe toda a lista de palavras do texto
        printf("5. Verificar o número de palavras do texto\n"); // Exibe o número de palavras únicas do texto de cada letra e total
        printf("6. Verificar se determinada palavra está na lista de palavras do texto\n"); // Verifica se determinada palavra está nas listas
        printf("7. Remover determinada palavra de uma lista de palavras\n"); // Remove um determina palavra de uma determina lista
        printf("8. Ordenação\n"); // Ordenção do dicionário através de diferentes métodos de ordenação
        printf("9. Instruções para usar o programa\n"); // Breve explicação de como usar o programa
        printf("10. Sair do programa\n"); // Encerra o programa
        printf("----------------------------------------------------------------\n");
        printf("Opção desejada: ");
        scanf("%d", &option);
        clrscr();

        // Implementação do menu de operações do programa
        switch (option) {
            case 1 :
                printf("Nome do arquivo desejado: ");
                scanf("%s", nome_arquivo);
                break;
            case 2 :
                constroi_dicionario(&dicionario, nome_arquivo);
                break;
            case 3 :
                printf("Insira uma letra: ");
                scanf("%s", &letra_desejada);
                printf("\n");
                imprime_dicionario_letra(&dicionario, letra_desejada);
                break;
            case 4 :
                imprime_dicionario_completo(&dicionario);
                break;
            case 5 :
                for (num_letra = 0; num_letra < 26; num_letra++) {
                    printf("\n------------------------------------------------------------\n");
                    printf("%d palavras únicas com a letra |%c|\n", retorna_numero_palavras(&dicionario.alfabeto[num_letra].lista_palavras), 
                    dicionario.alfabeto[num_letra].identificador_upper);
                    cont_num_palavras = cont_num_palavras + retorna_numero_palavras(&dicionario.alfabeto[num_letra].lista_palavras);
                    printf("------------------------------------------------------------\n");
                }
                printf("\n------------------------------------------------------------\n");
                printf("Número total de palavras únicas: %d\n", cont_num_palavras);
                printf("------------------------------------------------------------\n");
                cont_num_palavras = 0;
                break;
            case 6 :
                printf("Insira uma letra: ");
                scanf("%s", &letra_desejada);
                if (letra_desejada >= LOWER_A && letra_desejada <= LOWER_Z) {
                    num_letra = letra_desejada - LOWER_A;
                }
                else if (letra_desejada >= UPPER_A && letra_desejada <= UPPER_Z) {
                    num_letra = letra_desejada - UPPER_A;
                }
                else {
                    printf("O caractere informado não existe!\n");
                    break;
                }
                printf("Palavra que deseja verificar: ");
                scanf("%s", palavra_menu);
                if (verifica_pertencimento_lista_palavras(&dicionario.alfabeto[num_letra].lista_palavras, palavra_menu) == 1) {
                    printf("A palavra <%s> foi encontrada na lista de palavras de letra |%c|\n", palavra_menu, letra_desejada);
                }
                else {
                    printf("A palavra não foi encontrada!\n");
                }
                break;
            case 7 :
                printf("Insira uma letra: ");
                scanf("%s", &letra_desejada);
                if (letra_desejada >= LOWER_A && letra_desejada <= LOWER_Z) {
                    num_letra = letra_desejada - LOWER_A;
                }
                else if (letra_desejada >= UPPER_A && letra_desejada <= UPPER_Z) {
                    num_letra = letra_desejada - UPPER_A;
                }
                else {
                    printf("O caractere informado não existe!\n");
                    break;
                }
                printf("Palavra que deseja remover: ");
                scanf("%s", palavra_menu);
                if (remove_palavra_informada(&dicionario.alfabeto[num_letra].lista_palavras, palavra_menu) == 1) {
                    printf("A palavra <%s> foi removida com sucesso!\n", palavra_menu);
                }
                else {
                    printf("Não foi possível remover a palavra!\n");
                }
                break;
            case 8 :
                loop_sort = 1;
                while (loop_sort) {
                    // Operações disponíveis no menu de ordenação
                    printf("\n-------------------- ORDENAÇÃO DO DICIONÁRIO --------------------\n");
                    printf("Opções de ordenação:\n");
                    printf("Nome do arquivo: %s\n", nome_arquivo); // Exibe o nome do arquivo que foi aberto
                    printf("1. Construir o dicionário do texto\n"); // Constrói o dicionário do texto, desta vez implementado com vetores
                    printf("2. Ordenar e exibir a lista de palavras de determinada letra\n"); // Ordena e exibe a lista de palavras de uma determinada letra
                    printf("3. Ordenar e exibir toda a lista de palavras do texto\n"); // Ordena e exibe toda a lista de palavras do texto
                    printf("4. Instruções e observações para realizar a ordenação\n"); // Breve explicação de como usar o programa
                    printf("5. Sair da ordenação e voltar ao menu inicial\n"); // Encerra a ordenação e retorna ao menu inicial
                    printf("\n-----------------------------------------------------------------\n");
                    printf("Opção desejada: ");
                    scanf("%d", &option_sort);
                    clrscr();

                    // Implementação do menu de ordenação de operações do programa
                    switch (option_sort) {
                        case 1 :
                            constroi_new_dicionario(&new_dicionario, &dicionario);
                            break;
                        case 2 :
                            set_new_informations(&information);
                            printf("Insira uma letra: ");
                            scanf("%s", &letra_desejada);
                            if (letra_desejada >= LOWER_A && letra_desejada <= LOWER_Z) {
                                num_letra = letra_desejada - LOWER_A;
                            }
                            else if (letra_desejada >= UPPER_A && letra_desejada <= UPPER_Z) {
                                num_letra = letra_desejada - UPPER_A;
                            }
                            else {
                                printf("O caractere informado não existe!\n");
                                break;
                            }
                            printf("\n");
                            printf("Informe o método de ordenação desejado:\n");
                            printf("\n");
                            printf("1. Bubble Sort\n");
                            printf("2. Selection Sort\n");
                            printf("3. Insertion Sort\n");
                            printf("4. Shell Sort\n");
                            printf("5. Quick Sort\n");
                            printf("6. Heap Sort\n");
                            printf("\n");
                            printf("Método desejado: ");
                            scanf("%d", &sorting);
                            clrscr();

                            switch (sorting) {
                                case 1 :
                                    printf("-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Bubble Sort!\n");
                                    bubble_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("SORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    break;
                                case 2 :
                                    printf("-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Selection Sort!\n");
                                    selection_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("SORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    break;
                                case 3 :
                                    printf("-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Insertion Sort!\n");
                                    insertion_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("SORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    break;
                                case 4 :
                                    printf("-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("Ordenação com Shell Sort!\n");
                                    shell_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    printf("\n-----------------------------------------------------------------\n");
                                    printf("SORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    break;
                                case 5 :
                                    printf("-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Quick Sort!\n");
                                    quick_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("SORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    break;
                                case 6 :
                                    printf("-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Heap Sort!\n");
                                    heap_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("SORTED:\n\n");
                                    imprime_new_dicionario_letra(&new_dicionario, &dicionario, letra_desejada);
                                    printf("-----------------------------------------------------------------\n");
                                    break;
                                default :
                                    break;
                            }
                            break;
                        case 3 :
                            set_new_informations(&information);
                            printf("Informe o método de ordenação desejado:\n");
                            printf("\n");
                            printf("1. Bubble Sort\n");
                            printf("2. Selection Sort\n");
                            printf("3. Insertion Sort\n");
                            printf("4. Shell Sort\n");
                            printf("5. Quick Sort\n");
                            printf("6. Heap Sort\n");
                            printf("\n");
                            printf("Método desejado: ");
                            scanf("%d", &sorting);
                            clrscr();
                            switch (sorting) {
                                case 1 :
                                    printf("\n-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Bubble Sort!\n");
                                    for (num_letra = 0; num_letra < 26; num_letra++) {
                                        bubble_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    }
                                    printf("\n\n-----------------------------------------------------------------\n");
                                    printf("SORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    show_sorting_informations(&information, num_letra);
                                    break;
                                case 2 :
                                    printf("\n-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Selection Sort!\n");
                                    for (num_letra = 0; num_letra < 26; num_letra++) {
                                        selection_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    }
                                    printf("\n\n-----------------------------------------------------------------\n");
                                    printf("SORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    show_sorting_informations(&information, num_letra);
                                    break;
                                case 3 :
                                    printf("\n-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Insertion Sort!\n");
                                    for (num_letra = 0; num_letra < 26; num_letra++) {
                                        insertion_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    }
                                    printf("\n\n-----------------------------------------------------------------\n");
                                    printf("SORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    show_sorting_informations(&information, num_letra);
                                    break;
                                case 4 :
                                    printf("\n-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Shell Sort!\n");
                                    for (num_letra = 0; num_letra < 26; num_letra++) {
                                        shell_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    }
                                    printf("\n\n-----------------------------------------------------------------\n");
                                    printf("SORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    show_sorting_informations(&information, num_letra);
                                    break;
                                case 5 :
                                    printf("\n-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Quick Sort!\n");
                                    for (num_letra = 0; num_letra < 26; num_letra++) {
                                        quick_sort(&information, &dicionario, &new_dicionario, num_letra);
                                    }
                                    printf("\n\n-----------------------------------------------------------------\n");
                                    printf("SORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    show_sorting_informations(&information, num_letra);
                                    break;
                                case 6 :
                                    printf("\n-----------------------------------------------------------------\n");
                                    printf("UNSORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    printf("-----------------------------------------------------------------\n");
                                    printf("\nOrdenação com Heap Sort!\n");
                                    for (num_letra = 0; num_letra < 26; num_letra++) {
                                        heap_sort(&information, &dicionario, &new_dicionario, num_letra);;
                                    }
                                    printf("\n\n-----------------------------------------------------------------\n");
                                    printf("SORTED:\n");
                                    imprime_new_dicionario_completo(&new_dicionario, &dicionario);
                                    show_sorting_informations(&information, num_letra);
                                    break;
                                default :
                                    break;
                            }
                            break;
                        case 4 :
                            printf("Instruções:\n");
                            printf("Passo 1 - Construir o dicionário com suas listas de palavras, só que desta vez com vetores (1)\n");
                            printf("Passo 2 - Utilizar as demais funções de ordenação conforme sua vontade\n");
                            printf("Observações:\n");
                            printf("- Seguir as instruções anteriores do DICIONÁRIO DE AEDS e do ORDENAÇÃO DO DICIONÁRIO\n");
                            printf("para cada novo arquivo inserido ou mudança feita na lista de palavras original\n");
                            printf("- A função construir dicionário (1) serve também para voltor o dicionário para sua ordem original\n");
                            printf("- As informações de ordenação exibidas são para aquela lista de palavras e método em específico\n");
                            break;
                        case 5 :
                            loop_sort = 0;
                            break;
                        default :
                            printf("Opção inválida! Tente novamente.\n");
                    }
                }
                break;
            case 9 :
                printf("Instruções:\n");
                printf("Passo 1 - Inserir o nome do arquivo de texto que deseja ler e receber suas informações (1)\n");
                printf("Passo 2 - Construir o dicionário com suas listas de palavras (2)\n");
                printf("Passo 3 - Utilizar as demais funções conforme sua vontade\n");
                break;
            case 10 :
                printf("Obrigado por usar nosso dicionário :)\n");
                loop = 0;
                break;
            default :
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}