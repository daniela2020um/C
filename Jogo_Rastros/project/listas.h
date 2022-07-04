#ifndef LISTAS_LISTAS_H
#define LISTAS_LISTAS_H

#include "camada_dados.h"


/**
\brief Tipo de dados para as listas ligadas
*/
typedef struct nodo *LISTA;
typedef struct nodo {
    void *valor;
    LISTA prox;
} Nodo;

/**
\brief Função que cria uma lista vazia
@returns Lista vazia
*/
LISTA criar_lista();

/**
\brief Função que insere um valor na cabeça da lista
@returns Nova lista
*/
LISTA insere_cabeca(LISTA L, void *valor);

/**
\brief Função que devolve a cabeça da lista
@returns Lista vazia
*/
void *devolve_cabeca(LISTA L);

/**
\brief Função que devolve a cauda da lista
*/
LISTA proximo(LISTA L);

/**
\brief Função que remove a cabeça da lista (libertando o espaço ocupado)
@returns Cauda da lista
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Função que devolve verdareiro se a lista é vazia
*/
int lista_esta_vazia(LISTA L);

/**
\brief Função que devolve o comprimento de uma lista
*/
int length_lista (LISTA l);

#endif //LISTAS_LISTAS_H
