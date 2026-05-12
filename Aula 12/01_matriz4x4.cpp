/*1) Seja a matriz inteira valores (4x4). Preenchê-la por leitura, apresentar seus valores, e a
quantidade de elementos maiores que 15.*/

#include <iostream>
using namespace std;

int main()
{
    int matriz[4][4], qtde=0; // Matriz 4x4 e variável para contar a quantidade de elementos maiores que 15, inicializada em 0.
    int l, c;
    
    cout << "Preencha a matriz 4x4 com inteiros: " << endl;
    
    for(l=0;l<4;l++)
    {
        for(c=0;c<4;c++)
        {
            cin >> matriz[l][c];
            
            if (matriz[l][c] > 15) // Se o elemento atual for maior que 15, incrementamos a quantidade
            {
                qtde++;
            }
        }
    }
    
    cout << "Os valores digitados foram: " << endl;
    for(l=0;l<4;l++)
    {
        for(c=0;c<4;c++)
        {
            cout << matriz[l][c] << endl;
        }
    }
    
    cout << "Quantidade de valores maiores que 15: " << qtde << endl;
}