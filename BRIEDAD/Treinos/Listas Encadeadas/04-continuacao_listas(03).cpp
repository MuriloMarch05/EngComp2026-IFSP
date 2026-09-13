#include <iostream>
#include <stdlib.h>
using namespace std;

struct Item{
    int Valor;
    Item *Prox;
};

struct Lista{ // Header
    Item *Inicio; // Armazena o endereço do primeiro Item.
};

Item* Criar_Item(int Valor){ // 'Item*' Significa: Essa função vai retornar um endereço de um Item.
    Item *Elemento;
    
    Elemento = (Item*) malloc(sizeof(Item)); // Aloca memória para um Item e retorna o endereço dessa memória.
    
    if (Elemento != NULL){
        Elemento->Valor = Valor; // Acesse a estrutura que Elemento aponta, entre no campo Valor e atribua o valor a ele.
        Elemento->Prox = NULL; // Acesse o campo Prox da struct apontada por Elemento e atribua NULL.
    }
    
    return Elemento;
}

Lista* Criar_Lista(){
    Lista *L;

    L = (Lista*) malloc(sizeof(Lista));

    if (L != NULL){
        L->Inicio = NULL;
    }

    return L;
}

void Inserir_Comeco(Lista *L, int Valor){
    Item *Novo;

    Novo = Criar_Item(Valor);
    
    if(Novo != NULL){
        Novo->Prox = L->Inicio;  // 1º: guarda o antigo primeiro
        L->Inicio = Novo;        // 2º: coloca Novo como primeiro
    }

}

void Inserir_Final(Lista *L, int Valor){
    Item *Novo;
    Item *Atual;

    Novo = Criar_Item(Valor);
    Atual = L->Inicio;

    if(L->Inicio == NULL){
        L->Inicio = Novo;
    }
    
    while(Atual->Prox != NULL){
        Atual = Atual->Prox;
    }
    
    Atual->Prox = Novo;
}

void Remover(Lista *L, int Valor){
    Item *Atual;
    Item *Aux;

    Aux = NULL;
    Atual = L->Inicio;
    
    while (Atual != NULL && Atual->Valor != Valor){ // "Enquanto Atual existir e o valor armazenado nele for diferente do valor que quero remover, continue andando."
        Aux = Atual; // Faço o aux guardar o endereço do atual.
        Atual = Atual->Prox; // Faço o Atual mudar para o próximo elemento.

    }

    // Opa, parou o laço. Por que?
    if (Atual == NULL){ // Nao encontrou
        cout << "Item nao encontrado." << endl;
    }

    else{ // Encontrou

        if (Atual == L->Inicio){ // É o primeiro Item da lista
            L->Inicio = Atual->Prox; // Atualizo o header, pois o primeiro item foi apagado, entao eu passo pro proximo.
            free(Atual);
        }
 
        else{ // o Item está no meio da lista

            Aux->Prox = Atual->Prox; // Pulo o elemento atual, ou seja, eu pego o proximo do proximo.
            free(Atual); 
        }
       
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int Valor;
    Lista *L;

    // Criar_LIsta() -> Preciso alocar memória para uma Lista
    L = Criar_Lista();

    Inserir_Comeco(L, 10);
    Inserir_Comeco(L, 20);
    Inserir_Comeco(L, 30);
    Inserir_Final(L, 40);

    // Criar ponteiro para armazenar o endereço do primeiro item (para que possamos percorrer depois)
    Item *Atual;
    
    Atual = L->Inicio; // Começa no primeiro Item.
    int cont=0;
    
    cout << "Antes da remocao" << endl;
    while (Atual != NULL){
        cout << "Item[" << cont+1 << "]: "<< Atual->Valor << endl; // Mostra o Item atual
        Atual = Atual->Prox; // Vai para o próximo Item
        cont++; // Contador para ver qual item estamos.
    }

    Remover(L, 30);
    cout << "Depois da remocao" << endl;

    Atual = L->Inicio; // Atualiza o atual
    cont = 0; // Reseta o contador;
    while (Atual != NULL){
        cout << "Item[" << cont+1 << "]: "<< Atual->Valor << endl; // Mostra o Item atual
        Atual = Atual->Prox; // Vai para o próximo Item
        cont++; // Contador para ver qual item estamos.
    }


    return 0;
}