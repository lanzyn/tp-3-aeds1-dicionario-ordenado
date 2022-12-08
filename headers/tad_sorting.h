#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/tad_alt_dicio.h"


// Função de ordenação por Bubble Sort
void bubble_sort(new_dicionario *new_dicionario, int length, int num_letra);

// Função de ordenação por Selection Sort
void selection_sort(new_dicionario *new_dicionario, int length, int num_letra);

// Função de ordenação por Insertion Sort
void insertion_sort(new_dicionario *new_dicionario, int length, int num_letra);

// Função de ordenação por Shell Sort
void shell_sort(new_dicionario *new_dicionario, int length, int num_letra);

// // Função de ordenação por Quick Sort
// void sort(int left, int right, new_dicionario *new_dicionario);
// void partition(int left, int right, int *i, int *j, new_dicionario *new_dicionario);
// void quick_sort(new_dicionario *new_dicionario, int length);

// // Função de ordenação por Heap Sort
// void make(new_dicionario *new_dicionario, int length);
// void remake(int left, int right, new_dicionario *new_dicionario);
// void heap_sort(new_dicionario *new_dicionario, int length);