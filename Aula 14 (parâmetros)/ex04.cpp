/*4) Escreva uma função que receba um vector<float> com notas de alunos e retorne a média
aritmética (retorno do tipo float).*/

#include <iostream>
#include <vector> // Para usar o tipo vector
#include <iomanip>
using namespace std;

// Função para calcular a média das notas
float calcularMedia(const vector<float> &notas)
{
    float soma = 0.0;
    for (float nota : notas) // Percorre cada nota no vector e acumula a soma
    {
        soma += nota;
    }

    return notas.empty() ? 0.0 : soma / notas.size(); // Retorna a média, evitando divisão por zero.
}

// Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese");
    vector<float> notas;
    int quantidade;

    cout << "Digite a quantidade de notas: ";
    cin >> quantidade;

    for (int i = 0; i<quantidade; i++) // Loop para ler as notas dos alunos
    {
        float nota;
        cout << "Digite a nota do aluno " << (i+1) << ": ";
        cin >> nota;
        notas.push_back(nota);
    }

    float media = calcularMedia(notas);
    cout << fixed << setprecision(2);
    cout << "A média das notas é: " << media << endl;

    return 0;
}