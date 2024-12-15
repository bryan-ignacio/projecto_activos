#include <iostream>
#include <fstream>
#include <cstdlib> // Para usar system()
#include "Node.h"

using namespace std;

class MatrizDispersa {
public:
    Node *cabeH;
    Node *cabeV;

    MatrizDispersa();

    bool estaVacia();

    Node *cabeceraHorizontal(int valor);

    Node *cabeceraVertical(int valor);

    Node *insertarCabeceraH(int valor);

    Node *insertarCabeceraV(int valor);

    void insertarAlFinal(Node *valor, Node *cabeH, Node *cabeV);

    void insertarAlFinalH(Node *valor, Node *cabeH);

    void insertarAlFinalV(Node *valor, Node *cabeV);

    void insertarAlMedioH(Node *valor, Node *horizontal);

    void insertarAlMedioV(Node *valor, Node *vertical);

    void insertarValor(int valor, int cabH, int cabV);

    Node *enCabeceraH(Node *node);

    Node *enCabeceraV(Node *node);

    bool masDerecha(Node *cabeH, int cabH);

    bool masAbajo(Node *cabeV, int cabV);

    void reporte();
};

MatrizDispersa::MatrizDispersa() {
    this->cabeH = nullptr;
    this->cabeV = nullptr;
}

bool MatrizDispersa::estaVacia() {
    return this->cabeH == nullptr;
}

Node *MatrizDispersa::enCabeceraH(Node *node) {
    Node *aux = node;
    while (aux->arriba != nullptr) {
        aux = aux->arriba;
    }
    return aux;
}

Node *MatrizDispersa::enCabeceraV(Node *node) {
    Node *aux = node;
    while (aux->prev != nullptr) {
        aux = aux->prev;
    }
    return aux;
}


bool MatrizDispersa::masDerecha(Node *cabeH, int cabH) {
    Node *aux = cabeH;
    while (aux != nullptr) {
        if (aux->valor == cabH) return true;
        aux = aux->sig;
    }
    return false;
}

bool MatrizDispersa::masAbajo(Node *cabeV, int cabV) {
    Node *aux = cabeV;
    while (aux != nullptr) {
        if (aux->valor == cabV) return true;
        aux = aux->abajo;
    }
    return false;
}

Node *MatrizDispersa::insertarCabeceraH(int valor) {
    Node *nuevaCabecera = new Node(valor);
    if (this->cabeH == nullptr) {
        this->cabeH = nuevaCabecera;
        return nuevaCabecera;
    }

    Node *aux = this->cabeH;
    while (aux->sig != nullptr) {
        aux = aux->sig;
    }

    aux->sig = nuevaCabecera;
    nuevaCabecera->prev = aux;
    return nuevaCabecera;
}

Node *MatrizDispersa::insertarCabeceraV(int valor) {
    Node *nuevaCabecera = new Node(valor);
    if (this->cabeV == nullptr) {
        this->cabeV = nuevaCabecera;
        return nuevaCabecera;
    }

    Node *aux = this->cabeV;
    while (aux->abajo != nullptr) {
        aux = aux->abajo;
    }

    aux->abajo = nuevaCabecera;
    nuevaCabecera->arriba = aux;
    return nuevaCabecera;
}

Node *MatrizDispersa::cabeceraHorizontal(int valor) {
    if (estaVacia()) {
        return nullptr;
    }
    Node *aux = this->cabeH;
    while (aux != nullptr) {
        if (aux->valor == valor) return aux;
        aux = aux->sig;
    }
    return nullptr;
}

Node *MatrizDispersa::cabeceraVertical(int valor) {
    if (estaVacia()) {
        return nullptr;
    }
    Node *aux = this->cabeV;
    while (aux != nullptr) {
        if (aux->valor == valor) return aux;
        aux = aux->abajo;
    }
    return nullptr;
}


void MatrizDispersa::insertarAlFinalH(Node *valor, Node *cabeH) {
    Node *aux = cabeH;
    while (aux->abajo != nullptr) {
        aux = aux->abajo;
    }
    aux->abajo = valor;
    valor->arriba = aux;
}

void MatrizDispersa::insertarAlFinalV(Node *valor, Node *cabeV) {
    Node *aux = cabeV;
    while (aux->sig != nullptr) {
        aux = aux->sig;
    }
    aux->sig = valor;
    valor->prev = aux;
}

void MatrizDispersa::insertarAlMedioH(Node *valor, Node *horizontal) {
    horizontal->arriba->abajo = valor;
    valor->abajo = horizontal;
    valor->arriba = horizontal->arriba;
    horizontal->arriba = valor;
}

void MatrizDispersa::insertarAlMedioV(Node *valor, Node *vertical) {
    vertical->prev->sig = valor;
    valor->sig = vertical;
    valor->prev = vertical->prev;
    vertical->prev = valor;
}

