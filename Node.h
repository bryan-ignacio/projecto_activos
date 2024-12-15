//
// Created by Bryan Ignacio on 12/15/24.
//
#include <iostream>

class Node {
public:
    int valor;
    Node *sig;
    Node *prev;
    Node *arriba;
    Node *abajo;
    Node *adelante;
    Node *atras;

    Node(int valor);
};

Node::Node(int value) {
    this->valor = value;
    this->prev = nullptr;
    this->sig = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}
