#include "Pilha.hpp"

PilhaEncadeada::PilhaEncadeada()
{
    topo = NULL;
    tamanho = 0;
}

PilhaEncadeada::~PilhaEncadeada()
{
    Limpa();
}

void PilhaEncadeada::Empilha(char item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};

char PilhaEncadeada::Desempilha()
{
    char aux;
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