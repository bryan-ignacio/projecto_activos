//
// Created by Bryan Ignacio on 12/10/24.
//
#include <iostream>

using namespace std;

int main() {
    int option;
    while (true) {
        cout << "=========================" << endl;
        cout << "    RENTA DE ACTIVOS     " << endl;
        cout << "=========================" << endl;
        cout << "1. Iniciar Sesion." << endl;
        cout << "2. Salir." << endl;
        cout << "=========================" << endl;
        cout << "\t>Ingresa una opcion: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "_________________________" << endl;
                cout << "Iniciar Sesion:" << endl;
                cout << "_________________________" << endl;
                break;
            case 2:
                cout << "Saliste del Programa. Adios!" << endl;
                return 0;
            default:
                cout << "opcion Invalida. Por favor intenta de nuevo." << endl;
        }
    }
    return 0;
};