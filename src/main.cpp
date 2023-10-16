#include <iostream>
#include <string>
#include "ArvoreBinaria.hpp"
//#include "Expressao.hpp"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " [-a | -s] formula valoracao" << std::endl;
        return 1;
    }

    std::string comando = argv[1];
    std::string formula = argv[2];
    std::string valoracao = argv[3];

    if (comando == "-a") {
        Expressao expressao;
        int result = expressao.AvaliaExpressao(formula, valoracao);
        std::cout << result << std::endl;
    } else if (comando == "-s") {
        ArvoreBinaria arvore;
        arvore.Insere(valoracao); 
        std::string satisfabilidade = arvore.Satisfabilidade(); 
        std::cout << satisfabilidade << std::endl;;
    } else {
        std::cerr << "Opção inválida. Use -a para avaliação de expressões ou -s para satisfabilidade." << std::endl;
        return 1;
    }

    return 0;
}
