#include <iostream>
#include <string>
using namespace std;
#include "Classes/imovel.h"
 
//Construtor
Imovel::Imovel(string tipo, int proprietarioId, float lat, float lon, double preco, string endereco){
    tipo = tipo;
    proprietarioId = proprietarioId;
    lat = lat;
    lon = lon;
    preco = preco;
    endereco = endereco;

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


