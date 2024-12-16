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

    Node *cabeceraHorizontal(string departamento);

    Node *cabeceraVertical(string empresa);

    Node *insertarCabeceraH(string departamento);

    Node *insertarCabeceraV(string empresa);

    void insertarAlFinal(Node *valor, Node *cabeH, Node *cabeV);

    void insertarAlFinalH(Node *valor, Node *cabeH);

    void insertarAlFinalV(Node *valor, Node *cabeV);

    void insertarAlMedioH(Node *valor, Node *horizontal);

    void insertarAlMedioV(Node *valor, Node *vertical);

    void insertarValor(Node *valor, string cabH, string cabV);

    Node *enCabeceraH(Node *node);

    Node *enCabeceraV(Node *node);

    bool masDerecha(Node *cabeH, string cabH);

    bool masAbajo(Node *cabeV, string cabV);

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

bool MatrizDispersa::masDerecha(Node *cabeH, string cabH) {
    Node *aux = cabeH;
    while (aux != nullptr) {
        if (aux->user->getDepartamento() == cabH) return true;
        aux = aux->sig;
    }
    return false;
}

bool MatrizDispersa::masAbajo(Node *cabeV, string cabV) {
    Node *aux = cabeV;
    while (aux != nullptr) {
        if (aux->user->getEmpresa() == cabV) return true;
        aux = aux->abajo;
    }
    return false;
}

Node *MatrizDispersa::insertarCabeceraH(string departamento) {
    Usuario *usuario = new Usuario("", "", "", departamento, "");
    Node *nuevaCabecera = new Node(usuario);
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

Node *MatrizDispersa::insertarCabeceraV(string empresa) {
    Usuario *usuario = new Usuario("", "", "", "", empresa);
    Node *nuevaCabecera = new Node(usuario);
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

Node *MatrizDispersa::cabeceraHorizontal(string departamento) {
    if (estaVacia()) {
        return nullptr;
    }
    Node *aux = this->cabeH;
    while (aux != nullptr) {
        if (aux->user->getDepartamento() == departamento) return aux;
        aux = aux->sig;
    }
    return nullptr;
}

Node *MatrizDispersa::cabeceraVertical(string empresa) {
    if (estaVacia()) {
        return nullptr;
    }
    Node *aux = this->cabeV;
    while (aux != nullptr) {
        if (aux->user->getEmpresa() == empresa) return aux;
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

void MatrizDispersa::insertarValor(Node *valor, string cabH, string cabV) {
    Node *cabeH = nullptr;
    Node *cabeV = nullptr;
    Usuario *newUser = valor->user;
    Node *usuarioNuevo = new Node(newUser);

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
    string dot = "digraph MatrizDispersa {\n";
    dot += "rankdir=TB;\n"; // Configuración base de arriba hacia abajo
    dot += "node[shape=box, style=filled, color=lightgrey];\n";

    // Cabeceras Horizontales (Departamentos en el eje X)
    dot += "{ rank=same; ";
    Node *hdH = this->cabeH;
    while (hdH != nullptr) {
        dot += "H_" + hdH->user->getDepartamento() + "[label=\"" + hdH->user->getDepartamento() + "\", color=lightblue]; ";
        hdH = hdH->sig;
    }
    dot += "}\n";

    // Cabeceras Verticales (Empresas en el eje Y)
    Node *hdV = this->cabeV;
    while (hdV != nullptr) {
        dot += "V_" + hdV->user->getEmpresa() + "[label=\"" + hdV->user->getEmpresa() + "\", color=lightgreen];\n";
        hdV = hdV->abajo;
    }

    // Nodos internos (Usuarios)
    Node *horiz = this->cabeH;
    while (horiz != nullptr) {
        Node *aux = horiz->abajo;
        while (aux != nullptr) {
            dot += "N_" + aux->user->getUsername() + "[label=\"" + aux->user->getUsername() + "\", color=white];\n";
            aux = aux->abajo;
        }
        horiz = horiz->sig;
    }

    // Relaciones horizontales
    horiz = this->cabeH;
    while (horiz != nullptr) {
        if (horiz->sig != nullptr) {
            dot += "H_" + horiz->user->getDepartamento() + " -> H_" + horiz->sig->user->getDepartamento() + " [dir=both];\n";
        }
        Node *aux = horiz->abajo;
        if (aux != nullptr) {
            dot += "H_" + horiz->user->getDepartamento() + " -> N_" + aux->user->getUsername() + " [dir=both];\n";
        }
        while (aux != nullptr) {
            if (aux->abajo != nullptr) {
                dot += "N_" + aux->user->getUsername() + " -> N_" + aux->abajo->user->getUsername() + " [dir=both];\n";
            }
            aux = aux->abajo;
        }
        horiz = horiz->sig;
    }

    // Relaciones verticales
    Node *vert = this->cabeV;
    while (vert != nullptr) {
        if (vert->abajo != nullptr) {
            dot += "V_" + vert->user->getEmpresa() + " -> V_" + vert->abajo->user->getEmpresa() + " [dir=both];\n";
        }
        Node *aux = vert->sig;
        if (aux != nullptr) {
            dot += "V_" + vert->user->getEmpresa() + " -> N_" + aux->user->getUsername() + " [dir=both];\n";
        }
        while (aux != nullptr) {
            if (aux->sig != nullptr) {
                dot += "N_" + aux->user->getUsername() + " -> N_" + aux->sig->user->getUsername() + " [dir=both];\n";
            }
            aux = aux->sig;
        }
        vert = vert->abajo;
    }

    dot += "}\n";

    // Guardar el archivo DOT
    string dotFile = "matriz.dot";
    string pngFile = "matriz.png";

    ofstream file(dotFile);
    file << dot;
    file.close();

    // Ejecutar comando para convertir DOT a PNG
    string command = "dot -Tpng " + dotFile + " -o " + pngFile;
    int result = system(command.c_str());

    if (result == 0) {
        cout << "Reporte generado exitosamente en '" << pngFile << "'." << endl;
    } else {
        cout << "Error al generar la imagen. Asegúrate de tener Graphviz instalado." << endl;
    }
}