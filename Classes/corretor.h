#include <iostream>
#include <string>
using namespace std;

#ifndef CORRETOR_H
#define CORRETOR_H

//Classe imovel
class Corretor{
    private:
    static int id;
    string nome;
    int telefone; 
    bool avaliador; 
    float lat;
    float lng;

    public:
    Corretor(int telefone, bool avaliador, float lat, float lng, string nome);
    void exibirInformacoes();
};

#endif