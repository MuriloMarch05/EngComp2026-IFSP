/*2 - Gerenciador de Impressão: Simule uma fila de impressora. A estrutura da fila deve
receber nomes de documentos e tempo de impressão, removendo-os na ordem de
chegada.*/
#include <iostream>
#include<stdlib.h>
#include <string>
using namespace std;

struct Documento{
    string nome;
    int tempo;
    Documento *prox;
};

struct Fila{
    Documento *inicio;
    Documento *fim;
    int Total;
};

void ini_fila(Fila *F){
    F->inicio = NULL;
    F->fim = NULL;
    F->Total = 0;
}

bool fila_vazia(Fila *F){
    return(F->inicio == NULL);
}

Documento *Criar_Documento(string nome, int tempo){
    Documento *Ret;

    Ret = (Documento*) malloc(sizeof(Documento));

    if(Ret != NULL){
        Ret->nome = nome;
        Ret->tempo = tempo;
        Ret->prox = NULL;
    }
    return Ret;
}

void Enfileirar(Fila *F, string nome, int tempo){
    Documento *ptD;

    ptD = Criar_Documento(nome, tempo);

    if(ptD != NULL){
        if(fila_vazia(F)){
            F->inicio = ptD;
        }
        else{
            F->fim->prox = ptD;
        }

        F->fim = ptD;
        ++F->Total;
    }
}

Documento *Desenfileirar(Fila *F){
    Documento *Ret;

    Ret = NULL;

    if (!fila_vazia(F)){
        Ret = F->inicio;
        if (F->inicio == F->fim){ // Se o começo também for o fim, ou seja, 1 elemento
            F->inicio = NULL;
            F->fim = NULL;
        }
        else{ // Se não, se tiver mais de um elemento
            F->inicio = F->inicio->prox;
        }
        --F->Total;
    }

    return Ret;

}

/*void imprimir(Documento *D){
    Documento *Aux;

    Aux = D;

    while (Aux != NULL){
        cout <<"Arquivo: "<< Aux->nome << ": " << "| Impresso em: " <<Aux->tempo << endl;
        Aux = Aux->prox;
    }
    cout << endl;
}*/

int main() {
    setlocale(LC_ALL, "Portuguese");
    Fila F;
    ini_fila(&F);

    // 1. Simular chegada de documentos na impressora
    Enfileirar(&F, "Trabalho_ED.pdf", 5);
    Enfileirar(&F, "Foto_Ferias.jpg", 2);
    Enfileirar(&F, "Relatorio_Final.docx", 10);

    cout << "--- INICIANDO PROCESSAMENTO DA IMPRESSORA ---" << endl;

    // 2. Processar a fila até ela ficar vazia
    while (!fila_vazia(&F)) {
        Documento *docAtual = Desenfileirar(&F);
        
        cout <<"Arquivo: "<< docAtual->nome << ": " << "| Impresso em: " <<docAtual->tempo << endl;
        
        free(docAtual); // não esquecer de limpar a memória
    }

    cout << "--- TODOS OS DOCUMENTOS FORAM IMPRESSOS ---" << endl;
    return 0;
}