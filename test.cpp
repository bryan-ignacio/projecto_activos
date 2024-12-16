//
// Created by Bryan Ignacio on 12/15/24.
//
#include <iostream>
#include "Usuario.h"
using namespace std;

int main(){
    Usuario *user1 = new Usuario("bryan007", "contra123", "Bryan Ignacio", "Guatemala", "DevsGT");
    cout << user1->toString() << endl;
}