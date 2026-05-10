/*Neste problema você deve ler um número que indica uma coluna de uma matriz na qual uma operação deve ser realizada, um caractere maiúsculo, indicando a operação que será realizada, e todos os elementos de uma matriz M[12][12].
 Em seguida, calcule e mostre a soma ou a média dos elementos que estão na área verde da matriz, conforme for o caso. 

 -> Nesse caso, faremos um programa semelhante ao do exercício anterior, porém, ao invés de fixar a linha e percorrer as colunas, fixaremos a coluna e percorreremos as linhas.
 ---------------------------------------------------------------------------------------------------------------------
 - IMPORTANTE
  Não copie o código do exercício anterior, faça um novo programa e utilize a mesma lógica, mas adaptando-a para o caso da coluna. 
  Digo isso pois quando mais você treina, melhor fica, então não custa nada refazer.*/

 #include <iostream>
#include <iomanip>
 using namespace std;

 int main()
 {
    cout << fixed << setprecision(1);
    int C, l, c; // C = Coluna a ser considerada para operação, l = linha, c = coluna
    char T;
    double M[12][12], soma = 0.0;

    cin >> C >> T; // Lê a coluna e o tipo da operação

    for(l=0;l<12;l++) // Lê os elementos da matriz
    {
        for(c=0;c<12;c++)
        {
            cin >> M[l][c];
        }
    }

    for(l=0;l<12;l++)
    {
        soma += M[l][C]; // Soma os elementos da coluna C. Fixei a coluna C e percorri todas as linhas.
    }
    if (T == 'S')
    {
        cout << soma << endl; // Imprime a soma dos elementos da coluna C
    }
    else if (T == 'M')
    {
        cout << soma / 12.0 << endl; // Imprime a média dos elementos da coluna C (soma dividida por 12)
    }

    return 0;
}