#include "Expressao.hpp"
#include <string>

void Expressao::DivideEntrada(std::string entrada) {
    size_t primAspa = entrada.find("\"");
    size_t segAspa = entrada.find("\"", primAspa + 1);
    if (primAspa != std::string::npos && segAspa != std::string::npos) {
        expressao = entrada.substr(primAspa + 1, segAspa - primAspa - 1);
        valoracao = entrada.substr(segAspa + 1);
    } 
    else {
        expressao = entrada;
        valoracao = "";
    }
}

std::string AtribuiValor(std::string expressao, std::string valoracao) {
    std::string expressaoAtualizada = expressao;
    for (int i = 0; i < valoracao.length(); i++) {
        for (int j = 0; j < expressao.length(); j++) {
            if (expressao[j] == static_cast<char>('0' + i)) {
                expressaoAtualizada[j] = valoracao[i];
            }
        }
    }
    return expressaoAtualizada;
}