#include "auxiliares.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


LISTA criar_lista(){
    LISTA l;
    l = malloc (sizeof(Nodo));
    l->prox = NULL;
    return l;
}

LISTA insere_cabeca(LISTA L, void *v){
    LISTA l = criar_lista();
    l->valor = v;
    l->prox = L;
    return l;
}

void *devolve_cabeca(LISTA L){
    void *cabeca;
    if (L == NULL) cabeca = NULL;
    else cabeca = L->valor;
    return cabeca;
}

LISTA proximo(LISTA L){
    LISTA l;
    if (L == NULL) l = NULL; //corrigido
    else l = L->prox;
    return l;
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



double dist (int x, int y, int z, int w){
    double distancia = sqrt(pow(abs(x - z), 2) + pow(abs(y - w), 2));
    return distancia;
}

COORDENADA to_int(char v[]){
    int d = v[0]-48, d1 = v[1]-48;
    COORDENADA c;
    c.linha = d;
    c.coluna = d1;
    return c;
}


char* to_string(int x, int y){
    char *v=malloc((1));
    v[0]=x+48;
    v[1]=y+48;
    return v;
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

int num (ESTADO *e){
    int r = e->num_jogadas;
    return r;
}

ESTADO* ler(ESTADO *e, char fich[]){
    FILE *fp;
    char buff[BUFSIZ];
    char a;
    int j, i;
    fp=fopen(fich, "r");
    fseek(fp, 0, SEEK_SET);
    for(j=0; j<8; j++) {
        for (i=0; i<8; i++) {
            fscanf(fp, "%c " ,&a);
            if (a=='.') e->tab[j][i]=VAZIO;
            else if (a=='#') e->tab[j][i]=PRETA;
            else if (a=='*') e->tab[j][i]=BRANCA;
            else if (a=='2') e->tab[j][i]=JOG2;
            else if (a=='1') e->tab[j][i]=JOG1;
        }
    }
    mostrar_tabuleiro(e);
    while(fgets(buff, BUFSIZ, fp)) {
        printf("%s", buff);
    }
    printf("\n");
    fclose(fp);
    return e;
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
