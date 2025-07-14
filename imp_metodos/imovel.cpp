#include <iostream>
#include <string>
using namespace std;
#include "../Classes/imovel.h"
 
int Imovel::nextId = 1;

//Construtor
Imovel::Imovel(TipoImovel tipo, int proprietarioId, double lat, double lng, double preco, const string& endereco){
    this->id = nextId++; // Atribui o ID atual e depois incrementa para o próximo
    this->tipo = tipo;
    this->proprietarioId = proprietarioId;
    this->lat = lat;
    this->lng = lng;
    this->preco = preco;
    this->endereco = endereco;
}

void Imovel::exibirInformacoes(){
    cout<< "Informações do imóvel"<< endl;
    cout<< "Tipo: " << tipo << endl;
    cout<< "Proprietário ID: " << proprietarioId << endl;
    cout<< "Latitude: " << lat << endl;
    cout<< "Longitude: " << lon << endl;
    cout<< "Preço: " << preco << endl;
    cout<< "Endereço: " << endereco << endl;
}

// Converte o enum para sua representação em string
string Imovel::getTipoAsString() const {
    switch (tipo) {
    case CASA: return "Casa";
    case APARTAMENTO: return "Apartamento";
    case TERRENO: return "Terreno";
    }
}

// Converte uma string da entrada para o enum correspondente
TipoImovel stringToTipo(const string& str) {
    if (str == "casa" || str == "Casa") return CASA;
    if (str == "apartamento" || str == "Apartamento") return APARTAMENTO;
    if (str == "terreno" || str == "Terreno") return TERRENO;
}