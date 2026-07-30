/*1 - Faça um programa que armazene dados de 6 alunos com os
respectivos campos: número da matrícula, nome, nota da prova1, nota
da prova2 e média final. O professor entrará com os dados a serem
armazenados exceto a média que será calculada e armazenada pelo
programa. Sabendo que a média final é 6, imprima no final somente o
nome e a média dos alunos que passaram de ano.*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct aluno {
    int matricula;
    string nome;
    float prova1;
    float prova2;
    float media;
}alunos[6];

int main()
{
    for (int i=0; i<6; i++)
    {
        cout << "Digite a matricula do " << i+1 << "o. aluno: "<< endl;
        cin >> alunos[i].matricula;

        cout << "Digite o nome do " << i+1 << "o. aluno: "<< endl;
        cin >> alunos[i].nome;
        getline(cin, alunos[i].nome);

        cout << "Digite a nota da P1 do " << i+1 << "o. aluno: " << endl;
        cin >> alunos[i].prova1;

        cout << "Digite a nota da P2 do " << i+1 << "o. aluno: " << endl;
        cin >> alunos[i].prova2;

        alunos[i].media = (alunos[i].prova1 + alunos[i].prova2) / 2;
    }

    cout << fixed << setprecision(2);
    cout << "Alunos aprovados: " << endl;

    for (int i=0; i<6; i++)
    {
        if (alunos[i].media >= 6)
        {
            cout << "Nome: " << alunos[i].nome << " - Media: " << alunos[i].media << endl;
        }
    }

    return 0;
}