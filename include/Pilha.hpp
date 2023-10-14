

struct TipoCelula{
public:
    TipoCelula();

private:
    char item;
    TipoCelula *prox;
    friend class PilhaEncadeada;
};

class PilhaEncadeada
{
public:
    PilhaEncadeada();
    virtual ~PilhaEncadeada();
    void Empilha(char item);
    char Desempilha();
    void Limpa();
    bool Vazia() const {
        return topo == nullptr;
    }
    char ItemNoTopo() const {
    if (topo != nullptr) {
        return topo->item;
    } else {
        return ' ';
    }
}

private:
    TipoCelula *topo;
    int tamanho;

    friend class Expressao;
};