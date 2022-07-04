#include "camada_dados.h"
#include "camada_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    for (int j=0; j<8; j++){
    for (int i = 0; i<8; i++)
    { 
        if (j==3 && i==4) e->tab[j][i]=BRANCA;
        else if (j==7 && i==0) e->tab[j][i]=JOG1;
        else if (j==0 && i==7) e->tab[j][i]=JOG2;
        else e->tab[j][i]=VAZIO;
    }
    }
    mostrar_tabuleiro (e);
    return e;
}