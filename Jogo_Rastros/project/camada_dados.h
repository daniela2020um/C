/**
@file
camada_dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef LI2PL8G7_CAMADA_DE_DADOS_H
#define LI2PL8G7_CAMADA_DE_DADOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

/**
\brief Tipo de dados para a casa
*/
typedef enum {
    /** (.) no tabuleiro */
    VAZIO,
    /** (*) no tabuleiro */
    BRANCA,
    /** (#) no tabuleiro */
    PRETA,
    /** (1) no tabuleiro */
    JOG1,
    /** (2) no tabuleiro */
    JOG2,
} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
\brief Tipo de dados para a jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para estado
*/
typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** As jogadas */
    JOGADAS jogadas;
    /** O número das jogadas, usado no prompt */
    int num_jogadas;
    /** O jogador atual */
    int jogador_atual;
} ESTADO;

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica a peça branca ser colocada na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();

#endif //LI2PL8G7_CAMADA_DE_DADOS_H
