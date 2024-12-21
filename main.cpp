#include <iostream>
#include "MatrizDispersa.h"

using namespace std;

int main() {
    MatrizDispersa *matriz = new MatrizDispersa();
    Usuario *user1 = new Usuario("elian_estrada", "Elian Estrada", "1234", "guatemala", "igss");
    Node *node1 = new Node(user1);
    matriz->insertarValor(node1, node1->user->getDepartamento(), node1->user->getEmpresa());

    Usuario *user2 = new Usuario("juanito", "Juan Perez", "4567", "jutiapa", "max");
    Node *node2 = new Node(user2);
    matriz->insertarValor(node2, node2->user->getDepartamento(), node2->user->getEmpresa());

    Usuario *user3 = new Usuario("pedrito", "Pedro Rodriguez", "48956", "jalapa", "usac");
    Node *node3 = new Node(user3);
    matriz->insertarValor(node3, node3->user->getDepartamento(), node3->user->getEmpresa());

    Usuario *user8 = new Usuario("mafer", "Maria Fernanda", "54312", "peten", "cinepolis");
    Node *node8 = new Node(user8);
    matriz->insertarValor(node8, node8->user->getDepartamento(), node8->user->getEmpresa());

    Usuario *user4 = new Usuario("juanma", "Juan Manuel", "32897", "guatemala", "usac");
    Node *node4 = new Node(user4);
    matriz->insertarValor(node4, node4->user->getDepartamento(), node4->user->getEmpresa());

    Usuario *user5 = new Usuario("casimiro", "Carlos Perez", "721896", "guatemala", "max");
    user5->arbolActivos->insert(new Activo("balanza", ""));
    user5->arbolActivos->insert(new Activo("canastas", ""));
    user5->arbolActivos->insert(new Activo("linternas", ""));
    user5->arbolActivos->insert(new Activo("cargadores", ""));
    user5->arbolActivos->insert(new Activo("cables", ""));
    user5->arbolActivos->insert(new Activo("tazos", ""));
    Node *node5 = new Node(user5);
    matriz->insertarValor(node5, node5->user->getDepartamento(), node5->user->getEmpresa());

    Usuario *user6 = new Usuario("fuego03", "Fernando Mendez", "891346", "jutiapa", "cinepolis");
    Node *node6 = new Node(user6);
    matriz->insertarValor(node6, node6->user->getDepartamento(), node6->user->getEmpresa());

    Usuario *user7 = new Usuario("azurdia", "Alejandra Guzman", "780145", "jutiapa", "usac");
    Node *node7 = new Node(user7);
    matriz->insertarValor(node7, node7->user->getDepartamento(), node7->user->getEmpresa());

    Usuario *user9 = new Usuario("incrediboy", "Iraldo Martinez", "201598", "jutiapa", "max");
    Node *node9 = new Node(user9);
    matriz->insertarValor(node9, node9->user->getDepartamento(), node9->user->getEmpresa());

    Usuario *user10 = new Usuario("alcachofa", "Antonio Lopez", "20435", "jalapa", "usac");
    Node *node10 = new Node(user10);
    matriz->insertarValor(node10, node10->user->getDepartamento(), node10->user->getEmpresa());
    //casimiro


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

                        //
                        string repoUser;
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
                                cout << "ingrese username:" << endl;
                                cin >> repoUser;
                                matriz->buscarUsuarioPorUsername(repoUser)->user->arbolActivos->print();
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
                    Node *usuarioEncontrado = matriz->buscarUsuarioPorUsername(usuario);
                    int optionUser;
                    do {
                        string name;
                        string description;
                        string idActivo;
                        cout << "=========================" << endl;
                        cout << "   USUARIO: (" + usuarioEncontrado->user->getUsername() + ")" << endl;
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
                                cout << "Ingresar Nombre:" << endl;
                                cin >> name;
                                cout << "Ingresar Descripcion: " << endl;
                                cin >> description;
                                usuarioEncontrado->user->arbolActivos->insert(new Activo(name, description));
                                cout << "........................." << endl;
                                break;
                            case 2:
                                cout << "........................." << endl;
                                cout << "Eliminar Activo: " << endl;
                                cout << "mostrar lista de activos" << endl;
                                usuarioEncontrado->user->arbolActivos->printActivos();
                                cout << "Ingrese el ID del Activo a Eliminar: " << endl;
                                cin >> idActivo;
                                usuarioEncontrado->user->arbolActivos->eliminar(idActivo);
                                cout << "el activo fue eliminado" << endl;
                                usuarioEncontrado->user->arbolActivos->printActivos();
                                cout << "........................." << endl;
                                break;
                            case 3:
                                cout << "........................." << endl;
                                cout << "Modificar Activo: " << endl;
                                cout << "mostrar lista de activos" << endl;
                                usuarioEncontrado->user->arbolActivos->printActivos();

                                cout << "Ingrese el IdActivo a Modificar: ---" << endl;
                                cout << "ingrese descripcion nueva: " << endl;
                                cout << "Activo Modificado:" << endl;

                                cout << "ID: --- NOMBRE: --- DESCRIPCION: ---" << endl;
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
