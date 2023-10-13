#include "ArvoreBinaria.hpp"
#include <string.h>

ArvoreBinaria::ArvoreBinaria()
{
    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
    Limpa();
}

void ArvoreBinaria::Insere(std::string item)
{
    InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo *&p, std::string item)
{
    if (p == NULL)
    {
        p = new TipoNo();
        p->item = item;
    }
    else
    {
        if (item < p->item)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::PreOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        p->item;
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::InOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        InOrdem(p->esq);
        p->item;
        InOrdem(p->dir);
    }
}

void ArvoreBinaria::PosOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        p->item;
    }
}

void ArvoreBinaria::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = NULL;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
    if (p != NULL)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}