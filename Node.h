//
// Created by Bryan Ignacio on 12/15/24.
//
#include <iostream>
#include "Usuario.h"

class Node {
public:
    Usuario *user;
    Node *sig;
    Node *prev;
    Node *arriba;
    Node *abajo;
    Node *adelante;
    Node *atras;
    Node(Usuario *user);
};

Node::Node(Usuario *user) {
    this->user = user;
    this->prev = nullptr;
    this->sig = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}
