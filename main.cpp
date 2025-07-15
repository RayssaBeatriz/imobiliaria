#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Classes/imovel.h"
#include "Classes/corretor.h"
#include "Classes/cliente.h"

using namespace std;

int main() {
    vector<Corretor> todosCorretores;
    vector<Corretor> corretoresAvaliadores;
    vector<Cliente> clientes;
    vector<Imovel> imoveis;
    int nCorretores, nClientes, nImoveis;
    
    // Criar os corretores e adiciona à lista geral e lista de avaliadores
    cin >> nCorretores;
    for (int i = 0; i < nCorretores; i++) {
        string telefoneAvaliador, nomeAvaliador;
        bool avaliador;
        double lat, lng;
        cin >> telefoneAvaliador >> avaliador >> lat >> lng;
        getline(cin >> ws, nomeAvaliador); // Aqui o ws = whitespace manipulator e serve para descartar espaços em branco antes de ler o resto da linha
 

        todosCorretores.emplace_back(nomeAvaliador, telefoneAvaliador, avaliador, lat, lng);
    
        if (avaliador) {
        corretoresAvaliadores.push_back(todosCorretores.back()); // Adiciona uma cópia do último corretor criado à lista de avaliadores
        }
    }

    //Criar clientes
    cin>>nClientes;
    for(int i = 0; i <nClientes; i++){
        string telefoneCliente, nomeCliente;
        cin >> telefoneCliente;
        getline(cin >> ws, nomeCliente);
        clientes.emplace_back(nomeCliente, telefoneCliente);
    }

    //Criar imóveis
    cin>>nImoveis;
    for(int i = 0; i <nImoveis; i++){
        string tipoImovel, endereco;
        int proprietarioId;
        double lat, lng, preco;
        cin >> tipoImovel >> proprietarioId >> lat >> lng >> preco;
        getline(cin >> ws, endereco);
        imoveis.emplace_back(stringToTipo(tipoImovel), proprietarioId, lat, lng, preco, endereco);
    }

    // Distribuir os imóveis pela estratégia round-robin
    if (!corretoresAvaliadores.empty()) {
        for (size_t i = 0; i < imoveis.size(); i++) {
            corretoresAvaliadores[ i % corretoresAvaliadores.size() ].imoveisParaAvaliar.push_back(imoveis[i]);
        }
    }

    // Ordenar a rota para cada corretor pela estratégia do vizinho mais próximo
    for (Corretor& corretor : corretoresAvaliadores) {
        corretor.ordenarRota();
    }

    //Exibir informações da saída formatada
    for(size_t i = 0; i < corretoresAvaliadores.size(); i++){
        const Corretor& corretor = corretoresAvaliadores[i];

        cout << "Corretor " << corretor.id << endl;
        for (const Agenda& ag : corretor.agenda) {
            // Aqui o setfill('0') e setw(2) é usado para garantir o formato HH:MM
            cout << setfill('0') << setw(2) << ag.hora << ":"
                << setfill('0') << setw(2) << ag.minuto
                << " Imóvel " << ag.imovelId << endl;
        }

        // Linha em branco entre os agendamentos de cada corretor exceto o último
        if (i < corretoresAvaliadores.size() - 1) {
            cout << endl;
        }
    }
    

    return 0;
}