/**
@file
bot.h
*/

#ifndef BOT_BOT_H
#define BOT_BOT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliares.h"

#define BUF_SIZE 1024

/**
\brief Função que permite que o jogador atual peça ao computador para jogar por si (peça possivel com menor distancia)
@param e Apontador para o estado
@returns O jogador, o número da jogada e o respetivo turno
*/
int comando_jog (ESTADO *e);

#endif //BOT_BOT_H
