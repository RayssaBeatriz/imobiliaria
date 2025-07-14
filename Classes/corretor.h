#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "../Classes/imovel.h"

#ifndef CORRETOR_H
#define CORRETOR_H

// Struct que representa um agendamento
struct Agenda {
    int hora;
    int minuto;
    int imovelId;
};

// Classe corretor
class Corretor {
private:
    static int nextId;

public:
    int id;
    string nome;
    double lat;
    double lng;
    vector<Imovel> imoveisParaAvaliar;
    vector<Agenda> agenda;
    string telefone;
    bool avaliador;
    
    Corretor(const string& nome, const string& telefone, bool avaliador, double lat, double lng);
    void exibirInformacoes();
    void ordenarRota();
};

#endif