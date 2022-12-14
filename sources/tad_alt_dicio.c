#include "../headers/tad_alt_dicio.h"

#define UPPER_A 65
#define UPPER_Z 90

#define LOWER_A 97
#define LOWER_Z 122

void incializa_vetor_palavras(tipo_vetor_palavras *vetor, int tamanho) {
    vetor -> vetor_palavras = (tipo_new_palavra*) malloc(tamanho * sizeof(tipo_new_palavra));
}

void inicializa_new_dicionario(new_dicionario *new_dicionario, tipo_dicionario *dicionario) {
    int i;
    int num_palavras;
    for (i = 0; i < 26; i++) {
        new_dicionario -> alfabeto[i].identificador_upper = 'A' + i;
        new_dicionario -> alfabeto[i].identificador_lower = 'a' + i;
        num_palavras = retorna_numero_palavras(&dicionario -> alfabeto[i].lista_palavras);
        incializa_vetor_palavras(&new_dicionario -> alfabeto[i].lista_palavras_vetor, num_palavras);
    }
}

void copia_lista_palavras(tipo_vetor_palavras *vetor, tipo_lista_palavras *lista_palavras) {
    int i; i = 0;
    apontador_lista_palavras aux_palavra; aux_palavra = lista_palavras -> primeiro_lista -> p_prox_lista;
    while (aux_palavra != NULL) {
        vetor -> vetor_palavras[i].caracteres = strdup(aux_palavra -> item_palavra.cadeia_caracteres);
        i++;
        aux_palavra = aux_palavra -> p_prox_lista;
    }
}

void constroi_new_dicionario(new_dicionario *new_dicionario, tipo_dicionario *dicionario) {
    inicializa_new_dicionario(new_dicionario, dicionario);
    int i;
    for (i = 0; i < 26; i++) {
        copia_lista_palavras(&new_dicionario -> alfabeto[i].lista_palavras_vetor, &dicionario -> alfabeto[i].lista_palavras);
    }
}

void imprime_new_dicionario_completo(new_dicionario *new_dicionario, tipo_dicionario *dicionario) {
    int i, j;
    int num_palavras;
    for (i = 0; i < 26; i++) {
        num_palavras = retorna_numero_palavras(&dicionario -> alfabeto[i].lista_palavras);
        printf("\n-----------------------------------------------------------------\n");
        printf("Letra |%c| :\n", dicionario -> alfabeto[i].identificador_upper);
        printf("\n");
        for (j = 0; j < num_palavras; j++) {
            printf("[%s]\n\n", new_dicionario -> alfabeto[i].lista_palavras_vetor.vetor_palavras[j].caracteres);
        }
        printf("-----------------------------------------------------------------\n");
        printf("\n\n");
    }
}

void imprime_new_dicionario_letra(new_dicionario *new_dicionario, tipo_dicionario *dicionario, char letra_alfabeto) {
    int i;
    int aux; aux = 0;
        if (letra_alfabeto >= LOWER_A && letra_alfabeto <= LOWER_Z) {
            aux = letra_alfabeto - LOWER_A;
        }
        else if (letra_alfabeto >= UPPER_A && letra_alfabeto <= UPPER_Z) {
            aux = letra_alfabeto - UPPER_A;
        }
        else {
            printf("O caractere informado não existe!\n");
            return;
        }
        printf("Letra |%c| :\n", letra_alfabeto);
        printf("\n");
        if (retorna_numero_palavras(&dicionario -> alfabeto[aux].lista_palavras) > 0) {
            for (i = 0; i < retorna_numero_palavras(&dicionario -> alfabeto[aux].lista_palavras); i++) {
                printf("[%s]\n\n", new_dicionario -> alfabeto[aux].lista_palavras_vetor.vetor_palavras[i].caracteres);
            }
        }
        else {
            printf("Não existem palavras com a letra informada!\n");
            return;
        }
}