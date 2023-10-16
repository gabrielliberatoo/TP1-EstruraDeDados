#ifndef ARVOREBINARIA_HPP
#define ARVOREBINARIA_HPP

#include "TipoNo.hpp"
#include "Expressao.hpp"
#include <string>


class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(std::string item);
    void Limpa();
    void insereFolha(TipoNo *raiz);
    TipoNo* getRaiz(){
        return raiz;
    }
    std::string Satisfabilidade();
    std::string GerarValoracoes(const std::string& expressao, const std::string& variaveis, const std::string& valoracao);
    bool encontraValoracaoSatisfatoria(TipoNo *p, std::string &valoração);

private:
    void InsereRecursivo(TipoNo *&p, std::string item);
    void ApagaRecursivo(TipoNo *p);
    TipoNo *raiz;
};

#endif