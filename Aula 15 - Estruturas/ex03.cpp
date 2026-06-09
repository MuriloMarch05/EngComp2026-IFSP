/*3) Faça um programa para um concurso de beleza no qual precisa-se armazenar os dados das 30
candidatas, que são: número da inscrição, nome, altura, peso, naturalidade e estado. Depois de
cadastrar, apresentar somente o nome das candidatas que possuem altura acima de 1.85 e do
estado de SP.*/


#include <iostream>
using namespace std;


struct concurso
{
    int inscricao;
    string nome, naturalidade, estado;
    double altura, peso;

} mulheres[3];

int main()
{
    setlocale(LC_ALL, "Portuguese");

    for (int i = 0; i<3; i++)
    {
        cout << "Digite o número da "<< i+1 <<"a. candidata (inteiro): ";
        cin >> mulheres[i].inscricao;

        cin.ignore();
        cout << "Digite o nome da " << i+1 << "a. candidata: ";
        getline(cin, mulheres[i].nome);

        cout << "Digite a altura da " << i+1 << "a. candidata (em metros): ";
        cin >> mulheres[i].altura;

        cout << "Digite o peso da " << i+1 << "a. candidata (em KG): ";
        cin >> mulheres[i].peso;

        cin.ignore();
        cout << "Digite a naturalidade " << i+1 << "a. candidata (município): ";
        cin >> mulheres[i].naturalidade;

        cout << "Digite o estado da " << i+1 << "a. candidata (SIGLA): ";
        cin >> mulheres[i].estado;

    }

    cout << "Candidatas com 1.85m ou mais e que são do estado de São Paulo: " << endl;

    for (int i =0; i<3; i++)
    {

        if (mulheres[i].altura >= 1.85 && mulheres[i].estado == "SP")
        {
            cout << "Nome: " << mulheres[i].nome << endl;
        }
    }

    return 0;
}