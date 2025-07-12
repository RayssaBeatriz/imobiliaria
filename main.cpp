#include <iostream>
#include <string>
using namespace std;
#include "Classes/imovel.h"

int main() {
    // Criação de um objeto Imovel
    Imovel imovel("Apartamento", 1, -23.5505, -46.6333, 500000.00, "Rua Exemplo, 123");
    
    // Exibição das informações do imóvel
    imovel.exibirInformacoes();
    
    return 0;
}