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
        p = new TipoNo(item);
    }
    else
    {
        size_t pos = p->item.find("e");
        if (pos != std::string::npos)
        {
            TipoNo *NoEsq = new TipoNo(p->item);
            NoEsq->item[pos] = '0';
            InsereRecursivo(p->esq, NoEsq->item);

            TipoNo *NoDir = new TipoNo(p->item);
            NoDir->item[pos] = '1';
            InsereRecursivo(p->dir, NoDir->item);
        }
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