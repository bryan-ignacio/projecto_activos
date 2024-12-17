#include <iostream>
#include "MatrizDispersa.h"

using namespace std;

int main() {
    MatrizDispersa *matriz = new MatrizDispersa();
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
        string usuario;
        string contrasena;
        string fullName;
        string departamento;
        string empresa;
        switch (option) {
            case 1:
                cout << "_________________________" << endl;
                cout << "Iniciar Sesion" << endl;
                cout << "_________________________" << endl;
                cout << "Ingresa usuario:" << endl;
                cin >> usuario;
                cout << "Ingresa password:" << endl;
                cin >> contrasena;
                cout << "_________________________" << endl;
                if (usuario == "admin" && contrasena == "admin") {
                    int optionAdmin;
                    do {
                        cout << "==================================================" << endl;
                        cout << "   MENU ADMINISTRADOR    " << endl;
                        cout << "==================================================" << endl;
                        cout << "1. Registrar Usuario." << endl;
                        cout << "2. Reporte Matriz." << endl;
                        cout << "3. Reporte Activos Disponibles de un Departamento." << endl;
                        cout << "4. Reporte Activos Disponibles de una Empresa." << endl;
                        cout << "5. Reporte Transacciones." << endl;
                        cout << "6. Reporte Activos de un Usuario." << endl;
                        cout << "7. Activos Rentados por un Usuario." << endl;
                        cout << "8. Ordenar Transacciones." << endl;
                        cout << "9. Cerrar Sesion" << endl;
                        cout << "==================================================" << endl;
                        cout << "\t>Ingresa una opcion: ";
                        cin >> optionAdmin;
                        Usuario *user;
                        Node *node;
                        string name;
                        string pass;
                        string full;
                        string depa;
                        string empr;
                        switch (optionAdmin) {
                            case 1:
                                cout << "........................." << endl;
                                cout << "Registrar Usuario: " << endl;
                                cout << "........................." << endl;
                                cout << "\t>Ingrese username: " << endl;
                                cin >> name;
                                cout << "\t>Ingrese password: " << endl;
                                cin >> pass;
                                cin.ignore(); // Limpia el buffer antes de usar getline.
                                cout << "\t>Ingrese FullName: " << endl;
                                getline(cin, full);
                                cout << "\t>Ingrese Departamento: " << endl;
                                getline(cin, depa);
                                cout << "\t>Ingrese Empresa: " << endl;
                                getline(cin, empr);
                                // agregar el nuevo Usuario a la matriz.
                                user = new Usuario(name, pass, full, depa, empr);
                                node = new Node(user);
                                matriz->insertarValor(node, node->user->getDepartamento(), node->user->getEmpresa());
                                cout << "........................." << endl;
                                break;
                            case 2:
                                cout << "........................." << endl;
                                cout << "Reporte Matriz.: " << endl;
                                matriz->reporte();
                                cout << "........................." << endl;
                                break;
                            case 3:
                                cout << "........................." << endl;
                                cout << "Reporte Activos Disponibles de un Departamento: " << endl;
                                cout << "........................." << endl;
                                break;
                            case 4:
                                cout << "........................." << endl;
                                cout << "Reporte Activos Disponibles de una Empresa: " << endl;
                                cout << "........................." << endl;
                                break;
                            case 5:
                                cout << "........................." << endl;
                                cout << "Reporte Transacciones: " << endl;
                                cout << "........................." << endl;
                                break;
                            case 6:
                                cout << "........................." << endl;
                                cout << "Reporte Activos de un Usuario: " << endl;
                                cout << "........................." << endl;
                                break;
                            case 7:
                                cout << "........................." << endl;
                                cout << "Activos Rentados por un Usuario: " << endl;
                                cout << "........................." << endl;
                                break;
                            case 8:
                                cout << "........................." << endl;
                                cout << "Ordenar Transacciones: " << endl;
                                cout << "........................." << endl;
                                break;
                            case 9:
                                cout << "Cerro Sesion Administrador." << endl;
                                break;
                            default:
                                cout << "Opción no válida. Intente nuevamente." << endl;
                                break;
                        }
                    } while (optionAdmin != 9);
                } else if (matriz->buscarUsuarioPorUsername(usuario) != nullptr) {
                    Node *nodeEncontrado = matriz->buscarUsuarioPorUsername(usuario);
                    int optionUser;
                    do {
                        string name;
                        string description;
                        cout << "=========================" << endl;
                        cout << "   USUARIO: ("+ nodeEncontrado->user->getUsername()+")" << endl;
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
                        cin >> optionUser;
                        switch (optionUser) {
                            case 1:
                                cout << "........................." << endl;
                                cout << "Agregar Activo: " << endl;
                                cout << "idActivo(Automatico)" << endl;
                                cout << "Ingresar Nombre:" << endl;
                                cin >> name;
                                cout << "Ingresar Descripcion: " << endl;
                                cin >> description;
                                cout << "........................." << endl;
                                break;
                            case 2:
                                cout << "........................." << endl;
                                cout << "Eliminar Activo: " << endl;
                                cout << "mostrar lista de activos" << endl;
                                cout << "id: 3594921adsf, nombre: nombreActivo" << endl;
                                cout << "Ingrese el ID del Activo a Eliminar: " << endl;
                                cout << "id: ---   nombre: ---- : descripcion: ----" << endl;
                                cout << "........................." << endl;
                                break;
                            case 3:
                                cout << "........................." << endl;
                                cout << "Modificar Activo: " << endl;
                                cout << "mostrar lista de activos" << endl;
                                cout << "Ingrese el IdActivo a Modificar: ---" << endl;
                                if (true) {
                                    cout << "ingrese descripcion nueva: " << endl;
                                    cout << "Activo Modificado:" << endl;
                                    cout << "ID: --- NOMBRE: --- DESCRIPCION: ---" << endl;
                                };
                                cout << "........................." << endl;
                                break;
                            case 4:
                                cout << "........................." << endl;
                                cout << "Rentar Activo: " << endl;
                                cout << "ID: ---- NOMBRE: ---- TIEMPO DE RENTA: ---- " << endl;
                                cout << "ID: ---- NOMBRE: ---- TIEMPO DE RENTA: ---- " << endl;
                                cout << "ID: ---- NOMBRE: ---- TIEMPO DE RENTA: ---- " << endl;
                                cout << "ID: ---- NOMBRE: ---- TIEMPO DE RENTA: ---- " << endl;
                                cout << "ID: ---- NOMBRE: ---- TIEMPO DE RENTA: ---- " << endl;
                                int optionRentar;
                                do {
                                    cout << "" << endl;
                                    cout << "" << endl;
                                } while (optionRentar != 2);
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
                                cout << "Cerro Sesion User" << endl;
                                break;
                            default:
                                cout << "opcion Invalida. Por favor intenta de nuevo." << endl;
                        }
                    } while (optionUser != 7);
                } else {
                    cout << "usuario no encontrado.." << endl;
                    usuario = "";
                    contrasena = "";
                    departamento = "";
                    empresa = "";
                    break;
                }
                break;
            case 2:
                cout << "Saliste del Programa. Adios!" << endl;
                return 0;
            default:
                cout << "opcion Invalida. Por favor intenta de nuevo." << endl;
        }
        cout << endl;
    }
    return 0;
}
