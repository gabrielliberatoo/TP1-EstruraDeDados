#ifndef EXPRESSAO_HPP
#define EXPRESSAO_HPP
#include<string>
#include "Pilha.hpp"


class Expressao{
public: 
    Expressao(){};
    std::string AtribuiValor(std::string expressao, std::string valoracao);
    int AvaliaExpressao(std::string expressao, std::string valarocao);
    int realizaOperacao(char var1, char var2, char op);
    int precedencia(char operador);

private:
    std::string expressao;
    std::string valoracao;

    friend class TipoNo;

};

#endif