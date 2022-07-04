#include <stdio.h>
#include "camada_dados.h"
#include "camada_interface.h"
#include "camada_logica.h"
#include <stdio.h>
#define BUF_SIZE 1024

int main(){
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}