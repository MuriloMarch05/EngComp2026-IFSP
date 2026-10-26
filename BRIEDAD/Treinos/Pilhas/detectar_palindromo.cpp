// Atividade 5: Detector de Palíndromos. Receba uma palavra (ex: "ARARA") e verifique se ela é um palíndromo (lê-se igual da esquerda para a direita e vice-versa).

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

// ============================================
//             Estruturas básicas
// ============================================

struct Elemento{
    char item;
    Elemento *prox;
};
struct Pilha{
    Elemento *topo;
    int total;
};

// ============================================
//               Funções básicas
// ============================================

void ini_pilha(Pilha *P){
    P->topo = NULL;
    P->total = 0;
}

bool pilha_vazia(Pilha *P){
    return (P->topo == NULL);
}

Elemento *criar_elemento(char C){
    Elemento *aux;

    aux = (Elemento*) malloc(sizeof(Elemento));

    if(aux != NULL){
        aux->item = C;
        aux->prox = NULL;
    }

    return aux;
}

void Empilhar(Pilha *P, char C){
    Elemento *ptE;

    ptE = criar_elemento(C);
    if (ptE != NULL){
        ptE->prox = P->topo;
        P->topo = ptE;
        ++P->total;
    }
}

Elemento *desempilhar(Pilha *P){
    Elemento *ret;

    ret = NULL;

    if(!pilha_vazia(P)){
        ret = P->topo;
        P->topo = P->topo->prox;
        --P->total;
    }

    return ret;
}

void imprimir(Pilha *P){
    Elemento *aux;

    aux = P->topo;

    while(aux != NULL){

        cout << aux->item << ", ";

        aux = aux->prox;
    }
}

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


bool verificar_palindromo(Pilha *P, Fila *F){
    bool eh_palindromo = 1;

    while (!pilha_vazia(P) && !Fila_vazia(F) && eh_palindromo){
        if(desempilhar(P)->item != Desenfileirar(F)->item){
            eh_palindromo = 0;
        }
    }

    return eh_palindromo;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    string palavra;
    Pilha P;
    Fila F;
    
    ini_pilha(&P);
    Ini_fila(&F);

    cout << "=== VERIFICAR PALINDROMO ===" << endl;
    cout << "Digite uma palavra: ";
    getline(cin, palavra);

    for(int i = 0; palavra[i] != '\0'; i++){
        Empilhar(&P, palavra[i]);
        Enfileirar(&F, palavra[i]);
    }

    if(verificar_palindromo(&P, &F)){
    cout << "A palavra: " << palavra << " -> é palíndromo!" << endl;
    }
    else{
        cout << "Não é palíndromo." << endl;
    }
    
    return 0;
}