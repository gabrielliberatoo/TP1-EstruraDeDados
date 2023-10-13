#include <string>

class TipoNo
{
public:
    TipoNo(){
        item = "-1";
        esq = NULL;
        dir = NULL;
    }

private:
    std::string item;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};