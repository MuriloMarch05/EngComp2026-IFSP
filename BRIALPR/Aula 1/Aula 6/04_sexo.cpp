/*4) Faça um Programa que verifique se uma letra digitada é "F" ou "M". Conforme a letra escrever:
F - Feminino, M - Masculino, Sexo Inválido.*/

// Para fazer esse exercício, podemos usar tanto o switch-case quanto o if-else.
// Nesse caso, vamos usar o switch-case para verificar a letra digitada.

#include <iostream>
using namespace std;

int main()
{
    char sexo;

    cout << "Digite o sexo (F/M): ";
    cin >> sexo;
    sexo = toupper(sexo); // Convertendo a letra para maiúscula para facilitar a comparação

    switch(sexo)
    {
        case 'F':
            cout << "Sexo feminino." << endl;
            break;
        case 'M':
            cout << "Sexo masculino." << endl;
            break;
        default:
            cout << "Sexo inválido." << endl;
            break;
    }
    
    return 0;
}



