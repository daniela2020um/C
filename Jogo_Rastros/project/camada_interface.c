#include "camada_dados.h"
#include "camada_interface.h"
#include "camada_logica.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void mostrar_tabuleiro(ESTADO *e){
    int i, j, c=8;
    for (j=0; j<8; j++){
    printf ("%d  ", c);
    c--;
    for (i = 0; i<8; i++)
    {   
        if (e->tab[j][i]==PRETA) printf ("# ");
        else if (e->tab[j][i]==VAZIO) printf (". ");
        else if (e->tab[j][i]==BRANCA) printf ("* ");
        else if (e->tab[j][i]==JOG1) printf ("1 ");
        else if (e->tab[j][i]==JOG2) printf ("2 ");
    }
    printf ("\n");
    }
    printf ("   a b c d e f g h\n\n");
}

void tab_inicial(ESTADO *e){
    for (int j=0; j<8; j++){
    for (int i = 0; i<8; i++)
    { 
        if (j==3 && i==4) e->tab[j][i]=BRANCA;
        else if (j==7 && i==0) e->tab[j][i]=JOG1;
        else if (j==0 && i==7) e->tab[j][i]=JOG2;
        else e->tab[j][i]=VAZIO;
    }
}
}

int mostra_coordenada (COORDENADA c){
    printf ("jogar %d %d\n", c.coluna, c.linha);
    return 0;
}

int mostra_resultado (ESTADO *e, COORDENADA c){
    int r = jogar(e, c);
    if (r == 1) printf ("Parabéns jogador 1, venceu!\n");
    else if (r == 2) printf ("Parabéns jogador 2, venceu!\n");
    else if (r == 3) printf ("Coordenada inválida\n");
    return 0;
} 

int num (ESTADO *e){
    int r = e->num_jogadas;
    return r;
}

int movs (ESTADO *e, int turno) {
    char c1, c2;
    int l1, l2, conta=num(e);
    for (int i = 0, n=0; i < turno && n<conta; i++, n+=2) {
        c1 = e->jogadas[i].jogador1.coluna + 'a';
        l1 = -(e->jogadas[i].jogador1.linha) + 8;
        c2 = e->jogadas[i].jogador2.coluna + 'a';
        l2 = -(e->jogadas[i].jogador2.linha) + 8;
        if (i==turno-1 && conta%2!=0) printf("%d : %c%d\n", i+1, c1, l1);
        else printf("%d : %c%d %c%d\n", i+1, c1, l1, c2, l2);
    }
    return 0;
}

int conta_pretas(ESTADO *e){
    int conta=0, i, j;
    for (i=0; i<8; i++){
        for (j=0; j<8; j++){
            if (e->tab[i][j]==PRETA) conta++;
        }
    }
return conta;   
}

int pos (ESTADO *e, int x){
    int conta = num(e), rconta=conta;
    int z, y, z1, y1, n, gry=0, gry1=0, pr=conta_pretas(e), bl=x*2;
    if (conta%2!=0) rconta+=1;
    if (x==0){
        tab_inicial(e);
    }
    else{
    if (pr==0 || pr<bl){
        e->tab[3][4]=PRETA;
        for (n=0; n<x; n++){ 
        z=e->jogadas[n].jogador1.coluna;
        z1=e->jogadas[n].jogador1.linha;
        y=e->jogadas[n].jogador2.coluna;
        y1=e->jogadas[n].jogador2.linha;
        e->tab[z1][z]=PRETA;
        e->tab[y1][y]=PRETA;
        if (n==x-1){
            gry=y;
            gry1=y1;
            e->tab[gry1][gry]=BRANCA;
        }
        }
    }    
    else if (pr>bl){
    for (n=0; n<rconta/2; n++){ 
        z=e->jogadas[n].jogador1.coluna;
        z1=e->jogadas[n].jogador1.linha;
        y=e->jogadas[n].jogador2.coluna;
        y1=e->jogadas[n].jogador2.linha;
        if (n==x-1){
            gry=y;
            gry1=y1;
        }
        if (n==(rconta/2)-1 && conta%2!=0 ) e->tab[z1][z]=VAZIO;
        else if (n>x-1)
        {
            e->tab[z1][z]=VAZIO;
            e->tab[y1][y]=VAZIO;
        }
    }
    e->tab[gry1][gry]=BRANCA;
    printf("\n");
    } 
    }
    return 0;
}

int gravar(ESTADO *e, char fich[], int turno){ 
    FILE *fp;
    fp=fopen(fich, "w+");
    for (int j=0; j<8; j++){
        for (int i=0; i<8; i++){
            if (e->tab[j][i]==BRANCA) fprintf (fp, "*");
            else if (e->tab[j][i]==PRETA) fprintf (fp, "#");
            else if (e->tab[j][i]==VAZIO) fprintf (fp, ".");
            else if (e->tab[j][i]==JOG1)fprintf (fp, "1");
            else if (e->tab[j][i]==JOG2) fprintf (fp, "2");
        }
        fprintf (fp, "\n");
    }
    fprintf(fp, "\n");
    char c1, c2;
    int l1, l2, conta=num(e);
    for (int i = 0, n=0; i < turno && n<conta; i++, n+=2) {
        c1 = e->jogadas[i].jogador1.coluna + 'a';
        l1 = -(e->jogadas[i].jogador1.linha) + 8;
        c2 = e->jogadas[i].jogador2.coluna + 'a';
        l2 = -(e->jogadas[i].jogador2.linha) + 8;
        if (i==turno-1 && conta%2!=0) fprintf(fp,"%d : %c%d\n", i+1, c1, l1);
        else fprintf(fp,"%d : %c%d %c%d\n", i+1, c1, l1, c2, l2);
    }
    fclose(fp);
    return 0;
}

