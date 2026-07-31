#include <iostream>

using namespace std; //std::

struct Contato{
	string Nome, Email, Telefone, Cidade, Estado;
	int Idade;
};

int Cadastrar(Contato A[], int Tam){
		
	cout << "Nome["<<Tam<<"]: ";
	cin >> A[Tam].Nome;
	cout << "E-mail["<<Tam<<"]: ";
	cin >> A[Tam].Email;
	cout << "Telefone["<<Tam<<"]: ";
	cin >> A[Tam].Telefone;
	cout << "Cidade["<<Tam<<"]: ";
	cin >> A[Tam].Cidade;
	cout << "Estado["<<Tam<<"]: ";
	cin >> A[Tam].Estado;
	cout << "Idade["<<Tam<<"]: ";
	cin >> A[Tam].Idade;
	Tam++;		

	return Tam;
}

void Imprimir_Reg(Contato A[], int Pos, int Tipo){ //Tipo=1 (Tudo), Tipo=2 (Parcial)
	cout << "Nome["<<Pos<<"]: "<< A[Pos].Nome << endl;
	cout << "E-mail["<<Pos<<"]: "<< A[Pos].Email << endl;
	cout << "Telefone["<<Pos<<"]: "<< A[Pos].Telefone << endl;

	if (Tipo==1){
		cout << "Cidade["<<Pos<<"]: "<< A[Pos].Cidade << endl;
		cout << "Estado["<<Pos<<"]: "<< A[Pos].Estado << endl;
		cout << "Idade["<<Pos<<"]: "<< A[Pos].Idade << endl;		
		cout << endl;
	}
}

void Imprimir(Contato A[], int Tam, int Tipo){ //Tipo=1 (Tudo), Tipo=2 (Parcial)
	int Cont;
	for(Cont=0; Cont <Tam; Cont++){
		Imprimir_Reg(A, Cont, Tipo);
	}
}



void Menu(Contato A[]){
	int Op, OpImp, Tam=0;
	do{ //1 ou mais vezes - Menu
		system("cls");
		cout << "[1] - Cadastrar" << endl;
		cout << "[2] - Imprimir" << endl;
		cout << "[3] - Sair" << endl;
		cout << "Opção: ";
		cin >> Op;
		//processamento
		switch(Op){
			case 1:
				Tam = Cadastrar(A, Tam);				
				break;
			case 2:
				system("cls");
				cout << "[1] - Total" << endl;
				cout << "[2] - Parcial" << endl;
				cout << "Opção: ";
				cin >> OpImp;
				Imprimir(A, Tam, OpImp);
				break;	
			case 3:
				break;
			default:
				cout << endl << "Opção inválida!!" << endl;
		}
				
		system("pause");
	}while(Op!=3);
}

Contato Agenda[10];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Menu(Agenda);
	
	return 0;
}
