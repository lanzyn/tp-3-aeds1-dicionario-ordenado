#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que armazena informações de ordenação
typedef struct {
    int sort_com;
    int sort_mov;
    double sort_time_cpu;
    double sort_time_time;
    int files;
    int words;

    int total_sort_com;
    int total_sort_mov;
    double total_sort_time_cpu;
    double total_sort_time_time;
    int total_files;
    int total_words;

    double md_sort_com;
    double md_sort_mov;
    double md_sort_time_cpu;
    double md_sort_time_time;
} sorting_informations;

void show_sorting_informations(sorting_informations *information);
void clear_all_informations(sorting_informations *information);
void clear_informations(sorting_informations *information);