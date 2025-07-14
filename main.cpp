#include <iostream>
#include <string>
using namespace std;
#include "Classes/imovel.h"
#include "Classes/corretor.h"
#include "Classes/cliente.h"

int main() {
    int nCorretores, nClientes, nImoveis;
    cin>>nCorretores;

    //Criar avaliadores
    Corretor* corretores[nCorretores];
    for(int i = 0; i <nCorretores; i++){
        int telefoneAvaliador;;
        bool avaliador;
        float lat, lng;
        string nomeAvaliador;
        cin >> telefoneAvaliador >> avaliador >> lat >> lng >> nomeAvaliador;
        corretores[i] = new Corretor(telefoneAvaliador, avaliador, lat, lng, nomeAvaliador);
    }

    cin>>nClientes;
    //Criar clientes
    Cliente* clientes[nClientes];
    for(int i = 0; i <nClientes; i++){
        int telefoneCliente;
        string nomeCliente;
        cin >> telefoneCliente >> nomeCliente;
        clientes[i] = new Cliente(nomeCliente, telefoneCliente);
    }

    //Criar imóveis
    cin>>nImoveis;
    Imovel* imoveis[nImoveis];
    for(int i = 0; i <nImoveis; i++){
        string tipoImovel;
        int proprietarioId;
        float lat, lon;
        double preco;
        string endereco;
        cin >> tipoImovel >> proprietarioId >> lat >> lon >> preco >> endereco;
        TipoImovel tipo = stringToTipo(tipoImovel);
        imoveis[i] = new Imovel(tipo, proprietarioId, lat, lon, preco, endereco);
    }

    //Exibir informações dos imóveis
    for(int i = 0; i < nImoveis; i++){
        imoveis[i]->exibirInformacoes();
        cout << endl;
    }   

    //Exibir informações dos corretores
    for(int i = 0; i < nCorretores; i++){ 
        corretores[i]->exibirInformacoes();
        cout << endl;
    }
    //Exibir informações dos clientes
    for(int i = 0; i < nClientes; i++){
        cout << "ID: " << clientes[i]->id << endl;
        cout << "Nome: " << clientes[i]->nome << endl;
    }
    


    return 0;
}

