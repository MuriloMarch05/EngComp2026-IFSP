// 2 - Conversor Decimal-Binário: Implemente um algoritmo que receba um número decimal e, utilizando uma pilha dinâmica, converta-o para binário.

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Binario{
    int num;
    Binario *prox;
};

struct Pilha{
    Binario *topo;
    int Total;
};

void ini_pilha(Pilha *P){
    P->topo = NULL;
    P->Total = 0;
}

bool pilha_vazia(Pilha *P){
    return(P->topo == NULL);
}

Binario *criar_binario(int num){
    Binario *Ret;

    Ret = (Binario*) malloc(sizeof(Binario));
    if(Ret != NULL){
        Ret->num = num;
        Ret->prox = NULL;
    }

    return Ret;
}

void empilhar(Pilha *P, int num){
    Binario *ptB;

    ptB = criar_binario(num);
    if (ptB != NULL){
        if(!pilha_vazia(P)){
            ptB->prox = P->topo;
        }

        P->topo = ptB;
        ++P->Total;
    }
}

Binario *desempilhar(Pilha *P){
    Binario *Ret;

    Ret = NULL;

    if(!pilha_vazia(P)){
        Ret = P->topo;
        P->topo = P->topo->prox;
        --P->Total;
    }

    return Ret;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    Pilha P;
    int numero, resto;

    cout << "CONVERSOR DECIMAL-BINARIO" << endl;
    cout << "Digite um valor em decimal: ";
    cin >> numero;

    if(numero == 0){
        cout << "EM BINÁRIO: " << numero << endl;
    }

    else{
            ini_pilha(&P);
        
            while(numero != 0){
                resto = numero % 2;
                empilhar(&P, resto);
                numero = numero / 2;
            }
        
            cout << "EM BINÁRIO: ";
            while(!pilha_vazia(&P)){
                Binario *Aux = desempilhar(&P);
                cout << Aux->num;
                free(Aux);
            }
            cout << endl;
    }

    return 0;
}