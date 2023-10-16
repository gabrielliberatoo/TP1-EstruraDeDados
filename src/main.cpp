#include <iostream>
#include <string>
#include "ArvoreBinaria.hpp"
#include "Expressao.hpp"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " [-a | -s] formula valoration" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string formula = argv[2];
    std::string valoration = argv[3];

    if (option == "-a") {
        Expressao expressao;
        int result = expressao.AvaliaExpressao(formula, valoration);
        std::cout << result << std::endl;
    } else if (option == "-s") {
        Expressao expressao;
        std::string variaveis = expressao.ExtraiVariaveis(formula);
        std::string result = expressao.Satisfabilidade(formula, variaveis, valoration);
        std::cout << result << std::endl;
    } else {
        std::cerr << "Opção inválida. Use -a para avaliação de expressões ou -s para satisfabilidade." << std::endl;
        return 1;
    }

    return 0;
}
