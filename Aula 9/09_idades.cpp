/*Utilizando o comando `while`, crie um programa que leia idades de várias pessoas e pare apenas quando for digitado o valor `-99`. 
Ao final, mostre a média das idades lidas.*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int idades, soma = 0, contador = 0;
    int media;

    cout << "Digite as idades (-99 para parar): " << endl;

    while (idades != -99)
    {
        cin >> idades;

        if (idades != -99)
        {
            soma += idades; // Acumula a soma das idades
            contador++; // Conta quantas idades foram digitadas
        }
    }

    cout << "Você digitou " << contador << " idades." << endl;
    media = soma / contador; // Calcula a média

    if (contador > 0) // Verifica se alguma idade foi digitada
    {
        cout << "A média das idades é: " << media << endl;
    }
    else
    {
        cout << "Nenhuma idade foi digitada." << endl;
    }

    return 0;
}