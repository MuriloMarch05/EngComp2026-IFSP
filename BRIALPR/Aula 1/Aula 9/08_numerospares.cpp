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

    // Agora, vamos deixar o usuário escolher o intervalo para exibir os números pares, impares ou todos. Para isso, vamos usar o for aninhado.

    int inicio, fim;
    cout << "Digite o início do intervalo: ";
    cin >> inicio;
    cout << "Digite o fim do intervalo: ";
    cin >> fim;

    cout << "Você quer exibir pares, impares ou todos os números? (P/I/T): ";
    char escolha;
    cin >> escolha;
    escolha = toupper(escolha); // Convertendo para maiúscula para facilitar a comparação

    cout << "Números:\n";
    for (i = inicio;i<=fim; i++)
    {
        switch(escolha)
        {
            case 'P':
                if(i%2 == 0)
                {
                    cout << i << "\n";
                }
                break;
            case 'I':
                if(i%2 != 0)
                {
                    cout << i << "\n";
                }
                break;
            case 'T':
                cout << i << "\n";
                break;
            default:
                cout << "Opção inválida." << endl;
                return 1; // Encerra o programa com código de erro
        }
    }

    return 0;
}   