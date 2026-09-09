#include <iostream>
#include <cstring>
#include <clocale>

using namespace std;

// ======================================================
// ESTRUTURA DA OCORRÊNCIA
// ======================================================

struct Ocorrencia {
    int Codigo;
    char Descricao[20];
    Ocorrencia *prox;
};

// ======================================================
// HEADER DA LISTA
// ======================================================

struct Lista {
    Ocorrencia *inicio;
    int Total;
};

// ======================================================
// INICIALIZAÇÃO DA LISTA
// ======================================================

void inicializar(Lista *L) {
    L->inicio = NULL;
    L->Total = 0;
}

// ======================================================
// VERIFICA SE A LISTA ESTÁ VAZIA
// ======================================================

bool Lista_vazia(Lista *L) {
    return (L->inicio == NULL);
}

// ======================================================
// CRIA UMA NOVA OCORRÊNCIA
// ======================================================

Ocorrencia *Cria_Ocorrencia(int Codigo, const char *Desc) {

    Ocorrencia *Ret = new Ocorrencia;

    Ret->Codigo = Codigo;

    // Copia a descrição com segurança
    strncpy(Ret->Descricao, Desc, sizeof(Ret->Descricao) - 1);
    Ret->Descricao[sizeof(Ret->Descricao) - 1] = '\0';

    Ret->prox = NULL;

    return Ret;
}

// ======================================================
// INSERE OCORR�NCIA NO INÍCIO DA LISTA
// ======================================================

void Insere_ocorrencia(Lista *L, int Codigo, const char *Desc) {

    Ocorrencia *ptO;

    ptO = Cria_Ocorrencia(Codigo, Desc);

    if (ptO != NULL) {

        // O novo elemento aponta para o antigo início
        ptO->prox = L->inicio;

        // O novo elemento passa a ser o início
        L->inicio = ptO;

        // Atualiza a quantidade de elementos
        ++L->Total;
    }
}

// ======================================================
// REMOVE UMA OCORRÊNCIA PELO CÓDIGO
// ======================================================

void Remover(Lista *L, int Codigo) {

    Ocorrencia *ptO;
    Ocorrencia *aux;

    // Se a lista estiver vazia, n�o h� nada para remover
    if (Lista_vazia(L)) {
        return;
    }

    // --------------------------------------------------
    // CASO 1: o elemento a remover é o primeiro
    // --------------------------------------------------

    if (L->inicio->Codigo == Codigo) {

        aux = L->inicio;

        // O segundo elemento passa a ser o primeiro
        L->inicio = L->inicio->prox;

        delete aux;

        --L->Total;

        return;
    }

    // --------------------------------------------------
    // CASO 2: o elemento está no meio ou no final
    // --------------------------------------------------

    ptO = L->inicio;

    // Procura o elemento ANTERIOR ao que será removido
    while (ptO->prox != NULL &&
           ptO->prox->Codigo != Codigo) {

        ptO = ptO->prox;
    }

    // Verifica se encontrou o elemento
    if (ptO->prox != NULL) {

        aux = ptO->prox;

        // Faz a ligação "pular" o elemento removido
        ptO->prox = aux->prox;

        delete aux;

        --L->Total;
    }
}

// ======================================================
// BUSCA UMA OCORRÊNCIA PELO CÓDIGO
// ======================================================

Ocorrencia *Buscar(Lista *L, int Codigo) {

    Ocorrencia *ptO;

    for (ptO = L->inicio;
         ptO != NULL;
         ptO = ptO->prox) {

        if (ptO->Codigo == Codigo) {
            return ptO;
        }
    }

    // N�o encontrou
    return NULL;
}

// ======================================================
// IMPRIME A LISTA
// ======================================================

void Imprimir(Ocorrencia *V) {

    Ocorrencia *ptO;

    for (ptO = V;
         ptO != NULL;
         ptO = ptO->prox) {

        cout << ptO->Codigo
             << " (" << ptO->Descricao << ")"
             << endl;
    }
}

// ======================================================
// CONTA OS ELEMENTOS DA LISTA
// ======================================================

int Contar_Elementos(Ocorrencia *V) {

    Ocorrencia *ptO;
    int Total = 0;

    for (ptO = V;
         ptO != NULL;
         ptO = ptO->prox) {

        ++Total;
    }

    return Total;
}

// ======================================================
// LIBERA TODA A MEMÓRIA DA LISTA
// ======================================================

void Liberar_Lista(Lista *L) {

    Ocorrencia *aux;

    while (L->inicio != NULL) {

        aux = L->inicio;

        L->inicio = L->inicio->prox;

        delete aux;
    }

    L->Total = 0;
}

// ======================================================
// PROGRAMA PRINCIPAL
// ======================================================

Lista Lst;

int main() {

    setlocale(LC_ALL, "Portuguese");

    // Inicializa a lista
    inicializar(&Lst);

    // --------------------------------------------------
    // INSERÇÕES
    // --------------------------------------------------

    Insere_ocorrencia(&Lst, 1, "Buraco");
    Insere_ocorrencia(&Lst, 2, "Iluminacao");
    Insere_ocorrencia(&Lst, 3, "Acidente");
    Insere_ocorrencia(&Lst, 4, "Buraco 2");
    Insere_ocorrencia(&Lst, 5, "Iluminacao 2");
    Insere_ocorrencia(&Lst, 6, "Acidente 2");

    // --------------------------------------------------
    // IMPRIME A LISTA
    // --------------------------------------------------

    cout << "===== LISTA ORIGINAL =====" << endl;

    Imprimir(Lst.inicio);

    cout << "\nTotal: "
         << Lst.Total
         << endl;

    // --------------------------------------------------
    // BUSCA
    // --------------------------------------------------

    Ocorrencia *ptO;

    ptO = Buscar(&Lst, 4);

    if (ptO != NULL) {

        cout << "\nOcorrencia encontrada: "
             << ptO->Codigo
             << " - "
             << ptO->Descricao
             << endl;

    } else {

        cout << "\nOcorrencia nao encontrada!"
             << endl;
    }

    // --------------------------------------------------
    // REMOÇÃO
    // --------------------------------------------------

    cout << "\n===== REMOVENDO CODIGO 4 ====="
         << endl;

    Remover(&Lst, 4);

    Imprimir(Lst.inicio);

    cout << "\nTotal: "
         << Lst.Total
         << endl;

    // --------------------------------------------------
    // TESTE: REMOVER O PRIMEIRO
    // --------------------------------------------------

    cout << "\n===== REMOVENDO CODIGO 6 ====="
         << endl;

    Remover(&Lst, 6);

    Imprimir(Lst.inicio);

    cout << "\nTotal: "
         << Lst.Total
         << endl;

    // --------------------------------------------------
    // TESTE: REMOVER O ÚLTIMO
    // --------------------------------------------------

    cout << "\n===== REMOVENDO CODIGO 1 ====="
         << endl;

    Remover(&Lst, 1);

    Imprimir(Lst.inicio);

    cout << "\nTotal: "
         << Lst.Total
         << endl;

    // --------------------------------------------------
    // CONTAGEM
    // --------------------------------------------------

    cout << "\nQuantidade contada pela funcao: "
         << Contar_Elementos(Lst.inicio)
         << endl;

    // --------------------------------------------------
    // LIBERA MEMÓRIA
    // --------------------------------------------------

    Liberar_Lista(&Lst);

    return 0;
}
