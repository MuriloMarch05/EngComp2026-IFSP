#include <iostream>
#include <string.h>
using namespace std;

// Criar o novo tipo de dado
struct Elemento{
    char Item;
    Elemento *prox;
};

// Estrutura da pilha, temos um ponteiro que aponta para o topo e um contador.
struct Pilha{
    Elemento *topo;
    int Total;
};

// Análogo a listas encadeadas, função que inicia a pilha vazia.
void Ini_Pilha(Pilha *P){
    P->topo = NULL;
    P->Total = 0;
}

// Verificamos se ela está realmente vazia. 1 - Sim, 0 - não
bool Pilha_Vazia(Pilha *P){
    return (P->topo == NULL);
}

// Função para criar e alocar memória para cada Elemento.
Elemento *Criar_Elemento(char C){
    Elemento *Ret;

    Ret = (Elemento*) malloc(sizeof(Elemento));

    if (Ret != NULL){
        Ret->Item = C;
        Ret->prox = NULL;
    }

    return Ret;
}

// Função de impressão
void Imprimir(Elemento *E){
    Elemento *Aux;

    cout << endl << "IMPRESSAO" << endl;
    for (Aux = E; Aux!=NULL; Aux = Aux->prox){
        cout << Aux->Item;

        if(Aux->prox != NULL){
            cout << ", ";
        }
    }

    cout << endl;
}
// LIFO - Last In, First Out
// Último a entrar, primeiro a sair
void Empilhar(Pilha *P, char C){
    Elemento *ptE;

    ptE = Criar_Elemento(C);
    if(ptE != NULL){
        if(!Pilha_Vazia(P)){
            // Atualiza o fim
            ptE->prox = P->topo;
        }

        P->topo = ptE;
        ++P->Total;
    }
}

Elemento *Desempilhar(Pilha *P){
    Elemento *Ret = NULL;

    if(!Pilha_Vazia(P)){
        Ret = P->topo;
        P->topo = P->topo->prox;
        --P->Total;
    }

    return Ret;
}

Pilha P;
Elemento *E;
int main(){
    setlocale(LC_ALL, "Portuguese");

    Ini_Pilha(&P);
    Empilhar(&P, '3');
    Empilhar(&P, '2');
    Empilhar(&P, '1');
    
    Imprimir(P.topo);

    return 0;
}