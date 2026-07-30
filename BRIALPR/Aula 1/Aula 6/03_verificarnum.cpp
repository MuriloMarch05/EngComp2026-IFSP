/*3) Escreva um programa para ler um número. Verificar se o número é positivo, negativo ou igual a
zero.*/

#include <iostream>
using namespace std;

int main()
{
    double num;

    cout << "Digite um número: ";
    cin >> num;

    if (num > 0)
    {
        cout << "O número "<< num << " é positivo." << endl;
    }
    else if (num < 0)
    {
        cout << "O número " << num << " é negativo." << endl;
    }
    else
    {
        cout << "O número é igual a zero." << endl;
    }

    return 0;
}   



