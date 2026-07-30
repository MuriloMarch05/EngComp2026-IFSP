/*3)Faça um programa que:


Leia dois vetores com 5 elementos cada.
Crie um terceiro vetor contendo os elementos dos dois vetores.*/

#include <iostream>
using namespace std;

int main()
{
    int vet1[5], vet2[5], vet3[10];
    int i;

    // Leitura do primeiro vetor
    cout << "Digite os elementos do primeiro vetor: " << endl;
    for(i =0;i<5;i++)
    {
        cin >> vet1[i];
    }
    // Leitura do segundo vetor
    cout << "Digite os elementos do segundo vetor: " << endl;
    for(i=0;i<5;i++)
    {
        cin >> vet2[i];
    }

    // Preenchimento do terceiro vetor com os elementos dos dois vetores
    for(i=0;i<5;i++)
    {
        vet3[i] = vet1[i];
        vet3[i+5] = vet2[i];
    }
        
    // Exibição do terceiro vetor
    cout << "O terceiro vetor é: " << endl;

    for(i=0;i<10;i++)
    {
        cout << vet3[i] << " ";
    }
}