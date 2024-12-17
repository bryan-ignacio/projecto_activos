//
// Created by Bryan Ignacio on 12/17/24.
//
#include <iostream>
#include <fstream>
#include "Usuario.h"
using namespace std;


int main(){

    Activo* activo1 = new Activo("Activo1", "Descripción 1");
    Activo* activo2 = new Activo("Activo2", "Descripción 2");
    Activo* activo3 = new Activo("Activo3", "Descripción 3");

    Usuario *u1 = new Usuario("Bryan", "user1", "Bryan Ignacio", "Guatemala", "IGGS");
    u1->arbolActivos->insert(activo1);
    u1->arbolActivos->insert(activo2);
    u1->arbolActivos->insert(activo3);

    string path = "/Users/bryan/Developer/matrix_lab/";
    string dotFile = path + "arbolAVL.dot";
    string pngFile = path + "arbolAVL.png";

    // Abrir y escribir el archivo .dot
    ofstream file(dotFile);
    if (!file) {
        cerr << "Error al crear el archivo .dot" << endl;
        return 1; // Salir con error
    }
    file <<  u1->arbolActivos->print();// Genera el contenido del árbol AVL
    file.close();

    // Comando para convertir el archivo .dot a .png usando Graphviz
    string command = "dot -Tpng " + dotFile + " -o " + pngFile;
    if (system(command.c_str()) != 0) {
        cerr << "Error al ejecutar Graphviz (dot)" << endl;
        return 1; // Salir con error
    }

    cout << "El árbol AVL se ha generado correctamente en: " << pngFile << endl;

    // Abrir la imagen .png usando Preview en macOS
    command = "open " + pngFile;
    if (system(command.c_str()) != 0) {
        cerr << "Error al abrir el archivo .png con Preview" << endl;
        return 1;
    }
    // Liberar memoria
    delete u1->arbolActivos;


    return 0;
}