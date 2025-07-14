#include <iostream>
#include <string>
using namespace std;

#ifndef IMOVEL_H
#define IMOVEL_H

enum class TipoImovel {
    CASA, APARTAMENTO, TERRENO
};

//Classe imovel
class Imovel {
public:
    int id;
    TipoImovel tipo;
    
    // Construtor
    Imovel(Tipo imovel tipo, int proprietarioId, double lat, double lng, double preco, const string& endereco);
    void exibirInformacoes();

    string getTipoAsString() const;

private:
    static int nextId;
    int proprietarioId;
    double lat;
    double lng;
    double preco;
    string endereco;
};

// Função auxiliar para converter uma string de entrada para o tipo enum TipoImovel
TipoImovel stringToTipo(const string& str);

#endif