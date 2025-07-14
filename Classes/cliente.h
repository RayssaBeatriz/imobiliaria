#include <iostream>
#include <string>
using namespace std;

#ifndef CLIENTE_H
#define CLIENTE_H

// Classe cliente
class Cliente {
public:
    int id;
    string nome;
    string telefone;

    Cliente(const string& nome, const int telefone);

private:
    static int nextId;
};

#endif