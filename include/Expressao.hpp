#include<string>
#include "Pilha.hpp"

class Expressao{
public: 
    Expressao(){};
    void DivideEntrada(std::string entrada);
    void AtribuiValor(std::string expressao, std::string valoracao);
    void SeparaOpera(std::string expressao);
    int AvaliaExpressao(std::string expressao);
    int realizaOperacao(char var1, char var2, char op);
    int precedencia(char operador);


private:
    std::string expressao;
    std::string valoracao;
    std::string operadores;
    std::string valores;

};