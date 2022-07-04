#include <stdio.h>
#include "bot.h"
#include "auxiliares.h"


int main (int argc, char *argv[]) {
    if (argc == 3) {
        char* tabi = argv[1];
        char* tabf = argv[2];
        ESTADO *e = inicializar_estado();
        e = ler(e, tabi);
       // mostrar_tabuleiro(e);
        //movs(e);
        int pretas = num(e), turno;
        if (pretas%2==0)
        {
             turno = (pretas/2)-1;
        }
        else
        {
             turno = ((pretas-1)/2)-1;
        }
        comando_jog(e); // bot(e);
        gravar(e, tabf, turno); 
        return 0;
    }
}
