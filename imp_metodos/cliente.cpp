#include "../Classes/cliente.h"

int Cliente::nextId = 1;

// Construtor
Cliente::Cliente(const string& nome, const string& telefone) {
    this->id = nextId++; // Atribui o ID atual e incrementa para o pr�ximo.
    this->nome = nome;
    this->telefone = telefone;
}