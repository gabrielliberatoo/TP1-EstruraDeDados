#include "TipoNo.hpp"
#include <string>

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(std::string item);
    void Caminha(int tipo);
    void Limpa();

private:
    void InsereRecursivo(TipoNo *&p, std::string item);
    void ApagaRecursivo(TipoNo *p);
    void PreOrdem(TipoNo *p);
    void InOrdem(TipoNo *p);
    void PosOrdem(TipoNo *p);
    TipoNo *raiz;
};