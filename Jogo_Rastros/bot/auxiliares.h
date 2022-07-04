/**
@file
auxiliares.h
*/

#ifndef BOT_AUXILIARES_H
#define BOT_AUXILIARES_H


typedef enum {
            VAZIO,
            BRANCA,
            PRETA,
            JOG1,
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
\brief Função que lê um ficheiro com um tabuleiro previamnete gravado
@param e Apontador para o estado
@param fich[] Nome do ficheiro inserido pelo utilizador no terminal
*/
ESTADO* ler(ESTADO *e, char fich[]);

/**
\brief Função que calacula a distancia entre 2 coordenadas
*/
double dist (int x, int y, int z, int w);

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

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica a peça branca ser colocada na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();

/**
\brief Função que recebe e o estado e grava o tabuleiro num ficheiro .txt
@param e Apontador para o estado
@param fich[] Nome do ficheiro inserido pelo utilizador no terminal
@param turno O turno do jogador
*/
int gravar(ESTADO *e, char fich[], int turno);

/**
\brief Função que recebe o estado do jogo e imprime o tabuleiro
@param e Apontador para o estado
@returns O tabuleiro
*/
void mostrar_tabuleiro(ESTADO *e);

int num (ESTADO *e);

#endif //BOT_AUXILIARES_H
