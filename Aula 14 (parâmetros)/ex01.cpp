/*1) Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores de
entrada e retorne o maior valor na primeira variável e o segundo maior valor na segunda variável.
Escreva o conteúdo das 2 variáveis na tela.*/

#include <iostream>
using namespace std;

void maiorValor(int &a, int &b) // Utilizamos a variáveis por referência, para que seja posível alterar diretamente.
{
    int temp; // Variável auxiliar.

    if (b>a)
    {
        temp = a;
        a = b;
        b = temp;
    }

}

int main()
{
    int num1, num2;

    cout << "Digite o primeiro numero: ";
    cin >> num1;

    cout << "Digite o segundo numero: ";
    cin >> num2;

    maiorValor(num1, num2); // A função vai reorganizar as variáveis.

    cout << "O maior valor é : " << num1 << endl;
    cout << "O menor valor é : " << num2 << endl;

    return 0;
}