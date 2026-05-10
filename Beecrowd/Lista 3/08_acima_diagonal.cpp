/*Leia um caractere maiúsculo, que indica uma operação que deve ser realizada e uma matriz M[12][12]. 
Em seguida, calcule e mostre a soma ou a média considerando somente aqueles elementos que estão acima da diagonal principal da matriz, conforme ilustrado abaixo (área verde).*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(1);
    char T; // Tipo da operação
    double M[12][12], soma = 0.0; // M = Matriz, soma = variável para armazenar a soma dos elementos acima da diagonal principal
    int l, c, cont = 0; // l = linha, c = coluna, cont = contador para contar o número de elementos acima da diagonal principal

    cin >> T;
    // Lê os elementos da matriz
    for(l=0;l<12;l++)
    {
        for(c=0;c<12;c++)
        {
            cin >> M[l][c];
        }
    }
    // Percorre os elementos acima da diagonal principal
    for(l=0;l<12;l++)
    {
        for(c=l+1;c<12;c++) // Percorre as colunas a partir de c = l + 1 para garantir que estamos considerando apenas os elementos acima da diagonal principal (onde a coluna é maior que a linha).
        {
            soma += M[l][c];
            cont++; // Incrementa o contador para contar o número de elementos acima da diagonal principal.
        }
    }

    if (T == 'S')
    {
        cout << soma << endl;
    }
    else if (T == 'M')
    {
        cout << soma / (double)cont << endl; // Imprime a média dos elementos acima da diagonal principal (soma dividida pelo número de elementos).
    }

    return 0;

    /* Explicação:
     A diagonal principal de uma matriz 12x12 é composta pelos elementos M[0][0], M[1][1], M[2][2], ..., M[11][11]. 
     Os elementos acima da diagonal principal são aqueles para os quais a coluna é maior que a linha (c > l).  
     -----------------------------------------------------------------------------------------------------------------
    - Obs: Achei esse exercício um pouco mais complexo do que os anteriores, pois é necessário entender a estrutura da matriz e como percorrer apenas os elementos acima da diagonal principal.
    - Dica: Para percorrer os elementos acima da diagonal principal, você pode usar um loop aninhado onde o loop externo percorre as linhas e o loop interno percorre as colunas a partir da coluna seguinte à linha atual (c = l + 1).
    - Lembre-se de contar o número de elementos acima da diagonal principal para calcular a média corretamente, caso a operação seja 'M'. 
    */

}
