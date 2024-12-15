#include <iostream>
#include "MatrizDispersa.h"
using namespace std;

int main(){
    MatrizDispersa *matriz = new MatrizDispersa();
    matriz->insertarValor(5, 0, 0);
    matriz->insertarValor(8, 1, 0);
    matriz->insertarValor(10, 2, 1);
    matriz->insertarValor(15, 1, 1);
    matriz->reporte();
    return 0;
}