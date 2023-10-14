#include<string>
#include "Pilha.hpp"

class Expressao{
public: 
Expressao(){};
void DivideEntrada(std::string entrada);
int AvaliaExpressao(std::string expressao, std::string valoracao);
std::string AtribuiValor(std::string expressao, std::string valoracao);
private:
std::string expressao;
std::string valoracao;


};