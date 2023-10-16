#ifndef TIPONO_HPP
#define TIPONO_HPP
#include <string>

class TipoNo
{
public:
    TipoNo(std::string expressao){
        item = expressao;
        esq = NULL;
        dir = NULL;
    }

private:
    std::string item;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

#endif