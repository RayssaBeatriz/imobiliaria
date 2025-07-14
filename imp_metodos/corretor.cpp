#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;
#include "../Classes/corretor.h"

constexpr long double PI = 3.14159;
constexpr double EARTH_R = 6371.0; // Raio da Terra em Km

int Corretor::nextId = 1;

// Função auxiliar para converter graus em radianos
double grausParaRad(double g) {
    return g * PI / 180.0;
}

// Calcula a distância em km entre duas coordenadas com a fórmula de Haversine
double haversine(double lat1, double lng1, double lat2, double lng2) {
    double dlat = grausParaRad(lat2 - lat1);
    double dlng = grausParaRad(lng2 - lng1);
    double a = pow(sin(dlat / 2), 2) +
        cos(grausParaRad(lat1)) * cos(grausParaRad(lat2)) *
        pow(sin(dlng / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_R * c;
}

// Construtor
Corretor::Corretor(const string& nome, const string& telefone, bool avaliador, double lat, double lng) {
    this->id = nextId++;
    this->nome = nome;
    this->telefone = telefone;
    this->avaliador = avaliador;
    this->lat = lat;
    this->lng = lng;
}

void Corretor::exibirInformacoes() {
    cout << "Informações do avaliador" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Latitude: " << lat << endl;
    cout << "Longitude: " << lng << endl;
    cout << "Avaliador: " << (avaliador ? "Sim" : "Não") << endl;
}

// Algoritmo para ordenar a rota de visitas por meio da estratégia do Vizinho Mais Próximo
void Corretor::ordenarRota() {
    if (imoveisParaAvaliar.empty()) {
        return;
    }

    // Cria uma cópia da lista de imóveis para poder remover os que já foram agendados no processo da criação da agenda
    vector<Imovel> imoveisNaoVisitados = imoveisParaAvaliar;

    // Ponto de referência é a localização do próprio corretor
    double latAtual = this->lat;
    double lngAtual = this->lng;

    int tempoTotalMinutos = 540; // Tempo inicial de 09h em minutos após 00h

    // Loop para continuar enquanto houver imoveis na lista de não visitados
    while (!imoveisNaoVisitados.empty()) {
        int menorTempoViagem = numeric_limits<int>::max(); // Começa com um tempo "infinito" inicial
        int indiceEscolhido = -1; // Indice do próximo imóvel a ser visitado

        // Encontra o imóvel com menor tempo de viagem considerando 2 min por km arredondado
        for (size_t i = 0; i < imoveisNaoVisitados.size(); ++i) {
            double distancia = haversine(latAtual, lngAtual, imoveisNaoVisitados[i].lat, imoveisNaoVisitados[i].lng);
            int tempoViagem = round(distancia * 2.0);

            if (tempoViagem < menorTempoViagem) {
                menorTempoViagem = tempoViagem;
                indiceEscolhido = i;
            }
            // Em caso de tempos iguais, desempata pegando a ordem do menor ID
            else if (tempoViagem == menorTempoViagem) {
                if (imoveisNaoVisitados[i].id < imoveisNaoVisitados[indiceEscolhido].id) {
                    indiceEscolhido = i;
                }
            }
        }

        // ---> Daqui para baixo é atualização de estado da agenda para poder ir para a próxima iteração do loop de ordenação
        // Referência para o imóvel escolhido
        Imovel& proximoImovel = imoveisNaoVisitados[indiceEscolhido];

        // Adiciona o tempo de deslocamento ao relógio
        tempoTotalMinutos += menorTempoViagem;

        // Cria um novo agendamento e adiciona à agenda final do corretor
        Agenda novaAgenda;
        novaAgenda.hora = tempoTotalMinutos / 60;
        novaAgenda.minuto = tempoTotalMinutos % 60;
        novaAgenda.imovelId = proximoImovel.id;
        this->agenda.push_back(novaAgenda);

        // Adiciona o tempo de avaliação (60 min) para definir o ponto de partida do próximo deslocamento do corretor
        tempoTotalMinutos += 60;

        // Atualiza a localização atual do corretor após o fim da visita atual
        latAtual = proximoImovel.lat;
        lngAtual = proximoImovel.lng;

        // Remove o imóvel que acabou de ser visitado da lista de não visitados
        imoveisNaoVisitados.erase(imoveisNaoVisitados.begin() + indiceEscolhido);
    }
}