void MatrizDispersa::insertarValor(int valor, int cabH, int cabV) {

    Node *cabeH = nullptr;
    Node *cabeV = nullptr;
    Node *usuarioNuevo = new Node(valor);

    if (estaVacia()) {
        cabeH = insertarCabeceraH(cabH);
        cabeV = insertarCabeceraV(cabV);
        insertarAlFinal(usuarioNuevo, cabeH, cabeV);
        return;
    }

    cabeH = cabeceraHorizontal(cabH);
    cabeV = cabeceraVertical(cabV);

    if (cabeH == nullptr && cabeV == nullptr) {
        cabeH = insertarCabeceraH(cabH);
        cabeV = insertarCabeceraV(cabV);
        insertarAlFinal(usuarioNuevo, cabeH, cabeV);
        return;
    }

    if (cabeH == nullptr) {
        cabeH = insertarCabeceraH(cabH);
        insertarAlFinal(usuarioNuevo, cabeH, cabeV);
        return;
    }

    if (cabeV == nullptr) {
        cabeV = insertarCabeceraV(cabV);
        insertarAlFinal(usuarioNuevo, cabeH, cabeV);
        return;
    }

    Node *auxH = cabeH->abajo;
    Node *userCabV;
    bool abajo;


    while (auxH != nullptr) {
        userCabV = enCabeceraV(auxH);
        abajo = masAbajo(userCabV, cabV);
        if (!abajo) break;
        auxH = auxH->abajo;
    }

    if (abajo) {
        insertarAlFinalH(usuarioNuevo, cabeH);
    } else {
        insertarAlMedioH(usuarioNuevo, auxH);
    }

    Node *auxV = cabeV->sig;
    Node *userCabH;
    bool siguiente = false;
    while (auxV != nullptr) {
        userCabH = enCabeceraH(auxV);
        siguiente = masDerecha(userCabH, cabH);
        if (!siguiente) break;
        auxV = auxV->sig;
    }

    if (siguiente) {
        insertarAlFinalV(usuarioNuevo, cabeV);
    } else {
        insertarAlMedioV(usuarioNuevo, auxV);
    }

}

void MatrizDispersa::insertarAlFinal(Node *valor, Node *cabeH, Node *cabeV) {
    insertarAlFinalH(valor, cabeH);
    insertarAlFinalV(valor, cabeV);
}


void MatrizDispersa::reporte() {
    string dot = "digraph G {\n"
                 "rankdir=LR;\n" // Orientación horizontal
                 "node[shape=box];\n";

    // Generar nodos de las cabeceras horizontales
    Node *hdH = this->cabeH;
    while (hdH != nullptr) {
        dot += "H" + to_string(hdH->valor) + "[label=\"H" + to_string(hdH->valor) +
               "\", group=1, style=filled, color=lightblue];\n";
        hdH = hdH->sig;
    }

    // Generar nodos de las cabeceras verticales
    Node *hdV = this->cabeV;
    while (hdV != nullptr) {
        dot += "V" + to_string(hdV->valor) + "[label=\"V" + to_string(hdV->valor) +
               "\", style=filled, color=lightgreen];\n";
        hdV = hdV->abajo;
    }

    // Generar nodos internos de la matriz
    hdH = this->cabeH;
    while (hdH != nullptr) {
        Node *aux = hdH->abajo;
        while (aux != nullptr) {
            dot += "N" + to_string(aux->valor) + "[label=\"" + to_string(aux->valor) + "\", group=" +
                   to_string(aux->sig ? aux->sig->valor : hdH->valor + 1) + "];\n";
            aux = aux->abajo;
        }
        hdH = hdH->sig;
    }

    // Relacionar cabeceras horizontales con nodos
    hdH = this->cabeH;
    while (hdH != nullptr) {
        if (hdH->abajo != nullptr) {
            dot += "H" + to_string(hdH->valor) + " -> N" + to_string(hdH->abajo->valor) + " [dir=both];\n";
        }
        hdH = hdH->sig;
    }

    // Relacionar cabeceras verticales con nodos
    hdV = this->cabeV;
    while (hdV != nullptr) {
        if (hdV->sig != nullptr) {
            dot += "V" + to_string(hdV->valor) + " -> N" + to_string(hdV->sig->valor) + " [dir=both];\n";
        }
        hdV = hdV->abajo;
    }

    // Generar relaciones horizontales entre nodos internos
    hdH = this->cabeH;
    while (hdH != nullptr) {
        Node *aux = hdH->abajo;
        while (aux != nullptr) {
            if (aux->abajo != nullptr) {
                dot += "N" + to_string(aux->valor) + " -> N" + to_string(aux->abajo->valor) + " [dir=both];\n";
            }
            aux = aux->abajo;
        }
        hdH = hdH->sig;
    }

    // Generar relaciones verticales entre nodos internos
    hdV = this->cabeV;
    while (hdV != nullptr) {
        Node *aux = hdV->sig;
        while (aux != nullptr) {
            if (aux->sig != nullptr) {
                dot += "N" + to_string(aux->valor) + " -> N" + to_string(aux->sig->valor) + " [dir=both];\n";
            }
            aux = aux->sig;
        }
        hdV = hdV->abajo;
    }

    // Relacionar cabeceras horizontales entre sí
    hdH = this->cabeH;
    while (hdH != nullptr && hdH->sig != nullptr) {
        dot += "H" + to_string(hdH->valor) + " -> H" + to_string(hdH->sig->valor) + " [dir=both];\n";
        hdH = hdH->sig;
    }

    // Relacionar cabeceras verticales entre sí
    hdV = this->cabeV;
    while (hdV != nullptr && hdV->abajo != nullptr) {
        dot += "V" + to_string(hdV->valor) + " -> V" + to_string(hdV->abajo->valor) + " [dir=both];\n";
        hdV = hdV->abajo;
    }

    // Finalizar el archivo DOT
    dot += "}\n";

    // Guardar en un archivo .dot
    string dotFile = "matriz.dot";
    string pngFile = "matriz.png";

    ofstream file(dotFile);
    file << dot;
    file.close();

    // Ejecutar comando para convertir .dot a .png
    string command = "dot -Tpng " + dotFile + " -o " + pngFile;
    int result = system(command.c_str());

    if (result == 0) {
        cout << "Reporte generado en '" << pngFile << "'" << endl;
    } else {
        cout << "Error al generar la imagen." << endl;
    }
}
