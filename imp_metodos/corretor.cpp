#include <iostream>
#include <string>
using namespace std;
#include "../Classes/corretor.h"
 
//Construtor
Corretor::Corretor(int telefone, bool avaliador, float lat, float lng, string nome){
    this->telefone = telefone;
    this->avaliador = avaliador;
    this->lat = lat;
    this->lng = lng;
    this->nome = nome;

}

void Corretor::exibirInformacoes(){
    cout<< "Informações do avaliador"<< endl;
    cout<< "Nome: " << nome << endl;
    cout<< "Telefone: " << telefone << endl;
    cout<< "Latitude: " << lat << endl;
    cout<< "Longitude: " << lng << endl;
    cout<< "Avaliador: " << (avaliador ? "Sim" : "Não") << endl;
}