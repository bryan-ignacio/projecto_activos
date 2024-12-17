#include "Activo.h"

class NodeAVL {
public:
    Activo* activo;    // En lugar de un entero, tenemos un puntero a un objeto Activo
    int factorEq;
    NodeAVL* left;
    NodeAVL* right;

    NodeAVL(Activo* activo);
};

NodeAVL::NodeAVL(Activo* activo) {
    this->activo = activo;
    this->factorEq = 0;
    this->left = nullptr;
    this->right = nullptr;
}