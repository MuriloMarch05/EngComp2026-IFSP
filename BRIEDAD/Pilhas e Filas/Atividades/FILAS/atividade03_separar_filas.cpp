/*3 - Separar Fila: Implemente uma função que receba uma fila F1 e um valor n. A função
deve dividir a fila original em duas: F1 contendo os elementos até n, e F2 contendo os
elementos após n. As duas filas devem ser retornadas através de parâmetros por referência
para que o Main() consiga imprimi-las.*/

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Documento {
    string nome;
    int tempo;
    Documento *prox;
};

struct Fila {
    Documento *inicio;
    Documento *fim;
    int Total;
};

void ini_fila(Fila *F) {
    F->inicio = NULL;
    F->fim = NULL;
    F->Total = 0;
}

bool fila_vazia(Fila *F) {
    return (F->inicio == NULL);
}

Documento *Criar_Documento(string nome, int tempo) {
    Documento *Ret = (Documento*) malloc(sizeof(Documento));
    if (Ret != NULL) {
        Ret->nome = nome;
        Ret->tempo = tempo;
        Ret->prox = NULL;
    }
    return Ret;
}

void Enfileirar(Fila *F, string nome, int tempo) {
    Documento *ptD = Criar_Documento(nome, tempo);
    if (ptD != NULL) {
        if (fila_vazia(F)) {
            F->inicio = ptD;
        } else {
            F->fim->prox = ptD;
        }
        F->fim = ptD;
        ++F->Total;
    }
}

Documento *Desenfileirar(Fila *F) {
    Documento *Ret = NULL;
    if (!fila_vazia(F)) {
        Ret = F->inicio;
        if (F->inicio == F->fim) {
            F->inicio = NULL;
            F->fim = NULL;
        } else {
            F->inicio = F->inicio->prox;
        }
        --F->Total;
    }
    return Ret;
}

// separa a fila F1 em duas, baseada na quantidade n de elementos
void SepararFila(Fila *F1, Fila *F2, int n) {
    ini_fila(F2);
    
    int total_original = F1->Total; // Salva o tamanho inicial para controlar o loop
    int cont = 0;

    while (cont < total_original) {
        Documento *doc = Desenfileirar(F1);
        
        if (doc != NULL) {
            if (cont < n) {
                Enfileirar(F1, doc->nome, doc->tempo); // Retorna para F1
            } else {
                Enfileirar(F2, doc->nome, doc->tempo); // Vai para F2
            }
            free(doc); // Libera o nó temporário (Enfileirar já criou um novo)
            cont++;
        }
    }
}

void ImprimirFila(Fila *F, string nome_fila) {
    cout << "--- " << nome_fila << " ---" << endl;
    if (fila_vazia(F)) {
        cout << "Fila vazia." << endl;
    } else {
        Documento *Aux = F->inicio;
        while (Aux != NULL) {
            cout << "Arquivo: " << Aux->nome << " | Tempo: " << Aux->tempo << "s" << endl;
            Aux = Aux->prox;
        }
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Fila F1, F2;
    ini_fila(&F1);
    
    // Populando a fila original com 5 elementos
    Enfileirar(&F1, "Doc_A.pdf", 5);
    Enfileirar(&F1, "Doc_B.jpg", 2);
    Enfileirar(&F1, "Doc_C.docx", 10);
    Enfileirar(&F1, "Doc_D.txt", 3);
    Enfileirar(&F1, "Doc_E.xlsx", 7);

    cout << "FILA ORIGINAL (F1):" << endl;
    ImprimirFila(&F1, "Antes da separacao");

    int n = 3; // Os 3 primeiros ficam em F1, o resto vai para F2
    SepararFila(&F1, &F2, n);

    cout << "APOS SEPARACAO (n = " << n << "):" << endl;
    ImprimirFila(&F1, "Fila F1 (primeiros " + to_string(n) + " elementos)");
    ImprimirFila(&F2, "Fila F2 (elementos restantes)");

    // Limpeza de memória final
    while (!fila_vazia(&F1)) free(Desenfileirar(&F1));
    while (!fila_vazia(&F2)) free(Desenfileirar(&F2));

    return 0;
}