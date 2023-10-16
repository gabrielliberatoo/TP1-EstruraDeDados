#include "TipoNo.hpp"
#include "Pilha.hpp"
#include <string>

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(std::string item);
    void Caminha(int tipo);
    void Limpa();
    void insereFolha(TipoNo *raiz);
    TipoNo* getRaiz(){
        return raiz;
    }
    std::string Satisfabilidade();

private:
    void InsereRecursivo(TipoNo *&p, std::string item);
    void ApagaRecursivo(TipoNo *p);
    void PosOrdem(TipoNo *p);
    TipoNo *raiz;
};