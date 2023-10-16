#include "Expressao.hpp"

std::string Expressao::AtribuiValor(std::string expressao, std::string valoracao)
{
    std::string expressaoAtualizada = expressao;
    for (std::string::size_type i = 0; i < valoracao.length(); i++)
    {
        for (std::string::size_type j = 0; i < valoracao.length(); j++)
        {
            if (expressao[j] == static_cast<char>('0' + i))
            {
                expressaoAtualizada[j] = valoracao[i];
            }
        }
    }
    return expressaoAtualizada;
}

int Expressao::AvaliaExpressao(std::string expressao, std::string valoracao)
{
    PilhaEncadeada operadores;
    PilhaEncadeada valores;
    std::string expreValor = AtribuiValor(expressao, valoracao);

    for (char c : expreValor)
    {
        if (c == ' ')
        {
            continue;
        }

        if (c == '(')
        {
            operadores.Empilha(c);
        }
        else if (c == ')' && !operadores.Vazia())
        {
            while (operadores.ItemNoTopo() != '(')
            {
                char op = operadores.Desempilha();
                char var2 = valores.Desempilha();
                char var1 = valores.Desempilha();
                char resultado = realizaOperacao(var1, var2, op);
                valores.Empilha(resultado);
            }
            operadores.Desempilha();
        }
        else if (c == '~' || c == '&' || c == '|')
        {
            while (!operadores.Vazia() && precedencia(c) <= precedencia(operadores.ItemNoTopo()))
            {
                char op = operadores.Desempilha();
                char var2 = valores.Desempilha();
                char var1 = valores.Desempilha();
                char resultado = realizaOperacao(var1, var2, op);
                valores.Empilha(resultado);
            }
            operadores.Empilha(c);
        }
        else
        {
            valores.Empilha(c);
        }
    }

    while (!operadores.Vazia())
    {
        char op = operadores.Desempilha();
        char var2 = valores.Desempilha();
        char var1 = valores.Desempilha();
        char resultado = realizaOperacao(var1, var2, op);
        valores.Empilha(resultado);
    }

    return valores.Desempilha();
}

int Expressao::precedencia(char operador)
{
    if (operador == '~')
        return 3;
    if (operador == '&')
        return 2;
    if (operador == '|')
        return 1;
    return 0;
}

int Expressao::realizaOperacao(char var1, char var2, char operador)
{
    if (operador == '&')
    {
        return (var1 == '1' && var2 == '1') ? 1 : 0;
    }
    else if (operador == '|')
    {
        return (var1 == '1' || var2 == '1') ? 1 : 0;
    }
    else if (operador == '~')
    {
        return (var1 == '0') ? 1 : 0;
    }
    else
    {
        return 0;
    }
}


