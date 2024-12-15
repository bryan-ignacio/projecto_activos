//
// Created by Bryan Ignacio on 12/10/24.
//
#include <iostream>

using namespace std;

int main() {
    int option;
    while (true) {
        cout << "=========================" << endl;
        cout << "   USUARIO: (Username)   " << endl;
        cout << "=========================" << endl;
        cout << "1. Agregar Activo." << endl;
        cout << "2. Eliminar Activo." << endl;
        cout << "3. Modificar Activo." << endl;
        cout << "4. Rentar Activo." << endl;
        cout << "5. Activos Rentados." << endl;
        cout << "6. Mis Activos Rentados." << endl;
        cout << "7. Cerrar Sesion." << endl;
        cout << "=========================" << endl;
        cout << "\t>Ingresa una opcion: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "........................." << endl;
                cout << "Agregar Activo: " << endl;
                cout << "........................." << endl;
                break;
            case 2:
                cout << "........................." << endl;
                cout << "Eliminar Activo: " << endl;
                cout << "........................." << endl;
                break;
            case 3:
                cout << "........................." << endl;
                cout << "Modificar Activo: " << endl;
                cout << "........................." << endl;
                break;
            case 4:
                cout << "........................." << endl;
                cout << "Rentar Activo: " << endl;
                cout << "........................." << endl;
                break;
            case 5:
                cout << "........................." << endl;
                cout << "Activos Rentados: " << endl;
                cout << "........................." << endl;
                break;
            case 6:
                cout << "........................." << endl;
                cout << "Mis Activos Rentados: " << endl;
                cout << "........................." << endl;
                break;
            case 7:
                cout << "Saliste del Programa. Adios!" << endl;
                return 0;
            default:
                cout << "opcion Invalida. Por favor intenta de nuevo." << endl;
        }
    }
    return 0;
};