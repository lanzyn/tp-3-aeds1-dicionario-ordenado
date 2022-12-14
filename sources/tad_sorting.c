#include "../headers/tad_sorting.h"

void bubble_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) {
        information -> lists++;
        information -> sort_words = length;
        int i, j;
        tipo_new_palavra aux;
        clock_t start, end;
        start = clock();
        // Algoritimo Bubble Sort
        for (i = 0; i < length - 1; i++) {
            for (j = 1; j < length - i; j++) {
                information -> sort_com++;
                if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j].caracteres, 
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1].caracteres) < 0) {
                    aux = new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j];
                    new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j] = 
                    new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1];
                    new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1] = aux;
                    information -> sort_mov++;
                }
            }
        }
        end = clock();
        information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        set_next_informations(information);
        show_sorting_informations(information, num_letra);
        reset_current_information(information);
    }
}

void selection_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) {
        information -> lists++;
        information -> sort_words = length;
        int i, j;
        int min;
        tipo_new_palavra aux;
        clock_t start, end;
        start = clock();
        // Algoritmo Selection Sort
        for (i = 0; i < length - 1; i++) {
            min = i;
            for (j = i + 1; j < length; j++) {
                information -> sort_com++;
                if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j].caracteres, 
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min].caracteres) < 0) {
                    min = j;
                }
            }
            aux = new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min];
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min] =
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i];
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i] = aux;
            information -> sort_mov++;
        }
        end = clock();
        information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        set_next_informations(information);
        show_sorting_informations(information, num_letra);
        reset_current_information(information);
    }
}

void insertion_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) {
        information -> lists++;
        information -> sort_words = length;
        int i, j;
        tipo_new_palavra aux;
        clock_t start, end;
        start = clock();
        // Algoritmo Insertion Sort
        for (i = 0; i < length; i++) {
            aux = new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i];
            j = i - 1;
            information -> sort_com++;
            while ((j >= 0) && (strcmp(aux.caracteres, 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j].caracteres) < 0)) {
                if (j != i - 1) information -> sort_com++;
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1] =
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j];
                j--;
            }
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1] = aux;
            information -> sort_mov++;
        }
        end = clock();
        information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        set_next_informations(information);
        show_sorting_informations(information, num_letra);
        reset_current_information(information);
    }
}

void shell_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) {
        information -> lists++;
        information -> sort_words = length;
        int i, j;
        int h; h = 1;
        tipo_new_palavra aux;
        clock_t start, end;
        start = clock();
        // Algoritmo Shell Sort
        do {
            h = (h * 3) + 1;
        } while (h < length);
        do {
            h = h/3;
            for (i = h; i < length; i++) {
                aux = new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i];
                j = i;
                information -> sort_com++;
                while (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - h].caracteres, aux.caracteres) > 0) {
                    if (j != i) information -> sort_com++;
                    new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j] =
                    new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - h];
                    j -= h;
                    if (j < h) {
                        break;
                    }
                }
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j] = aux;
                information -> sort_mov++;
            }
        } while (h != 1);
        end = clock();
        information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        set_next_informations(information);
        show_sorting_informations(information, num_letra);
        reset_current_information(information);
    }
}

