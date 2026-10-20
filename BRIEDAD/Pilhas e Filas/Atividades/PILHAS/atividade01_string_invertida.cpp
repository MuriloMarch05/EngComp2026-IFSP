// 1 -Inverter String: Utilize uma pilha dinâmica para ler uma string e exibi-la de trás para frente.

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct String{
    char caracteres;
    String *prox;
};

struct Pilha{
    String *topo;
    int Total;
};

void ini_pilha(Pilha *P){
    P->topo = NULL;
    P->Total = 0;
}

bool Pilha_Vazia(Pilha *P){
    return (P->topo == NULL);
}

String *Criar_String(char caracteres){
    String *Ret;

    Ret = (String*) malloc(sizeof(String));
    if(Ret != NULL){
        Ret->caracteres = caracteres;
        Ret->prox = NULL;
    }

    return Ret;
}
void Empilhar(Pilha *P, char caracteres){
    String *ptS;

    ptS = Criar_String(caracteres);
    if(ptS != NULL){
        if (!Pilha_Vazia(P)){
            ptS->prox = P->topo;
        }

        P->topo = ptS;
        ++P->Total;
    }
}

String *Desempilhar(Pilha *P){
    String *Ret;

    Ret = NULL;

    if(!Pilha_Vazia(P)){
        Ret = P->topo;
        P->topo = P->topo->prox;
        --P->Total;
    }

    return Ret;
}
void imprimir(Pilha *P){
    String *Aux;

    Aux = P->topo;

    cout << "O INVERSO É:"<< endl;
    while(Aux != NULL){
        cout << Aux->caracteres << ", ";
        Aux = Aux->prox;
    }
    cout << endl;
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    Pilha P;
    string frase;

    cout << "Digite uma palavra/frase para vê-la ao contrário: ";
    getline(cin, frase);

    ini_pilha(&P);

    // Como no C++ a string é um vetor de caracteres, percorremos até o \0, que sinaliza o final.
    for(int i = 0; frase[i]!='\0'; i++){
        Empilhar(&P, frase[i]); // Empilha cada caractere, separadamente
    }
    cout << "Quantidade de caracteres: " << P.Total << endl; // Apenas para verificar.

    // Apenas mostra a pilha, que já é o inverso.
    // imprimir(&P);
    
    // Aqui, a gente desempilha e imprime o que foi desempilhado. Depois liberamos a memória de cada caractere.

    cout << "O INVERSO É: ";
    while(!Pilha_Vazia(&P)){
        String *aux = Desempilhar(&P);
        cout << aux->caracteres;
        free(aux);
    }
    cout << endl;

    return 0;
}