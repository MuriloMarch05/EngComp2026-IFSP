/*Neste problema você deve ler um número, indicando uma linha da matriz na qual uma operação deve ser realizada, um caractere maiúsculo, indicando a operação que será realizada, 
e todos os elementos de uma matriz M[12][12]. 
Em seguida, calcule e mostre a soma ou a média dos elementos que estão na área verde da matriz, conforme for o caso. 
---------------------------------------------------------------------------------------------------------------------
-> A primeira linha de entrada contem um número L (0 ≤ L ≤ 11) indicando a linha que será considerada para operação.
 - A segunda linha de entrada contém um único caractere Maiúsculo T ('S' ou 'M'), indicando a operação (Soma ou Média) que deverá ser realizada com os elementos da matriz. 
 - Seguem os 144 valores de ponto flutuante que compõem a matriz, sendo que a mesma é preenchida linha por linha, da linha 0 até a linha 11, sempre da esquerda para a direita.*/

#include <iostream>
#include <iomanip> // Necessário para usar a função setprecision
using namespace std;

int main()
{
    cout << fixed << setprecision(1); // Configura a saída para exibir um número fixo de casas decimais (1 casa decimal)
    int L, l, c; // L = Linha a ser considerada para operação, l = linha, c = coluna
    char T; // Tipo da operação
    double M[12][12], soma = 0.0; // M = Matriz, soma = variável para armazenar a soma dos elementos da linha

    cin >> L >> T; // Lê a linha e o tipo da operação

    // Lê os elementos da matriz
    for (l=0;l<12;l++)
    {
        for (c=0;c<12;c++)
        {
            cin >> M[l][c];
        }
    }

    for (c=0; c<12; c++)
    {
        soma += M[L][c]; // Soma os elementos da linha L. Fixei a linha L e percorri todas as colunas.
        
    }
    if (T == 'S')
    {
        cout << soma << endl; // Imprime a soma dos elementos da linha L
    }
    else if (T == 'M')
    {
        cout << soma / 12.0 << endl; // Imprime a média dos elementos da linha L (soma dividida por 12)
    }

    return 0;
}