// Algoritmo Quick Sort - Sort - Partition
void quick_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) {
        information -> lists++;
        information -> sort_words = length;
        clock_t start, end;
        start = clock();
        // Algoritmo Quick Sort -> Sort -> Partition
        sort(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, 0, length - 1);
        end = clock();
        information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        set_next_informations(information);
        show_sorting_informations(information, num_letra);
        reset_current_information(information);
    }
}
void sort(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right) {
    int i, j;
    partition(information, vetor, left, right, &i, &j);
    if (left < j) sort(information, vetor, left, j);
    if (i < right) sort(information, vetor, i, right);
}
void partition(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right, int *i, int *j) {
    *i = left; *j = right;
    tipo_new_palavra pivot;
    tipo_new_palavra aux;
    pivot = vetor -> vetor_palavras[(*i + *j) / 2];
    do {
        information -> sort_com++;
        while (strcmp(pivot.caracteres, vetor -> vetor_palavras[*i].caracteres) > 0) {
            (*i)++;
        }
        information -> sort_com++;
        while (strcmp(pivot.caracteres, vetor -> vetor_palavras[*j].caracteres) < 0) {
            (*j)--;
        }
        if (*i <= *j) {
            aux = vetor -> vetor_palavras[*i];
            vetor -> vetor_palavras[*i] = vetor -> vetor_palavras[*j];
            vetor -> vetor_palavras[*j] = aux;
            information -> sort_mov++;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

// Algoritmo Heap Sort - Heap Make
void heap_sort(sorting_informations *information, tipo_dicionario *dicionario, new_dicionario *new_dicionario, int num_letra) {
    int length; length = retorna_numero_palavras(&dicionario -> alfabeto[num_letra].lista_palavras);
    if (length != 0) {
        information -> lists++;
        information -> sort_words = length;
        int i;
        tipo_new_palavra aux;
        clock_t start, end;
        start = clock();
        // Algoritmo Heap Sort -> Heap Make
        for (i = (length - 1)/2; i >= 0; i--) {
            heap_make(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, i, length - 1);
        }
        for (i = length - 1; i >= 1; i--) {
            aux = new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[0];
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[0] = 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i];
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i] = aux;
            information -> sort_mov++;
            heap_make(information, &new_dicionario -> alfabeto[num_letra].lista_palavras_vetor, 0, i - 1);
        }
        end = clock();
        information -> sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        set_next_informations(information);
        show_sorting_informations(information, num_letra);
        reset_current_information(information);
    }
}
void heap_make(sorting_informations *information, tipo_vetor_palavras *vetor, int i, int lenght) {
    tipo_new_palavra aux; aux = vetor -> vetor_palavras[i];
    int j; j = (i * 2) + 1;
    while (j <= lenght) {
        if (j < lenght) {
            information -> sort_com++;
            if (strcmp(vetor -> vetor_palavras[j].caracteres, vetor -> vetor_palavras[j + 1].caracteres) < 0) {
                j++;
            }
        }
        information -> sort_com++;
        if (strcmp(aux.caracteres, vetor -> vetor_palavras[j].caracteres) < 0) {
            vetor -> vetor_palavras[i] = vetor -> vetor_palavras[j];
            i = j;
            j = (2 * i) + 1;
        }
        else {
            j = lenght + 1;
        }
    }
    vetor -> vetor_palavras[i] = aux;
}

// Funções de Sorting Informations
void set_new_informations(sorting_informations *information) {
    information -> lists = 0;
    information -> sort_words = 0;
    information -> sort_com = 0;
    information -> sort_mov = 0;
    information -> sort_time = 0;
    information -> t_sort_words = 0;
    information -> t_sort_com = 0;
    information -> t_sort_mov = 0;
    information -> t_sort_time = 0;
    information -> md_sort_words = 0;
    information -> md_sort_com = 0;
    information -> md_sort_mov = 0;
    information -> md_sort_time = 0;
}

void set_next_informations(sorting_informations *information) {
    information -> t_sort_words = information -> t_sort_words + information -> sort_words;
    information -> t_sort_com = information -> t_sort_com + information -> sort_com;
    information -> t_sort_mov = information -> t_sort_mov + information -> sort_mov;
    information -> t_sort_time = information -> t_sort_time + information -> sort_time;
}

void reset_current_information(sorting_informations *information) {
    information -> sort_words = 0;    
    information -> sort_com = 0;
    information -> sort_mov = 0;
    information -> sort_time = 0;
}

void show_sorting_informations(sorting_informations *information, int num_letra) {
    const char letra[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("\n-----------------------------------------------------------------\n");
    if (num_letra < 26) printf("Letra |%c|\n", letra[num_letra]);
    else printf("Informações de ordenação:\n");
    printf("-----------------------------------------------------------------\n");
    printf("Palavras atuais: %.2lf\n", information -> sort_words);
    printf("Comparações atuais: %.2lf\n", information -> sort_com);
    printf("Movimentações atuais: %.2lf\n", information -> sort_mov);
    printf("Tempo atual: %lf\n", information -> sort_time);
    printf("-----------------------------------------------------------------\n");
    printf("Total de palavras: %.2lf\n", information -> t_sort_words);
    printf("Total de listas de palavras: %.2lf\n", information -> lists);
    printf("Total de comparações: %.2lf\n", information -> t_sort_com);
    printf("Total de movimentaçẽs: %.2lf\n", information -> t_sort_mov);
    printf("Tempo total: %lf\n", information -> t_sort_time);
    printf("-----------------------------------------------------------------\n");
    printf("Média de palavras/lista: %.2lf\n", information -> t_sort_words / information -> lists);
    printf("Média de comparações/lista: %.2lf\n", information -> t_sort_com / information -> lists);
    printf("Média de movimentações/lista: %.2lf\n", information -> t_sort_mov / information -> lists);
    printf("Média de tempo/lista: %lf\n", information -> t_sort_time / information -> lists);
    printf("-----------------------------------------------------------------\n");
}