/**
@file
camada_logica.h
Definição do estado e das funções que o manipulam
*/

#ifndef LI2PL8G7_CAMADA_LOGICA_H
#define LI2PL8G7_CAMADA_LOGICA_H

#include "listas.h"

/**
\brief Função que recebe o estado e uma coordenada e muda o tipo da casa dessa coordenada para branca
@param e Apontador para o estado
@param c A coordenada
*/
void peca_branca(ESTADO *e, COORDENADA c);

/**
\brief Função que recebe o estado e uma coordenada e muda o tipo da casa dessa coordenada para preta
@param e Apontador para o estado
@param c A coordenada
*/
void peca_preta(ESTADO *e, COORDENADA c);

/**
\brief Função que recebe o estado do jogo e a coordenada para o qual o jogador pretende mover a peça branca e verifica se a coordenada para a qual pretende jogar é válida
@param e Apontador para o estado
@param c A coordenada
@returns Retorna 1 caso a posição para a qual o jogador quer jogar é valida e 0 caso contrário
*/
int posicao_valida(ESTADO *e, COORDENADA c);

/**
\brief Função que recebe o estado do jogo e retorna a coordenada da peça branca
@param e Apontador para o estado
@returns A coordenada da peça branca
*/
COORDENADA obter_coord_branca(ESTADO *e);

/**
\brief Função que recebe o estado e verifica se o jogador não tem mais hipóteses de jogadas retornando 1 caso se verifica
@param e Apontador para o estado
@returns Retorna 1 caso o jogador não tenha mais hipóteses de jogadas e 0 caso contrário
*/
int encurralada (ESTADO *e);

/**
\brief Função que recebe e o estado e retorna 1 caso o jogo tenha acabado e 0 caso ainda não tenha acabado
@param e Apontador para o estado
@returns Retorna 1 caso o jogo tenha acabado e 0 caso contrário
*/
int deteta_fim (ESTADO *e);

/**
\brief Função que verifica se a peça branca chega a uma das casas que ditam o fim do jogo, caso retorne 1, o jogador um ganhou o jogo, caso retorne 2 o jogador dois ganhou o jogo, caso retorne 0 o jogo ainda não acabou
@param e Apontador para o estado
@param c A coordenada
@returns Retorna 1 caso a peça branca se encontre na casa onde ganha o jogador 1, retorna 2 caso a peça branca se encontre na casa onde ganha o jogador 2 e 0 caso contrário
*/
int acabou(ESTADO *e, COORDENADA c);

/**
\brief Função que recebe o estado do jogo e a coordenada para o qual será movida a peça branca e coloca na coordenada anterior da peça branca uma peça preta e efetua a jogada que o jogador pretende
@param e Apontador para o estado
@param c A coordenada
@returns Uma peça preta na anterior coordenada da peça branca e nova posição da peça branca
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Função que lê tabuleiros que ja foram gravados caso o ficheiro exista
@param e Apontador para o estado
@param fich[] Nome do ficheiro inserido pelo utilizador no terminal
*/
int ler(ESTADO *e, char fich[]);

/**
\brief Função que calacula a distancia entre 2 coordenadas
*/
double dist (int x, int y, int z, int w);

/**
\brief Função que guarda uma jogada
@param e Apontador para o estado
@param c A coordenada
@param turno O turno do jogador
*/
void guarda_jogada(ESTADO *e, COORDENADA c, int turno);

/**
\brief Função que devolve uma lista com as jogadas possiveis
@param e Apontador para o estado
@param l Lista de jogadas possiveis
*/
LISTA jogadas_possiveis(ESTADO *e, LISTA l);

/**
\brief Função que tranforma 2 inteiros numa string
*/
char* to_string(int x, int y);

/**
\brief Função que tranforma uma string em coordenadas
*/
COORDENADA to_int(char v[]);

#endif//LI2PL8G7_CAMADA_LOGICA_H