void comando_jog2 (LISTA l, ESTADO *e, int turno){
    double min = 100, distancia;
    COORDENADA u = obter_coord_branca(e), move, nova;
    while (l != NULL) {
        if (e->jogador_atual == 1) {
            char *coord = devolve_cabeca(l);
            move = to_int(coord);
            distancia = dist(move.linha, move.coluna,0,7);
            if (distancia == 0) {
                printf ("Parabéns jogador 1, venceu!\n");
                //e->tab[0][7] = BRANCA;
            }
            if (distancia < min) {
                min = distancia;
                nova.linha = move.linha;
                nova.coluna = move.coluna;
                l = proximo(l);
            }
            else l = proximo(l);
        }
        else if (e->jogador_atual == 2) {
            char *coord = devolve_cabeca(l);
            move = to_int(coord);
            distancia = dist(move.linha, move.coluna,7,0);
            if (distancia == 0) {
                printf ("Parabéns jogador 2, venceu!\n");
            //    e->tab[0][7] = BRANCA;
            }
            if (distancia < min) {
                min = distancia;
                nova.linha = move.linha;
                nova.coluna = move.coluna;
                l = proximo(l);
            }
            else l = proximo(l);
        }
    }
    e->tab[u.linha][u.coluna] = PRETA;
    e->tab[nova.linha][nova.coluna] = BRANCA;
    guarda_jogada(e, nova, turno);
}

void comando_jog (LISTA l, ESTADO *e, int turno) {
    COORDENADA u = obter_coord_branca(e), nova;
    char *coord;
    int x,i = 0;
    srand(time(NULL));
    x = rand() % length_lista(l);
    while (i != x){
       i++;
       l = proximo(l);
    }
    coord = devolve_cabeca(l);
    nova = to_int(coord);
    e->tab[u.linha][u.coluna] = PRETA;
    if (e->tab[nova.linha][nova.coluna] == JOG1) {
        printf("Parabéns jogador 2, venceu!\n");
        e->tab[7][0] = BRANCA;
    }
    else if (e->tab[nova.linha][nova.coluna] == JOG2) {
        printf ("Parabéns jogador 1, venceu!\n");
        e->tab[0][7] = BRANCA;
    }
    else {
        e->tab[nova.linha][nova.coluna] = BRANCA;
        guarda_jogada(e, nova, turno);
    }
}

int interpretador(ESTADO *e) {
        char linha[BUF_SIZE];
        char col[2], lin[2], cont=0, a[2], b[2], c[2], d[2], filename[BUF_SIZE];
        int jog, quit=0, turno=1, x;
        e->num_jogadas=0;
        while (!deteta_fim(e) && quit!=1){
        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;

        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            jog = e->jogador_atual;
            if (posicao_valida(e,coord)){
                printf ("# %d PL%d (%d)> ", e->num_jogadas+1, jog, turno);
                guarda_jogada(e, coord, turno);
                e->num_jogadas+=1;
                if (jog==1) e->jogador_atual=2;
                else e->jogador_atual=1;
                if (turno>0 && cont<1) cont++;
                else{
                    turno++;
                    cont=0;
                }
            } 
            else printf ("# %d PL%d (%d)> ", e->num_jogadas, jog, turno);
            mostra_resultado (e,coord);
            jogar(e, coord);
            mostrar_tabuleiro(e);
        }
        else if(sscanf(linha, "%[q]", a) == 1) {
            quit++;
        }
        else if(sscanf(linha, "ler %s", filename) == 1){
            ler(e, filename);
        }
        else if(sscanf(linha, "gr %s", filename) == 1){
            gravar(e, filename, turno);
        }
         else if(sscanf(linha, "%[m]%[o]%[v]%[s]", a, b, c, d) == 4){
            movs(e, turno);
         }
         else if(sscanf(linha, "pos %d", &x) == 1){
            if (x<=turno){
            pos(e, x);
            mostrar_tabuleiro (e);
            }
            else printf ("Comando inválido! Use como argumento um inteiro de 0 até %d", turno-1);
        }  
        else if (strcmp(linha, "jog2\n")==0){
            LISTA l = NULL;
            l = jogadas_possiveis(e, l);
            int jog = e->jogador_atual;
            printf("# %d PL%d (%d)\n", e->num_jogadas + 1, jog, turno);
            comando_jog2(l, e, turno);
            if (encurralada(e)) {
                if (e->jogador_atual == 1) printf("Parabéns jogador 1, venceu!\n");
                else printf("Parabéns jogador 2, venceu!\n");
            }
            mostrar_tabuleiro(e);
            e->num_jogadas += 1;
            if (jog == 1) e->jogador_atual = 2;
            else e->jogador_atual = 1;
            if (turno > 0 && cont < 1) cont++;
            else {
                turno++;
                cont = 0;
            }   
        } 
        else if(sscanf(linha, "%[j]%[o]%[g]", a, b, c) == 3){
            LISTA l = NULL;
            l = jogadas_possiveis(e, l);
            int jog = e->jogador_atual;
            printf("# %d PL%d (%d)\n", e->num_jogadas + 1, jog, turno);
            comando_jog(l, e, turno);
            if (encurralada(e)) {
                if (e->jogador_atual == 1) printf("Parabéns jogador 1, venceu!\n");
                else printf("Parabéns jogador 2, venceu!\n");
            }
            mostrar_tabuleiro(e);
            e->num_jogadas += 1;
            if (jog == 1) e->jogador_atual = 2;
            else e->jogador_atual = 1;
            if (turno > 0 && cont < 1) cont++;
            else {
                turno++;
                cont = 0;
            }
        }
      }
    return 1;
}
