/*1) Construir um programa que calcula o cubo de um número inteiro. O cálculo do
cubo será feito utilizando-se uma função e esta deverá retornar o valor calculado.*/

#include <iostream>
#include <iomanip>
using namespace std;

double calcula_cubo(double num)
{
    double cubo;
    cubo = num*num*num;
    return cubo;
}

int main()
{
    double numero;
    cout << "Digite um numero para ver seu cubo: " << endl;
    cin >> numero;

    cout << "O cubo do numero "<< numero << " é igual a "<< calcula_cubo(numero);

    return 0;
}