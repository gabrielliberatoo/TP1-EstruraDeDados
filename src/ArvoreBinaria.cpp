#include "ArvoreBinaria.hpp"


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
        size_t pos = p->item.find("e"||"a");
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


std::string ArvoreBinaria::GerarValoracoes(const std::string& expressao, const std::string& variaveis, const std::string& valoracao) {
    Expressao obj;
    if (variaveis.empty()) {
        int resultado = obj.AvaliaExpressao(expressao, valoracao);
        return resultado == 1 ? valoracao : "";
    }

    char primeiraVar = variaveis[0];
    std::string restanteVariaveis = variaveis.substr(1);

    std::string valoracaoComZero = valoracao + primeiraVar + "=0, ";
    std::string valoracaoComUm = valoracao + primeiraVar + "=1, ";

    std::string resultadoComZero = GerarValoracoes(expressao, restanteVariaveis, valoracaoComZero);
    std::string resultadoComUm = GerarValoracoes(expressao, restanteVariaveis, valoracaoComUm);

    return resultadoComZero + resultadoComUm;
}



std::string ArvoreBinaria::Satisfabilidade() {
    std::string valoraçãoSatisfatória = "";
    bool existeValoraçãoSatisfatória = encontraValoracaoSatisfatoria(raiz, valoraçãoSatisfatória);

    if (existeValoraçãoSatisfatória) {
        return "1 " + valoraçãoSatisfatória;
    } else {
        return "0";
    }
}

bool ArvoreBinaria::encontraValoracaoSatisfatoria(TipoNo *p, std::string &valoração) {
    if (p == nullptr) {
        return true; 
    }

    
    std::string variavel = p->item;

   
    if (variavel[0] == 'e') { 
        for (char valor : {'0', '1'}) {
            valoração += valor;
            if (encontraValoracaoSatisfatoria(p->esq, valoração)) {
                return true; 
            }
            valoração.pop_back(); 
        }
    } else if (variavel[0] == 'a') { 
        for (char valor : {'0', '1'}) {
            valoração += valor;
            if (!encontraValoracaoSatisfatoria(p->esq, valoração)) {
                return false; 
            }
            valoração.pop_back(); 
        }
    }

    return false; 
}
