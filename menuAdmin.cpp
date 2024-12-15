//
// Created by Bryan Ignacio on 12/10/24.
//
#include <iostream>
using namespace std;

int main() {

    int option;
    while(true){
        cout << "=========================" << endl;
        cout << "   MENU ADMINISTRADOR    " << endl;
        cout << "=========================" << endl;
        cout << "1. Registrar Usuario." << endl;
        cout << "2. Reporte Matriz." << endl;
        cout << "3. Reporte Activos Disponibles de un Departamento." << endl;
        cout << "4. Reporte Activos Disponibles de una Empresa." << endl;
        cout << "5. Reporte Transacciones." << endl;
        cout << "6. Reporte Activos de un Usuario." << endl;
        cout << "7. Activos Rentados por un Usuario." << endl;
        cout << "8. Ordenar Transacciones." << endl;
        cout << "9. Salir." << endl;
        cout << "=========================" << endl;
        cout << "\t>Ingresa una opcion: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Registrar Usuario: " << endl;
                cout << "........................." << endl;
                cout << "........................." << endl;
                break;
            case 2:
                cout << "Reporte Matriz.: " << endl;
                cout << "........................." << endl;
                cout << "........................." << endl;
                break;
            case 3:
                cout << "Reporte Activos Disponibles de un Departamento: " << endl;
                cout << "........................." << endl;
                cout << "........................." << endl;
                break;
            case 4:
                cout << "Reporte Activos Disponibles de una Empresa: " << endl;
                cout << "........................." << endl;
                cout << "........................." << endl;
                break;
            case 5:
                cout << "Reporte Transacciones: " << endl;
                cout << "........................." << endl;
                cout << "........................." << endl;
                break;
            case 6:
                cout << "Reporte Activos de un Usuario: " << endl;
                cout << "........................." << endl;
                cout << "........................." << endl;
                break;
            case 7:
                cout << "Activos Rentados por un Usuario: " << endl;
                cout << "........................." << endl;
                cout << "........................." << endl;
                break;
            case 8:
                cout << "Ordenar Transacciones: " << endl;
                cout << "........................." << endl;
                cout << "........................." << endl;
                break;
            case 9:
                return 0;
                break;
        }
    }
    return 0;
}
