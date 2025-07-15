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

    Cliente(const string& nome, const string& telefone);

private:
    static int nextId;
};

#endif