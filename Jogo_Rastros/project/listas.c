#include <stdlib.h>
#include <stdio.h>
#include "listas.h"

// Cria uma lista vazia
LISTA criar_lista(){
    LISTA l;
    l = malloc (sizeof(Nodo));
    l->prox= NULL;
    return l;
}
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *v){
    LISTA l = criar_lista();
    l->valor = v;
    l->prox = L;
    return l;
}
// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L){
    void *cabeca;
    if (L == NULL) cabeca = NULL;
    else cabeca = L->valor;
    return cabeca;
}
// Devolve a cauda da lista
LISTA proximo(LISTA L){
    LISTA l;
    if (L == NULL) l = NULL; //corrigido
    else l = L->prox;
    return l;
}
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L){
    LISTA l;
    l = L;
    L = proximo(L);
    free(l);
    return L;
}
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L){
    int v = 0;
    if (L == NULL) v = 1;
    return v;
}
void print_lista(LISTA L){
    while (L!=NULL)
    {
        char *str = (char *) devolve_cabeca(L);
        printf("%s\n", str);
        L = L->prox;
    }
}

int length_lista (LISTA l){
    int conta = 0;
    while(l != NULL){
         conta++;
         l = l->prox;
    }
    return conta;
}