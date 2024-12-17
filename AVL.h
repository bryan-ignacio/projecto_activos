//
// Created by Bryan Ignacio on 12/17/24.
//
#include <iostream>
#include "NodeAVL.h"

using namespace std;

class AVL {
private:
    void insert(NodeAVL *value, NodeAVL *&root);

    void eliminar(const string &idActivo, NodeAVL *&root);

    int heightMax(NodeAVL *node);

    int factEquilibration(NodeAVL *node);

    void rotationRigth(NodeAVL *&node);

    void rotationLeft(NodeAVL *&node);

    void rotationRightLeft(NodeAVL *&node);

    void rotationLeftRight(NodeAVL *&node);

    NodeAVL *masDerecha(NodeAVL *node);

    string print(NodeAVL *root, int &count);

public:
    NodeAVL *root;

    AVL();

    bool isHoja(NodeAVL *node);

    void insert(Activo *activo);

    void eliminar(const string &idActivo);

    string print();
};

AVL::AVL() {
    this->root = nullptr;
}

void AVL::insert(Activo *activo) {
    NodeAVL *node = new NodeAVL(activo);
    insert(node, this->root);
}

void AVL::insert(NodeAVL *value, NodeAVL *&root) {
    if (root == nullptr) {
        root = value;
        root->factorEq = factEquilibration(root);
        return;
    }

    // Comparamos por idActivo
    if (value->activo->getIdActivo() < root->activo->getIdActivo()) {
        insert(value, root->left);
    } else {
        insert(value, root->right);
    }

    root->factorEq = factEquilibration(root);
    if (root->factorEq < -1) {
        if (root->left->factorEq > 0) {
            rotationLeftRight(root);
            return;
        }
        rotationRigth(root);
        return;
    }

    if (root->factorEq > 1) {
        if (root->right->factorEq < 0) {
            rotationRightLeft(root);
            return;
        }
        rotationLeft(root);
        return;
    }
}

void AVL::eliminar(const string &idActivo) {
    eliminar(idActivo, this->root);
}

void AVL::eliminar(const string &idActivo, NodeAVL *&root) {
    if (root == nullptr) {
        cout << "El valor no existe con idActivo: " + idActivo << endl;
        return;
    }

    // Comparamos por idActivo
    if (idActivo == root->activo->getIdActivo()) {
        if (isHoja(root)) {
            root = nullptr;
            return;
        }

        if (root->left == nullptr) {
            root = root->right;
            return;
        }

        if (root->right == nullptr) {
            root = root->left;
            return;
        }

        NodeAVL *nodeDerecha = masDerecha(root->left);
        root->activo = nodeDerecha->activo;
        eliminar(nodeDerecha->activo->getIdActivo(), root->left);
    } else if (idActivo < root->activo->getIdActivo()) {
        eliminar(idActivo, root->left);
    } else {
        eliminar(idActivo, root->right);
    }

    root->factorEq = factEquilibration(root);

    if (root->factorEq < -1) {
        if (root->left->factorEq > 0) {
            rotationLeftRight(root);
            return;
        }
        rotationRigth(root);
        return;
    }
    if (root->factorEq > 1) {
        if (root->right->factorEq < 0) {
            rotationRightLeft(root);
            return;
        }
        rotationLeft(root);
        return;
    }
}

void AVL::rotationRigth(NodeAVL *&node) {
    NodeAVL *aux = node->left;
    node->left = aux->right;
    aux->right = node;
    node = aux;

    node->factorEq = factEquilibration(node);
    node->right->factorEq = factEquilibration(node->right);
    if (node->left == nullptr) return;
    node->left->factorEq = factEquilibration(node->left);
}

void AVL::rotationLeft(NodeAVL *&node) {
    NodeAVL *aux = node->right;
    node->right = aux->left;
    aux->left = node;
    node = aux;

    node->factorEq = factEquilibration(node);
    node->left->factorEq = factEquilibration(node->left);
    if (node->right == nullptr) return;
    node->right->factorEq = factEquilibration(node->right);
}

void AVL::rotationRightLeft(NodeAVL *&node) {
    rotationRigth(node->right);
    rotationLeft(node);
}

void AVL::rotationLeftRight(NodeAVL *&node) {
    rotationLeft(node->left);
    rotationRigth(node);
}

int AVL::heightMax(NodeAVL *node) {
    if (node == nullptr) return 0;
    int hLeft = heightMax(node->left);
    int hRight = heightMax(node->right);

    return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

NodeAVL *AVL::masDerecha(NodeAVL *node) {
    if (node->right == nullptr) return node;
    return masDerecha(node->right);
}

int AVL::factEquilibration(NodeAVL *node) {
    return heightMax(node->right) - heightMax(node->left);
}

bool AVL::isHoja(NodeAVL *node) {
    return node->left == nullptr && node->right == nullptr;
}

string AVL::print() {
    int count = -1;
    string dot = "digraph G {\n\tnode [shape=circle];\n\t";
    dot += print(this->root, count);
    dot += "\n}";
    return dot;
}

string AVL::print(NodeAVL *root, int &count) {
    if (root == nullptr) return "";

    count++;
    int currentCount = count;
    string dot = "n" + to_string(currentCount) + " [label=" + root->activo->getName() + "];\n\t";

    if (root->left != nullptr) {
        int nextNode = count + 1;
        dot += "n" + to_string(currentCount) + " -> n" + to_string(nextNode) + ";\n\t" + print(root->left, count);
    }

    if (root->right != nullptr) {
        int nextNode = count + 1;
        dot += "n" + to_string(currentCount) + " -> n" + to_string(nextNode) + ";\n\t" + print(root->right, count);
    }

    return dot;
}