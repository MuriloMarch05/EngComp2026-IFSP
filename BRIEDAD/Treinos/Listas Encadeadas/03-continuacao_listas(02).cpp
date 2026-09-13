#include <iostream>
#include <stdlib.h>
using namespace std;

struct Item{
    int Valor;
    Item *Prox;
};

Item* Criar_Item(int Valor){ // 'Item*' Significa: Essa função vai retornar um endereço de um Item.
    Item *Elemento;

    Elemento = (Item*) malloc(sizeof(Item));

    if (Elemento != NULL){
        Elemento->Valor = Valor;
        Elemento->Prox = NULL;
    }

    return Elemento;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    Item *Item1, *Item2, *Item3;

    Item1 = Criar_Item(10);
    Item2 = Criar_Item(20);
    Item3 = Criar_Item(30);

    Item1->Prox = Item2;
    Item2->Prox = Item3;
    Item3->Prox = NULL;

    // Criar ponteiro para armazenar o endereço do primeiro item (para que possamos percorrer depois)
    Item *Atual;

    Atual = Item1; // Começa no Item1
    int cont=0;

    while (Atual != NULL){
        cout << "Item[" << cont+1 << "]: "<< Atual->Valor << endl; // Mostra o Item atual
        Atual = Atual->Prox; // Vai para o próximo Item
        cont++; // Contador para ver qual item estamos.
    }

    return 0;
}