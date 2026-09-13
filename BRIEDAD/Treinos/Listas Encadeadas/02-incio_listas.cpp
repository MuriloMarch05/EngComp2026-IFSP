/*
==================================================
EXERCÍCIO — CRIAÇÃO E ENCADEAMENTO DE ITENS
==================================================

1. Crie a estrutura Item contendo:
   - um inteiro Valor;
   - um ponteiro Prox para outro Item.

2. Crie dois itens dinamicamente na memória.

3. Atribua os valores:
   - primeiro item: 10
   - segundo item: 20

4. Faça o ponteiro Prox do primeiro item
   apontar para o segundo item.

5. Faça o Prox do segundo item apontar para NULL.

6. Mostre na tela os valores dos dois itens,
   acessando o segundo item através do ponteiro
   Prox do primeiro.

A estrutura final deverá representar:

[10 | Prox] -----> [20 | NULL]

==================================================
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Item{
    int Valor;
    Item *Prox;
};

int main(){
    setlocale(LC_ALL, "Portuguese");

    Item *Item1, *Item2, *Item3;

    Item1 = (Item*) malloc(sizeof(Item));
    Item2 = (Item*) malloc(sizeof(Item));
    Item3 = (Item*) malloc(sizeof(Item));

    Item1->Valor = 10;
    Item2->Valor = 20;
    Item3->Valor = 30;

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