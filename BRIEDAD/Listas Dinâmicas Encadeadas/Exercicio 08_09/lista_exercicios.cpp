/*
Suponha DUAS listas dinâmicas encadeadas de números inteiros NÃO ORDENADAS (elementos podem ser inseridos sem ordenação e, no caso da lista dinâmica, é mais fácil inserir sempre no início). Implemente as seguintes rotinas em C++. 

Uma função que receba como parâmetros uma lista encadeada e um número inteiro a ser inserido na lista;
Uma função que receba como parâmetros uma lista encadeada e um número inteiro a ser removido da lista;
Uma função que receba como parâmetro uma lista encadeada e imprima a lista na tela;
Uma função que tenha como valor de retorno o comprimento de uma lista encadeada passada como parâmetro;
Uma função que receba como parâmetros uma lista encadeada e um número inteiro n e retorne o número de nós da lista que possuem o número inteiro (campo da lista) com valores iguais a n;
Uma função que receba como parâmetros uma lista encadeada e dois números (original e novo) e troque todas as ocorrências do número original pelo número novo. Após o retorno da lista resultante, a mesma deve ser impressa na tela (função Imprimir);
Uma função que receba como parâmetro uma lista encadeada e um valor inteiro n, e retorne duas listas, de tal forma que a primeira lista possua todos os elementos que são maiores que n e a segunda lista possua todos os elementos que são menores do que n. Após o processamento da função, as duas listas devem ser impressas na tela (função Imprimir). Considere uma lista qualquer não ordenada;
Uma função que construa uma nova lista a partir dos números que fazem parte de duas listas passadas como parâmetros. Essa função deve receber como parâmetro as duas listas a serem comparadas e retornar a lista resultante com os elementos que fazem parte da interseção. Após o retorno da lista resultante, a mesma deve ser impressa na tela (função Imprimir). Considere duas listas quaisquer não ordenadas.
Implementar  a função principal "main", conforme a imagem abaixo:

Observação: Recomenda-se utilizar o Switch Case devido a complexidade do exemplo.*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Item{
    int Valor;
    Item *Prox;
};

struct Lista{
    Item *Inicio;
};


void Inicializar_Lista(Lista *L){
    L->Inicio = NULL;
}

int Lista_Vazia(Lista *L){
    int Ret = 1;

    if (L->Inicio != NULL){
        Ret = 0;
    }

    return Ret;
}

Lista* Criar_Lista(){
    Lista *L;

    L = (Lista *) malloc(sizeof(Lista));
    if (L != NULL){
        Inicializar_Lista(L);
    }

    return L;
}

Item* Criar_Item(int Valor){
    Item *Elemento;

    Elemento = (Item *) malloc(sizeof(Item));

    if (Elemento !=  NULL){
        Elemento->Valor = Valor;
        Elemento->Prox = NULL;
    }

    return Elemento;
}

Lista* Selecionar_Lista(Lista *L1, Lista *L2){
    int Op;
    Lista *L;

    do{
        cout << "\n Qual lista deseja utilizar? (Lista 1 = [1], Lista 2 = [2]) \n";
        cout << "Resposta: ";
        cin >> Op;
        if(Op!=1 && Op != 2){
            cout << "\nLista inválida\n";
        }
        else{
            if(Op==1){
                L= L1;
            }
            else{
                L = L2;
            }
        }

    }while(Op != 1 && Op != 2);

    return L;
}

void Menu(Lista *L1, Lista *L2){
    int Op, Valor;
    Lista* L;

    do{
        cout << "------------------ TESTE DE OPERAÇÕES COM LISTAS -----------------" << endl;
        cout << "1 - Inserir na lista (Lista 1 ou Lista 2)" << endl;
        cout << "2 - Excluir da lista (Lista 1 ou Lista 2) " << endl;
        cout << "3 - Imprimir" << endl;
        cout << "4 - " << endl;
        cout << "5 - " << endl;
        cout << "6 - " << endl;
        cout << "7 - Dividir a lista em duas (Lista 1 e Lista 2)" << endl;
        cout << "8 - Intersecção das listas " << endl;
        cout << "0 - Sair" << endl;
        cin >> Op;

        switch (Op){
            case 1:

            case 2:

            case 3:

            case 4:

            case 5:

            case 6:

            case 7:

            case 8:

            default:
                cout << "Opção inválida" << endl;
        }

    }while(Op != 0);
}

Lista *L1, *L2;
int main(){
    setlocale(LC_ALL, "Portuguese");

    L1 = Criar_Lista();
    Inicializar_Lista(L1);

    L2 = Criar_Lista();
    Inicializar_Lista(L2);

    Menu(L1, L2);

    return 0;
}