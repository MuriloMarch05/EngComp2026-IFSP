#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <clocale>
using namespace std;

struct Elemento{
    char item;
    Elemento *prox;
};

struct Fila{
    Elemento *Inicio;
    Elemento *Fim;
    int Total;
};

void Ini_fila(Fila *F){
    F->Inicio = NULL;
    F->Fim = NULL;
    F->Total = 0;
}

bool Fila_vazia(Fila *F){
    return(F->Inicio == NULL);
}

Elemento *Criar_elemento(char C){
    Elemento *Ret;

    Ret = (Elemento*) malloc(sizeof(Elemento));

    if(Ret != NULL){
        Ret->item = C;
        Ret->prox = NULL;
    }

    return Ret;
}

void Enfileirar(Fila *F, char C){
    Elemento *ptE;

    ptE = Criar_elemento(C);
    if(ptE != NULL){
        if(Fila_vazia(F)){
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
	
	if (!Fila_vazia(F)){
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