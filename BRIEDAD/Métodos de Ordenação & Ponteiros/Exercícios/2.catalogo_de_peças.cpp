/*

Exercício 2: Catálogo de Peças (Selection Sort)

- Objetivo: Ordenar produtos pelo seu código identificador.
- Defina uma struct Produto com codigo (int) e preco (float)
- Crie uma função para preencher os dados de 5 produtos cadastrados pelo usuário.
- Implemente o Selection Sort para organizar o catálogo em ordem crescente pelo campo codigo

Uso de Ponteiro: Na lógica de troca (swap), utilize uma variável auxiliar do tipo struct Produto para trocar os blocos inteiros de dados na memória ao encontrar o menor elemento.

*/

#include <iostream>
using namespace std;

struct Produto{
    int codigo;
    double preco;
};

void cadastroProdutos(){

}


int main(){
    setlocale(LC_ALL, "Portuguese");

    int tam = 5;
    Produto listaProdutos[tam];
    
    


    return 0;
}