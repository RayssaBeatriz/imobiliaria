#include <iostream>
#include <string>
using namespace std;

#ifndef IMOVEL_H
#define IMOVEL_H

enum class TipoImovel {
    CASA, APARTAMENTO, TERRENO, OUTRO
};

//Classe imovel
class Imovel {
public:
    int id;
    TipoImovel tipo;
    double lat;
    double lng;
    
    // Construtor
    Imovel(TipoImovel tipo, int proprietarioId, double lat, double lng, double preco, const string& endereco);
    void exibirInformacoes();

    string getTipoAsString() const;

private:
    static int nextId;
    int proprietarioId;
    double preco;
    string endereco;
};

// Fun��o auxiliar para converter uma string de entrada para o tipo enum TipoImovel
TipoImovel stringToTipo(const string& str);

#endif