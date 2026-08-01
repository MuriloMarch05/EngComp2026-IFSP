/*1) Faça um programa que receba uma frase, calcule e mostre a quantidade de vogais
da frase digitada. O programa deverá contar vogais maiúsculas e minúsculas.*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string frase;
    int vogMin=0, vogMai=0;

    cout << "Digite qualquer merda, de preferência mais de uma palavra: ";
    getline(cin, frase);

    for (int i = 0; i<frase.length(); i++)
    {
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' )
        {
            vogMin++;
        }
    }

    for (int i = 0; i<frase.length(); i++)
    {
        if (frase[i] == 'A' || frase [i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U')
        {
            vogMai++;
        }
    }

    cout << "A frase tem " << vogMin << " vogais minúsculas e "<< vogMai << " vogais maiúsculas.";

    return 0;
}
