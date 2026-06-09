/*3) Faça um programa para criptografar uma frase dada pelo usuário (a criptografia
troca as vogais da frase por *).*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    string frase;

    cout << "Digite uma frase para criptografá-la: ";
    getline(cin, frase);

    for(int i = 0; i < frase.length(); i ++)
    {
        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u')
        {
            frase[i] = '*';
        }

        if(frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U')
        {
            frase[i] = '*';
        }
    }

    cout << "Frase criptografada: " << frase << endl;

    return 0;
}