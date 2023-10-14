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

std::string Expressao::AtribuiValor(std::string expressao, std::string valoracao) {
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


int Expressao::AvaliaExpressao(std::string expressao, std::string valoracao) {
    PilhaEncadeada operadores;
    PilhaEncadeada valores;
    std::string expreValor = AtribuiValor(expressao,valoracao);


    for (char c : expreValor) {
        if (c == ' ') {
            continue;
        }

        if (c == '(') {
            operadores.Empilha(c);
        } else if (c == ')' && !operadores.Vazia()) {
            while (operadores.ItemNoTopo() != '(') {
                char op = operadores.Desempilha();
                char var2 = valores.Desempilha();
                char var1 = valores.Desempilha();
                char resultado = realizaOperacao(var1, var2, op);
                valores.Empilha(resultado);
            }
            operadores.Desempilha();
        } else if (c == '~' || c == '&' || c == '|') {
            while (!operadores.Vazia() && precedencia(c) <= precedencia(operadores.ItemNoTopo())) {
                char op = operadores.Desempilha();
                char var2 = valores.Desempilha();
                char var1 = valores.Desempilha();
                char resultado = realizaOperacao(var1, var2, op);
                valores.Empilha(resultado);
            }
            operadores.Empilha(c);
        } else {
            valores.Empilha(c);
        }
    }

    while (!operadores.Vazia()) {
        char op = operadores.Desempilha();
        char var2 = valores.Desempilha();
        char var1 = valores.Desempilha();
        char resultado = realizaOperacao(var1, var2, op);
        valores.Empilha(resultado);
    }

    return valores.Desempilha();
}

int Expressao::precedencia(char operador) {
    if (operador == '~') return 3;
    if (operador == '&') return 2;
    if (operador == '|') return 1;
    return 0;
}

int Expressao::realizaOperacao(char var1, char var2, char operador) {
    if (operador == '&') {
        return (var1 == '1' && var2 == '1') ? 1 : 0;
    } else if (operador == '|') {
        return (var1 == '1' || var2 == '1') ? 1 : 0;
    } else if (operador == '~') {
        return (var1 == '0') ? 1 : 0;
    } else {
        return 0;
    }
}

std::string Expressao::Satisfabilidade(std::string expressao, std::string valoracao){
    ArvoreBinaria possibilidades;
    possibilidades.Insere(valoracao);
    
}