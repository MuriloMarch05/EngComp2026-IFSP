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

void EstadoMaior(Contato A[], int Pos, string Estado){
	if(A[Pos].Estado==Estado && A[Pos].Idade>18){
		cout << "Nome["<<Pos<<"]: "<< A[Pos].Nome << endl;
		cout << "E-mail["<<Pos<<"]: "<< A[Pos].Email << endl;
		cout << "Telefone["<<Pos<<"]: "<< A[Pos].Telefone << endl;
		cout << "Cidade["<<Pos<<"]: "<< A[Pos].Cidade << endl;
		cout << "Estado["<<Pos<<"]: "<< A[Pos].Estado << endl;
		cout << "Idade["<<Pos<<"]: "<< A[Pos].Idade << endl;		
		cout << endl;
	}
}

void Imprimir(Contato A[], int Tam, int Tipo, int MaiorP, string Estado){ //Tipo=1 (Tudo), Tipo=2 (Parcial), Tipo=3 (Pessoa mais velha, apenas), Tipo 4 (Pessoas maiores de 18 anos e de um Estado a ser lido)
	int Cont;
	if(Tipo!=3){
		for(Cont=0; Cont <Tam; Cont++){
		if(Tipo==4){
			EstadoMaior(A, Cont, Estado);
		}
			else{
				Imprimir_Reg(A, Cont, Tipo);
			}
	}
	}
	else{
		cout << "Nome["<<MaiorP<<"]: "<<A[MaiorP].Nome<<endl;
		cout << "E-Mail["<<MaiorP<<"]: "<<A[MaiorP].Email<<endl;
		cout << "Telefone["<<MaiorP<<"]: "<<A[MaiorP].Telefone<<endl;
		cout << "Cidade["<<MaiorP<<"]: "<<A[MaiorP].Cidade<<endl;
		cout << "Estado["<<MaiorP<<"]: "<<A[MaiorP].Estado<<endl;
		cout << "Idade["<<MaiorP<<"]: "<<A[MaiorP].Idade<<endl;
	}
}
int Maior(Contato A[], int Tam){
	int Cont, MaiorI, MaiorP;
	for(Cont=0;Cont<Tam;Cont++){
		if(Cont==0){
			MaiorP=0;
			MaiorI=A[0].Idade;
		}
		else{
			if(A[Cont].Idade>MaiorI){
				MaiorP=Cont;
				MaiorI=A[Cont].Idade;
			}
		}
	}
	return MaiorP;
}



void Menu(Contato A[]){
	int Op, OpImp, Tam=0, MaiorP;
	string Estado;
	do{ //1 ou mais vezes - Menu
		system("cls");
		cout << "[1] - Cadastrar" << endl;
		cout << "[2] - Imprimir" << endl;
		cout << "[3] - Sair" << endl;
		cout << "Op��o: ";
		cin >> Op;
		//processamento
		switch(Op){
			case 1:
				Tam = Cadastrar(A, Tam);
			 MaiorP = Maior(A, Tam);
				break;
			case 2:
				system("cls");
				cout << "[1] - Total" << endl;
			 cout << "[2] - Parcial" << endl;
			 cout << "[3] - Dados da pessoa mais velha" << endl;
			 cout << "[4] - Dados das pessoas maiores de idade e de um estado (a ser definido pelo usuário)" << endl;
				cout << "Opção: ";
				cin >> OpImp;
			 if(OpImp==4){
			  	system("cls");
			  	cout<<"\nDigitar o estado desejado:\n";
			  	cin>>Estado;
			 }
				 Imprimir(A, Tam, OpImp, MaiorP, Estado);
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
