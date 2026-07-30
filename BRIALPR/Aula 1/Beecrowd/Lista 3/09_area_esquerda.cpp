#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(1);
    char T; // Tipo de operação
    int l, c, cont=0; // Contador para saber a quantidade de elementos na área verde
    double M[12][12], soma=0.0;
    
    cin >> T;
    
    for(l=0;l<12;l++) // Loops aninhados para preenchimento da matriz
    {
        for(c=0;c<12;c++)
        {
            cin >> M[l][c];
        }
    }
    
    for(l=0;l<12;l++) // Agora vamos percorrer de novo, mas para encaixar as condições
    {
        for(c=0;c<12;c++)
        {
            if (c<l && c<(11-l)) // Condição para ver se o elemento está na área verde (à esquerda da diagonal principal e à esquerda da diagonal secundária)
            {
                soma += M[l][c];
                cont++;
            }
        }
    }    
    
    if(T == 'S')
    {
        cout << soma << endl;
    }
    
    else if (T == 'M')
    {
        cout << soma / (double)cont << endl;
    }
    return 0;
}