/* Faça um programa que leia dois números e imprima a soma e a subtração deles. */

#include <iostream> // Inclui a biblioteca de entrada e saída. Use em todos os programas C++.
using namespace std; // Permite usar nomes do espaço de nomes std sem o prefixo "std::".

int main() // Função principal do programa, onde a execução começa.
{
    int num1, num2; // Declaração de duas variáveis inteiras para armazenar os números.

    cout << "Digite o primeiro número: "; // Solicita ao usuário que digite o primeiro número.
    cin >> num1; // Lê o primeiro número digitado pelo usuário e armazena na variável num1.

    cout << "Digite o segundo número: "; // Solicita ao usuário que digite o segundo número.
    cin >> num2; // Lê o segundo número digitado pelo usuário e armazena na variável num2.

    // Agora, você tem duas formas de realizar a soma e a subtração: usando vaiáveis intermediárias ou realizando as operações diretamente na impressão.
    // Usando variáveis intermediárias:
    int soma = num1 + num2; // Calcula a soma dos dois números e armazena na variável soma.
    int subracao = num1 - num2; // Calcula a subtração dos dois números e armazena na variável subtracao.

    cout << "Soma: " << soma << endl; // Imprime a soma dos dois números.
    cout << "Subtração: " << subracao << endl; // Imprime a subtração dos dois números.

    /* Ou, realizando as operações diretamente na impressão:

    cout << "Soma: " << (num1 + num2) << endl;
    cout << "Subtração: " << (num1 - num2) << endl;
    -----------------------------------------------------------------
    -> Ambas as formas são válidas. A escolha entre elas depende do estilo de codificação e da clareza que você deseja alcançar. 
    -> Usar variáveis intermediárias pode tornar o código mais legível, especialmente se as operações forem complexas ou se os resultados forem usados em várias partes do programa. 
    -> Por outro lado, realizar as operações diretamente na impressão pode ser mais conciso para operações simples.
    */
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso.
}