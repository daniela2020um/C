#include "bot.h"
#include "auxiliares.h"
#include <math.h>
#include <stdlib.h>

int comando_jog (ESTADO *e){
    LISTA L = NULL;
    LISTA l = jogadas_possiveis(e,L);
    double min = 100, distancia;
    int r = 0, jog, cont, turno = 0;
    COORDENADA u = obter_coord_branca(e), move, nova;
    jog = e->jogador_atual;
        while (l != NULL) {
            if (e->jogador_atual == 1) {
                char *coord = devolve_cabeca(l);
                move = to_int(coord);
                distancia = dist(move.linha, move.coluna, 0, 7);
                if (distancia == 0) {
                    r = 1;
                }
                if (distancia < min) {
                    min = distancia;
                    nova.linha = move.linha;
                    nova.coluna = move.coluna;
                    l = proximo(l);
                } else l = proximo(l);
            } else if (e->jogador_atual == 2) {
                char *coord = devolve_cabeca(l);
                move = to_int(coord);
                distancia = dist(move.linha, move.coluna, 7, 0);
                if (distancia == 0) {
                    r = 2;
                }
                if (distancia < min) {
                    min = distancia;
                    nova.linha = move.linha;
                    nova.coluna = move.coluna;
                    l = proximo(l);
                } else l = proximo(l);
            }
        }

        e->tab[u.linha][u.coluna] = PRETA;
        e->tab[nova.linha][nova.coluna] = BRANCA;
        printf("# %d PL%d (%d)\n ", e->num_jogadas + 1, jog, turno);
        mostrar_tabuleiro(e);
        //resultado_jog(e,l,turno);
        e->num_jogadas += 1;
        if (jog == 1) e->jogador_atual = 2;
        else e->jogador_atual = 1;
        if (turno > 0 && cont < 1) cont++;
        else {
            turno++;
            cont = 0;
        }
    return r;
}
