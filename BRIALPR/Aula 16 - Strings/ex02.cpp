/*2) Faça um programa que receba uma frase, calcule e mostre a quantidade de
palavras da frase digitada.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string frase;
    int palavras = 0;
    bool dentroPalavra = false;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    for(int i = 0; i < frase.length(); i++)
    {
        if(frase[i] != ' ')
        {
            if(!dentroPalavra)
            {
                palavras++;
                dentroPalavra = true;
            }
        }
        else
        {
            dentroPalavra = false;
        }
    }

    cout << "Quantidade de palavras: " << palavras;

    return 0;
}
