/**
@file
camada_interface.h
Definição do estado e das funções que o manipulam
*/

#ifndef LI2PL8G7_CAMADA_INTERFACE_H
#define LI2PL8G7_CAMADA_INTERFACE_H

#include "camada_dados.h"
#include "listas.h"

/**
\brief  Função que recebe o estado do jogo e interpreta os comandos para efetuar a jogada que o jogador pretende
@param e Apontador para o estado
@returns Retorna 0 se o utilizador não introduziu uma das casas do tabuleiro e 1 caso o faça
*/
int interpretador(ESTADO *e);

/**
\brief Função que recebe o estado do jogo e imprime o tabuleiro
@param e Apontador para o estado
@returns O tabuleiro
*/
void mostrar_tabuleiro(ESTADO *e);

/**
\brief Função que imprime a coordenada
@param c Apontador para a Coordenada
@returns A coordenada
*/
int mostra_coordenada (COORDENADA c);

/**
\brief Função que imprime mensagem de jogada invalida assim como qual dos jogadores ganhou
@param e Apontador para o estado
@param c A coordenada
@returns Mensagem de jogo
*/
int mostra_resultado (ESTADO *e, COORDENADA c);

/**
\brief Função que recebe o estado do jogo e a coordenada para o qual será movida a peça branca e coloca na coordenada anterior da peça branca uma peça preta e efetua a jogada que o jogador pretende
@param e Apontador para o estado
@param c A coordenada
@returns Peça preta na coordenada anterior da branca
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Função que recebe e o estado e retorna 1 caso o jogo tenha acabado e 0 caso ainda não tenha acabado
@param e Apontador para o estado
@returns Retorna 1 caso o jogo tenha acabado e 0 caso contrário
*/
int deteta_fim(ESTADO *e);

/**
\brief Função que nos da o número de jogadas efetuadas
@param e Apontador para o estado
@returns Número de jogadas
*/
int num (ESTADO *e);

/**
\brief Função que imprime a lista de movimentos que é dada por tantas linhas como jogadas. Cada linha começa com o número da jogada (sempre com dois algarismos) seguinda dos movimentos de cada jogador
@param e Apontador para o estado
@param turno O turno no jogador
@returns Lista de movimentos
*/
int movs (ESTADO *e, int turno);

/**
\brief Função que recebe e o estado e grava o tabuleiro num ficheiro .txt
@param e Apontador para o estado
@param fich[] Nome do ficheiro inserido pelo utilizador no terminal
@param turno O turno do jogador
*/
int gravar(ESTADO *e, char fich[], int turno);

/**
\brief O comando pos permite ao utilizador aceder a uma jogada anterior
@param e Apontador para o estado
@param x Número da jogada
@returns Jogada anterior
*/
int pos (ESTADO *e, int x);

/**
\brief Função que nos da o número de peças pretas
@param e Apontador para o estado
@return O número de peças pretas
 */
int conta_pretas(ESTADO *e);

/**
\brief Função que permite que o jogador atual peça ao computador para jogar por si (peça possivel com menor distancia)
@param e Apontador para o estado
@param turno O turno do jogador
@param l Lista de jogadas possiveis
*/
void comando_jog(LISTA l,ESTADO *e, int turno);

/**
\brief Função que permite que o jogador atual peça ao computador para jogar por si (peça possivel aleatoria)
@param e Apontador para o estado
@param turno O turno do jogador
@param l Lista de jogadas possiveis
*/
void comando_jog2 (LISTA l, ESTADO *e, int turno);


#endif//LI2PL8G7_CAMADA_INTERFACE_H
