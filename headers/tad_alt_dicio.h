#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tad_dicionario.h"

// Delclarando um tipo palavra
typedef struct {
    char *caracteres;
} tipo_new_palavra;

// Declarando um tipo lista de palavras
typedef struct {
    tipo_new_palavra *vetor_palavras;
} tipo_vetor_palavras;

// Declarando um tipo para o dicionário
typedef struct {    
    char identificador_upper;
    char identificador_lower;
    tipo_vetor_palavras lista_palavras_vetor;
} tipo_new_dicionario;

// Declarando o dicionário
typedef struct {
    tipo_new_dicionario alfabeto[26];
} new_dicionario;

// Função que inicializa um a palavra e a lista de palavras com vetores
void incializa_vetor_palavras(tipo_vetor_palavras *vetor, int tamanho);

// Função para inicializar o novo dicionário vazio
void inicializa_new_dicionario(new_dicionario *new_dicionario, tipo_dicionario *dicionario);

// Função que copia os itens de uma lista encadeada de palavras para o dicionário de cada letra
void copia_lista_palavras(tipo_vetor_palavras *vetor, tipo_lista_palavras *lista_palavras);

// Função para construir o novo dicionário a partir do um já existente
void constroi_new_dicionario(new_dicionario *new_dicionario, tipo_dicionario *dicionario);

// Função para imprimir todo o novo dicionário
void imprime_new_dicionario_completo(new_dicionario *new_dicionario, tipo_dicionario *dicionario);

// Função para imprimir uma letra específica do novo dicionário
void imprime_new_dicionario_letra(new_dicionario *new_dicionario, tipo_dicionario *dicionario, char letra_alfabeto);