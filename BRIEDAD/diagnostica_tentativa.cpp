#include <iostream>

using namespace std;

struct Contato {
    string Nome, Email, Telefone, Cidade, Estado;
    int Idade;
};

int Cadastrar(Contato A[], int Tam) {

    cout << "Nome[" << Tam <<"]: ";
    cin >> A[Tam].Nome;
    cout << "E-mail[" << Tam <<"]: ";
    cin >> A[Tam].Email;
    cout << "Telefone[" << Tam <<"]: ";
    cin >> A[Tam].Telefone;
    cout << "Cidade[" << Tam <<"]: ";
    cin >> A[Tam].Cidade;
    cout << "Estado[" << Tam <<"]: ";
    cin >> A[Tam].Estado;
    cout << "Idade[" << Tam <<"]: ";
    cin >> A[Tam].Idade;
    Tam++;
    return Tam;
}

void Imprimir_Reg(Contato A[], int Pos, int Tipo) {

    cout << "Nome[" <<Pos<< "]: " << A[Pos].Nome << endl;
    cout << "Email[" <<Pos<< "]: " << A[Pos].Email << endl;
    cout << "Telefone[" <<Pos<< "]: "<< A[Pos].Telefone << endl;

    if (Tipo == 1) {
        cout << "Cidade[" <<Pos<< "]: " << A[Pos].Cidade << endl;
        cout << "Estado[" << Pos << "]: " << A[Pos].Estado << endl;
        cout << "Idade[" <<Pos<< "]: " << A[Pos].Idade << endl;
        cout << endl;
    }
}

void Imprimir(Contato A[], int Tam, int Tipo) {
    int Cont;
    for (Cont = 0; Cont < Tam; Cont++){
        Imprimir_Reg(A, Cont, Tipo);
    }
}

void BuscaEstado(Contato A[], int Tam, string Estado) {
    int cont;
    for (cont = 0; cont < Tam; cont++) {
        if (A[cont].Idade >= 18 && A[cont].Estado == Estado) {
            Imprimir_Reg(A, cont, 1);
        }
    }

}

int BuscaVelha(Contato A[], int Tam, int idade) {
    int cont;
    for (cont = 0; cont < Tam; cont++) {

    }

}

void Menu(Contato A[]) {
    int Op, Tam=0, OpImp;
do {
    cout << "[1] - Cadastrar" << endl;
    cout << "[2] - Imprimir" << endl;
    cout << "[3] - Buscar maiores por Estado" << endl;
    cout << "[4] - Buscar pessoa mais velha" << endl;
    cout << "Opção: ";
    cin >> Op;

    switch (Op) {
        case 1:
            Tam = Cadastrar(A, Tam);
            break;
        case 2:
            cout << "[1] - Total" << endl;
            cout << "[2] - Parcial" << endl;
            cout << "Opção: ";
            cin >> OpImp;
            Imprimir(A, Tam, OpImp);
            break;
        case 3:
            BuscaEstado(A, Tam, Op);
            break;

        default:
            cout << "Opção inválida." << endl;
    }
}while (Op != 3);
}

Contato Agenda[10];
int main() {
        setlocale(LC_ALL, "Portuguese");

        Menu(Agenda);

        return 0;
}
