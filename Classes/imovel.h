#include <iostream>
#include <string>
using namespace std;

#ifndef CORRETOR_H
#define CORRETOR_H

//Classe imovel
class Imovel {
    private:
    static int id;
    string tipo;
    int proprietarioId;
    bool avaliador;
    float lat;
    float lon;
    string endereco;
    double preco;

    public:
    Imovel(string tipo, int proprietarioId, float lat, float lon, double preco, string endereco);
    void exibirInformacoes();
};

#endif