// 1 - Inverter Fila: Crie uma função que receba uma fila e a inverta, utilizando uma pilha como estrutura auxiliar.
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;

// Estrutura de FILAS
struct Elemento{
    int dado;
    Elemento *prox;
};

struct Fila{
    Elemento *Inicio;
    Elemento *Fim;
    int Total;
};

void Ini_Fila(Fila *F){
    F->Inicio = NULL;
    F->Fim = NULL;
    F->Total = 0;
}

bool Fila_Vazia(Fila *F){
    return(F->Inicio == NULL);
}

Elemento *Criar_Elemento(int valor){
    Elemento *Ret;

    Ret = (Elemento*) malloc(sizeof(Elemento));
    if(Ret != NULL){
        Ret->dado = valor;
        Ret->prox = NULL;
    }

    return Ret;
}

void Enfileirar(Fila *F, int valor){
    Elemento *ptE;

    ptE = Criar_Elemento(valor);

    if(ptE != NULL){
        if(Fila_Vazia(F)){
            F->Inicio = ptE;
        }
        else{
            F->Fim->prox = ptE;
        }

        F->Fim = ptE;
        ++F->Total;
    }

}

Elemento * Desenfileirar(Fila *F){
	Elemento *Ret = NULL;
	
	if (!Fila_Vazia(F)){
		Ret = F->Inicio;
		if (F->Inicio == F->Fim) {
			//1 elemento
			F->Inicio = NULL;
			F->Fim = NULL;
		}
		else{
			//Mais de 1 elemento
			F->Inicio = F->Inicio->prox;
		}
		--F->Total;			
	}
	
	return Ret;
}

// Estruturas de PILHAS
struct Pilha{
    Elemento *topo;
    int Total;
};

void Ini_Pilha(Pilha *P){
    P->topo = NULL;
    P->Total = 0;
}

bool Pilha_Vazia(Pilha *P){
    return(P->topo == NULL);
}

void Empilhar(Pilha *P, int valor){
    Elemento *ptE;

    ptE = Criar_Elemento(valor);
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

// Impressão
void Imprimir(Elemento *E){
	Elemento *Aux = E;
	
	while (Aux != NULL){
        cout << Aux->dado << ", ";

        Aux = Aux->prox;
    }

    cout << endl;
}
void InverterFila(Fila *F) {
    Pilha P;
    Ini_Pilha(&P);
    
    Elemento*elem; // Ponteiro para guardar o elemento temporariamente
    
    // Primeiro : Da Fila para a Pilha
    while (!Fila_Vazia(F)) {
        elem = Desenfileirar(F);      // Tira da frente da fila
        Empilhar(&P, elem->dado);     // Joga o dado no topo da pilha
        free(elem);                   // Libera o nó da fila (a pilha criará o seu próprio nó)
    }
    
    // Segundo: Da Pilha de volta para a Fila
    while (!Pilha_Vazia(&P)) {
        Elemento *aux = Desempilhar(&P); // Tira do topo da pilha
        Enfileirar(F, aux->dado);             // Joga no fim da fila
        free(aux);                            // Libera o nó da pilha
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    Fila F;
    Ini_Fila(&F);

    Enfileirar(&F, 10);
    Enfileirar(&F, 20);
    Enfileirar(&F, 30);

    cout << "Fila original:" << endl;
    Imprimir(F.Inicio);

    InverterFila(&F);

    cout << "Fila invertida:" << endl;
    Imprimir(F.Inicio);

    return 0;
}