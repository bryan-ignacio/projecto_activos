//
// Created by Bryan Ignacio on 12/15/24.
//

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

class Activo {
    string idActivo; // 15 caracteres.
    string name;
    string description;

public:
    Activo(string name, string description);

    string getIdActivo();

    string getName();

    void setName(string nameActivo);

    string getDescription();

    void setDescription(string descriptionActivo);

    string toString();
private:
    string generarId15caracteres();
};

Activo::Activo(std::string name, std::string description) {
    this->idActivo = generarId15caracteres();
    this->name = name;
    this->description = description;
}

string Activo::getIdActivo() {
    return this->idActivo;
}


string Activo::getName() {
    return this->name;
}

void Activo::setName(std::string nameActivo) {
    this->name = nameActivo;
}

string Activo::getDescription() {
    return this->description;
}

void Activo::setDescription(std::string descriptionActivo) {
    this->description = descriptionActivo;
}

string Activo::generarId15caracteres() {
    const string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, caracteres.size() - 1);
    string id;
    for (int i = 0; i < 15; ++i) {
        id += caracteres[dis(gen)];
    }
    return id;
}

string Activo::toString() {
    return "Activo->[ id: "+this->idActivo+ " name: " + this->name + " descripcion: " + this->description + "]";
}

