#include "Pilha.hpp"
#include <string>

PilhaEncadeada::PilhaEncadeada()
{
    topo = NULL;
    tamanho = 0;
}

PilhaEncadeada::~PilhaEncadeada()
{
    Limpa();
}

void PilhaEncadeada::Empilha(std::string item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};

std::string PilhaEncadeada::Desempilha()
{
    std::string aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "A pilha está vazia!";

    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;
    return aux;
};

void PilhaEncadeada::Limpa()
{
    while (!Vazia())
        Desempilha();
}