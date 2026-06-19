/*4) Faça um programa para criptografar uma frase dada pelo usuário. Na criptografia, a
frase deverá ser invertida e as consoantes deverão ser trocadas por #.
Exemplo: EU ESTOU NA ESCOLA
A#O##E A# UO##E EU */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string frase;
    string vogais = "aeiouAEIOU";

    cout << "Digite uma frase: " << endl;
    getline(cin, frase);

    for (int i = frase.size()-1; i>=0;--i)
    {
        if (vogais.find(frase[i]) != string::npos)
        {
            cout << frase[i]; // Vogal
        }
        else if (isalpha(frase[i]))
        {
            cout << '#'; // Consoante
        }
        else
        {
            cout << frase[i]; // espaço, pontuação, etc.
        }
    }

    return 0;
}