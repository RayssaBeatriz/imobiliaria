#include <iostream>
#include <string>
using namespace std;
#include "Classes/imovel.h"
#include "Classes/corretor.h"

int main() {
    int n;
    cin>>n;

    //Criar avaliadores
    Corretor* corretores[n];
    for(int i = 0; i <n; i++){
        int telefoneAvaliador;;
        bool avaliador;
        float lat, lng;
        string nomeAvaliador;
        cin >> telefoneAvaliador >> avaliador >> lat >> lng >> nomeAvaliador;
        Corretor corretor(telefoneAvaliador, avaliador, lat, lng, nomeAvaliador);
        corretores[i] = &corretor;
        corretores[i]->exibirInformacoes();
    }

    cin>>n;
    //Criar clientes
    
    for(int i = 0; i <n; i++){
        int telefoneCliente;
        string nomeCliente;
        cin >> telefoneCliente >> nomeCliente;
    }

    //Criar imóveis
    cin>>n;
    Imovel* imoveis[n];
    for(int i = 0; i <n; i++){
        string tipoImovel;
        int proprietarioId;
        float lat, lon;
        double preco;
        string endereco;
        cin >> tipoImovel >> proprietarioId >> lat >> lon >> preco >> endereco;
        Imovel imovel(tipoImovel, proprietarioId, lat, lon, preco, endereco);
        imoveis[i] = &imovel;
    }
    


    return 0;
}

