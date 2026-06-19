/*5) Um hospital utiliza um sistema para organizar a fila de pacientes com base no protocolo de Manchester
(gravidade por cores). Defina uma struct Paciente contendo: nome (string), idade (inteiro) e gravidade
(string, que pode ser "VERDE" ou "VERMELHO").


Cadastre um vetor de 6 pacientes no sistema.
O programa deve processar esse vetor e imprimir primeiro todos os pacientes com gravidade
"VERMELHO" (emergência) e, depois, todos os pacientes com gravidade "VERDE" (não urgente).*/


#include <iostream>
#include <iomanip>
using namespace std;

struct Pacientes
{
    string nome;
    int idade;
    string gravidade;
}paciente[3];


int main()
{
    setlocale(LC_ALL, "Portuguese");
    string gravidade_local;

    for (int i = 0; i<3; i++)
    {
        cout << "Digite o nome do paciente: ";
        cin >> paciente[i].nome;

        cout << "Idade do paciente: ";
        cin >> paciente[i].idade;

        cout << "Gravidade (vermelho / verde): ";
        cin >> paciente[i].gravidade;
        
    }
    
    cout << "PACIENTES URGENTES:" << endl;

    for(int i = 0; i<3; i++)
    {
        if (paciente[i].gravidade == "vermelho")
        {
            cout << "Nome: "<<paciente[i].nome << "\nIdade: " << paciente[i].idade << endl;
        }
    }

    cout << "PACIENTES NAO URGENTES:" << endl;
    
    for(int i = 0; i<3; i++)
    {
        if (paciente[i].gravidade == "verde")
        {
            cout << "Nome: " << paciente[i].nome << "\nIdade: " << paciente[i].idade << endl;
        }
    }

    return 0;
}