/*Exercício 8: Escreva um programa usando `for` que exiba todos os números pares entre 10 e 200, um em cada linha.*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura para exibir acentos corretamente

    int i;
    cout << "Números pares entre 10 e 200:" << endl;
    for (i = 10; i<=200; i++)
    {
        if(i%2 == 0) // Verifica se o número é par
        {
            cout << i << "\n"; // Exibe o número par. Deixei \n pois é mais leve que endl.
        }
    }

    return 0;
}   


