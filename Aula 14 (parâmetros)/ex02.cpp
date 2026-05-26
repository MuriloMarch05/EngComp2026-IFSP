/*2) Faça um programa que leia três valores inteiros e chame uma sub-rotina que receba estes 3 valores
de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variável, o segundo menor
valor na variável do meio, e o maior valor na última variável. A rotina deve retornar o valor 1 se os três
valores forem iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na tela.*/

#include <iostream>
using namespace std;


int ordenados(int &a, int &b, int &c)
{
    int aux; // Variável auxiliar para realizar as trocas.

    if (a==b && b==c) // Se os três valores forem iguais, a função retorna 1.
    {
        return 1;
    }

    if (a>b) // Se a for maior que b, realiza a troca para que a seja o menor valor.
    {
        aux = a;
        a = b;
        b = aux;
    }

    if (b>c) // Se b for maior que c, realiza a troca para que b seja o segundo menor valor e c seja o maior valor.
    {
        aux = b;
        b = c;
        c = aux;
    }
    if (a>b) // Após a primeira troca, é necessário verificar novamente se a é maior que b, para garantir que a seja o menor valor.
    {
        aux = a;
        a = b;
        b = aux;
    }

    return 0;
}

int main()
{
    int num1,num2,num3;

    cout << "Digite o primeiro numero: ";
    cin >> num1;
    
    cout << "Digite o segundo numero: ";
    cin >> num2;

    cout << "Digite o terceiro numero: ";
    cin >> num3;

    ordenados(num1,num2,num3); // A função organiza os números em ordem crescente.

    cout << "Os numeros ordenados sao: " << num1 << ", " << num2 << ", " << num3 << endl;

    return 0;
}