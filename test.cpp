//
// Created by Bryan Ignacio on 12/15/24.
//
#include <iostream>
#include "MatrizDispersa.h"
#include "Activo.h"

using namespace std;

int main() {
    Activo *a1 = new Activo("Activo1", "descrp a1");
    Activo *a2 = new Activo("Activo2", "descrp a2");
    Activo *a3 = new Activo("Activo3", "descrp a3");
    Activo *a4 = new Activo("Activo4", "descrp a4");
    Activo *a5 = new Activo("Activo5", "descrp a5");
    cout << a1->toString() << endl;
    cout << a2->toString() << endl;
    cout << a3->toString() << endl;
    cout << a4->toString() << endl;
    cout << a5->toString() << endl;

//    MatrizDispersa *matriz = new MatrizDispersa();
//    Usuario *u1 = new Usuario("Bryan", "user1", "Bryan Ignacio", "Guatemala", "IGGS");
//    Node *n1 = new Node(u1);
//    matriz->insertarValor(n1, n1->user->getDepartamento(), n1->user->getEmpresa());
//
//    Usuario *u2 = new Usuario("Ignacio", "user2", "Bryan Ignacio", "Jutiapa", "IGGS");
//    Node *n2 = new Node(u2);
//    matriz->insertarValor(n2, n2->user->getDepartamento(), n2->user->getEmpresa());
//
//    Usuario *u3 = new Usuario("Xoy", "user3", "Bryan Ignacio", "Guatemala", "Cinepolis");
//    Node *n3 = new Node(u3);
//    matriz->insertarValor(n3, n3->user->getDepartamento(), n3->user->getEmpresa());
//
//    Usuario *u4 = new Usuario("Fernanda", "user4", "Bryan Ignacio", "Escuintla", "Max");
//    Node *n4 = new Node(u4);
//    matriz->insertarValor(n4, n4->user->getDepartamento(), n4->user->getEmpresa());
//
//    matriz->reporte();
//
//    if(matriz->buscarUsuarioPorUsername("Hola") != nullptr){
//        cout << "Nodo encontrado" << endl;
//    }else{
//        cout << "Nodo no encontrado" << endl;
//    }


    return 0;
}