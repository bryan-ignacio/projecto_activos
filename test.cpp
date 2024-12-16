//
// Created by Bryan Ignacio on 12/15/24.
//
#include <iostream>
#include "MatrizDispersa.h"

using namespace std;

int main() {
    MatrizDispersa *matriz = new MatrizDispersa();
    Usuario *u1 = new Usuario("Bryan", "user1", "Bryan Ignacio", "Guatemala", "IGGS");
    Node *n1 = new Node(u1);
    matriz->insertarValor(n1, n1->user->getDepartamento(), n1->user->getEmpresa());

    Usuario *u2 = new Usuario("Ignacio", "user2", "Bryan Ignacio", "Jutiapa", "IGGS");
    Node *n2 = new Node(u2);
    matriz->insertarValor(n2, n2->user->getDepartamento(), n2->user->getEmpresa());

    Usuario *u3 = new Usuario("Xoy", "user3", "Bryan Ignacio", "Guatemala", "Cinepolis");
    Node *n3 = new Node(u3);
    matriz->insertarValor(n3, n3->user->getDepartamento(), n3->user->getEmpresa());

    Usuario *u4 = new Usuario("Fernanda", "user4", "Bryan Ignacio", "Escuintla", "Max");
    Node *n4 = new Node(u4);
    matriz->insertarValor(n4, n4->user->getDepartamento(), n4->user->getEmpresa());

    matriz->reporte();

    return 0;
}