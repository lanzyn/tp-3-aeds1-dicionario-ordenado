#include "../headers/tad_sorting.h"

void bubble_sort(new_dicionario *new_dicionario, int length, int num_letra) {
    int com; com = 0;
    int mov; mov = 0;
    int i, j;
    char *aux;

    clock_t start, end;
    time_t t_start, t_end;
    double cpu_time_used;
    double time_used;

    start = clock();
    t_start = time(NULL);

    for (i = 0; i < length - 1; i++) {
        for (j = 1; j < length - i; j++) {
            com++;
            if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1]) < 0) {
                strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]);
                strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1]);
                strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1], aux);
                mov++;
            }
        }
    }

    end = clock();
    t_end = time(NULL);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_used = difftime(t_end, t_start);

    printf("\n");
    printf("Tempo (método clock_t): %lf\n", cpu_time_used);
    printf("Tempo (método time_t): %lf\n", time_used);
    printf("Comparações: %d\n", com);
    printf("Movimentações: %d\n", mov);
    printf("\n");
    printf("-----------------------------------------------------------------\n");
}