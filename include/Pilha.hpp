#include <string>

struct TipoCelula{
public:
    TipoCelula();

private:
    std::string item;
    TipoCelula *prox;
    friend class PilhaEncadeada;
};

class PilhaEncadeada
{
public:
    PilhaEncadeada();
    virtual ~PilhaEncadeada();
    void Empilha(std::string item);
    std::string Desempilha();
    void Limpa();
    bool Vazia() const {
        return topo == nullptr;
    }

private:
    TipoCelula *topo;
    int tamanho;
};