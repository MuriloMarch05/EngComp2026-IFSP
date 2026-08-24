/*

Exercício 2: Catálogo de Peças (Selection Sort)

- Objetivo: Ordenar produtos pelo seu código identificador.
- Defina uma struct Produto com codigo (int) e preco (float)
- Crie uma função para preencher os dados de 5 produtos cadastrados pelo usuário.
- Implemente o Selection Sort para organizar o catálogo em ordem crescente pelo campo codigo

Uso de Ponteiro: Na lógica de troca (swap), utilize uma variável auxiliar do tipo struct Produto para trocar os blocos inteiros de dados na memória ao encontrar o menor elemento.

*/

#include <iostream>
#include <clocale>

using namespace std;

struct Produto{
    int codigo;
    double preco;
};


void cadastroProdutos(Produto *p, int tam){

    for(int i = 0; i < tam; i++){

        cout << "Código do produto[" << i << "]: ";
        cin >> p[i].codigo;

        cout << "Preço do produto[" << i << "]: ";
        cin >> p[i].preco;
    }
}


void selectionSort(Produto *p, int tam){

    int i, j, min, localTroca, trocou;
    Produto aux;

    for(i = 0; i < tam - 1; i++){

        min = p[i].codigo;
        localTroca = i;
        trocou = 0;

        for(j = i + 1; j < tam; j++){

            if(p[j].codigo < min){

                min = p[j].codigo;
                localTroca = j;
                trocou = 1;
            }
        }

        if(trocou){

            aux = p[i];
            p[i] = p[localTroca];
            p[localTroca] = aux;
        }
    }
}


void catalogo(Produto *p, int tam){

    cout << "===== CATÁLOGO DE PRODUTOS =====" << endl;

    for(int i = 0; i < tam; i++){

        cout << "Produto[" << i << "]: "
             << p[i].codigo << endl;

        cout << "Preço[" << i << "]: "
             << p[i].preco << endl;
    }
}


int main(){

    setlocale(LC_ALL, "Portuguese");

    const int tam = 5;

    Produto listaProdutos[tam];

    cadastroProdutos(listaProdutos, tam);

    selectionSort(listaProdutos, tam);

    catalogo(listaProdutos, tam);

    return 0;
}