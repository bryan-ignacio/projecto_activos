//
// Created by Bryan Ignacio on 12/15/24.
//
#include <iostream>
#include "AVL.h"

using namespace std;

class Usuario {
private:
    string username;
    string password;
    string fullName;
    string departamentoH;
    string empresaV;
public:
    AVL *arbolActivos = new AVL();
    Usuario(string username, string password, string fullname, string departamento, string empresa);

    void setUsername(string username);

    string getUsername();

    void setPassword(string password);

    string getPassword();

    void setFullName(string fullname);

    string getFullName();

    void setDepartamento(string departamento);

    string getDepartamento();

    void setEmpresa(string empresa);

    string getEmpresa();

    string toString();
};

Usuario::Usuario(string username, string password, string fullname, string departamento, string empresa) {
    this->username = username;
    this->password = password;
    this->fullName = fullname;
    this->departamentoH = departamento;
    this->empresaV = empresa;
}


void Usuario::setUsername(string username) {
    this->username = username;
}

string Usuario::getUsername() {
    return this->username;
}

void Usuario::setPassword(string password) {
    this->password = password;
}

string Usuario::getPassword() {
    return this->password;
}

void Usuario::setFullName(string fullname) {
    this->fullName = fullname;
}

string Usuario::getFullName() {
    return this->fullName;
}

void Usuario::setDepartamento(string departamento) {
    this->departamentoH = departamento;
}

string Usuario::getDepartamento() {
    return this->departamentoH;
}

void Usuario::setEmpresa(string empresa) {
    this->empresaV = empresa;
}

string Usuario::getEmpresa() {
    return this->empresaV;
}

string Usuario::toString() {
    return "Usuario->[ username: " + this->username + " password: " + this->password + " fullname: " + this->fullName +
           " departamento: " + this->departamentoH + " empresa: " + this->empresaV + " ]";
}
