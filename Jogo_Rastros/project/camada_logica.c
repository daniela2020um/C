#include "camada_dados.h"
#include "camada_logica.h"
#include "camada_interface.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void peca_branca(ESTADO *e, COORDENADA c){
        e->tab[c.linha][c.coluna]=BRANCA;
}

void peca_preta(ESTADO *e, COORDENADA c){
    e->tab[c.linha][c.coluna]=PRETA;
}

double dist (int x, int y, int z, int w){
    double distancia = sqrt(pow(abs(x - z), 2) + pow(abs(y - w), 2));
    return distancia;
}

int posicao_valida(ESTADO *e, COORDENADA c){
    COORDENADA d;
    d= obter_coord_branca(e);
    double distancia = dist(c.linha,c.coluna,d.linha,d.coluna);
    if ((e->tab[c.linha][c.coluna]==VAZIO || e->tab[c.linha][c.coluna]==JOG1 || e->tab[c.linha][c.coluna]==JOG2) && (distancia==1 || distancia==sqrt(2))) return 1;
    else return 0;
}

COORDENADA obter_coord_branca(ESTADO *e){
    int i, j;
    COORDENADA coord;
    for (j=0; j<8; j++){
        for (i=0; i<8; i++)
        {
            if (e->tab[j][i]==BRANCA){
                coord.coluna=i;
                coord.linha=j;
            }
        }
    }
    return coord;
}

int encurralada (ESTADO *e){
    LISTA L = NULL;
    LISTA l = jogadas_possiveis(e,L);
    if (l == NULL) return 1;
    else return 0;
}


int deteta_fim (ESTADO *e){
    int fim=0;
    if (e->tab[0][7]==BRANCA || e->tab[7][0]==BRANCA || encurralada(e)==1) fim=1;
    return fim;
}

int acabou(ESTADO *e, COORDENADA c){
    if (e -> tab[c.linha][c.coluna] == e -> tab[0][7]) return 2;
    else if (e -> tab[c.linha][c.coluna] == e -> tab[7][0]) return 1;
    else return 0;
}

int jogar(ESTADO *e, COORDENADA c) {
    COORDENADA d;
    int r = 0;
    d= obter_coord_branca(e);
    if (posicao_valida(e,c)){
        mostra_coordenada(c);
        peca_branca(e, c);
        peca_preta(e, d);
        if ( encurralada(e) == 1 && e -> jogador_atual == 2) r = 1; 
        else if ( encurralada(e) == 1 && e -> jogador_atual == 1) r = 2; 
        else if (acabou(e,c) == 2) r = 1; 
        else if (acabou(e,c) == 1) r = 2; 
    }
    else if (e->tab[c.linha][c.coluna]==PRETA || !posicao_valida(e,c)) r = 3; 
    return r;
}

int ler(ESTADO *e, char fich[]){
    FILE *fp;
    char buff[BUF_SIZE];
    char a;
    int j, i;
    fp=fopen(fich, "r");
    fseek(fp, 0, SEEK_SET); 
    for(j=0; j<8; j++) {
        for (i=0; i<8; i++) {
            if (fscanf(fp, "%c " ,&a) == 1) {
                if (a == '.') e->tab[j][i] = VAZIO;
                else if (a == '#') e->tab[j][i] = PRETA;
                else if (a == '*') e->tab[j][i] = BRANCA;
                else if (a == '2') e->tab[j][i] = JOG2;
                else if (a == '1') e->tab[j][i] = JOG1;
            }
        }
    }
    mostrar_tabuleiro(e);
    while(fgets(buff, BUF_SIZE, fp)) {
        printf("%s", buff);
    }
    printf("\n");
    fclose(fp);
    return 0;
}

void guarda_jogada(ESTADO *e, COORDENADA c, int turno){
    int jog = e->jogador_atual;
    if (jog==1) e->jogadas[turno-1].jogador1=c;
    else  e->jogadas[turno-1].jogador2=c;
}

char* to_string(int x, int y){
    char *v=malloc(sizeof(1));
    v[0]=x+48;
    v[1]=y+48;
    return v;
}

COORDENADA to_int(char v[]){
    int d = v[0]-48, d1 = v[1]-48;
    COORDENADA c;
    c.linha = d;
    c.coluna = d1;
    return c;
}

LISTA jogadas_possiveis(ESTADO *e, LISTA l) {
    COORDENADA u;
    u = obter_coord_branca(e);
    int i, j;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            double distancia  = dist(j, i, u.linha, u.coluna) ;
            if ((distancia == 1 || distancia == sqrt(2)) && (e->tab[j][i] == VAZIO || e->tab[j][i] == JOG1 || e->tab[j][i] == JOG2)) {
                char* t= to_string(j, i);
                l = insere_cabeca(l, t);
            }
        }
    }
    return l;
}
