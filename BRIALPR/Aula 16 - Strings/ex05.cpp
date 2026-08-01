/*5) Faça um programa que receba uma frase e mostre cada palavra dela em uma
linha separada.
Exemplo:
Frase: COMPUTADORES SÃO MÁQUINAS POTENTES
Saída:
COMPUTADORES
SÃO
MÁQUINAS
POTENTES*/

#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string frase;

    cout << "Digite uma frase qualquer: ";
    getline(cin, frase);

    istringstream iss(frase);
    string palavra;
    while (iss >> palavra) {
        cout << palavra << '\n';
    }

    return 0;
}