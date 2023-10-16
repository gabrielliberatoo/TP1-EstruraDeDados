#include<string>
#include "Pilha.hpp"
#include "ArvoreBinaria.hpp"

class Expressao{
public: 
    Expressao(){};
    void DivideEntrada(std::string entrada);
    std::string AtribuiValor(std::string expressao, std::string valoracao);
    int AvaliaExpressao(std::string expressao, std::string valarocao);
    int realizaOperacao(char var1, char var2, char op);
    int precedencia(char operador);
    std::string Satisfabilidade(std::string expressao, std::string valoracao);
    std::string Satisfabilidade(const std::string& expressao, const std::string& variaveis);

private:
    std::string expressao;
    std::string valoracao;

    friend class TipoNo;

};