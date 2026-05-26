/*3) Crie uma função que receba um vector<int> por referência constante (const vector<int> &)
e imprima na tela qual é o maior e o menor elemento dele.*/

#include <iostream>
#include <vector>
#include <algorithm> // Biblioteca necessária para usar as funções max_element e min_element.
using namespace std;

void maiorMenor(const vector<int> &v)
{
    if (v.empty())
    {
        cout << "O vetor está vazio." << endl;
    }

    int maior = *max_element(v.begin(), v.end()); // A função max_element retorna um iterador para o maior elemento do vetor, e o operador * é usado para obter o valor desse elemento.
    int menor = *min_element(v.begin(), v.end()); // A função min_element retorna um iterador para o menor elemento do vetor, e o operador * é usado para obter o valor desse elemento.
    cout << "Maior elemento: " << maior << endl;
    cout << "Menor elemento: " << menor << endl;
}

int main()
{
    int vet[5], i;

    cout << "Digite 5 numeros: " << endl;

    for (i = 0; i < 5; i++)
    {
        cin >> vet[i];
    }

    vector<int> v(vet, vet + 5); // Criando um vetor a partir do array vet.

    maiorMenor(v); // Chamando a função para encontrar o maior e menor elemento do vetor.

    return 0;
}