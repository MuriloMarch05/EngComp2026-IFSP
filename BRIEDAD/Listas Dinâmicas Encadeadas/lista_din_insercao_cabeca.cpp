#include <iostream>

// Este é um exemplo de programa em C++

using namespace std;

struct Aluno{
	int Pront;
	Aluno *Prox;
};

Aluno * Cria_Aluno(int Pront){
	Aluno *Pt;
	
	Pt = (Aluno *) malloc(sizeof(Aluno));
	if (Pt != NULL){
		Pt->Pront = Pront;
		Pt->Prox = NULL;	
	}
	
	return Pt;
}

Aluno * Insere_Aluno(Aluno *Ini, int Pront){
	Aluno *Pt;
	
	Pt = Cria_Aluno(Pront);
	Pt->Prox = Ini;
	
	return Pt;
}

/*
I(A) = mostrar A e I(A->prox)
*/
void Imprime_Aluno(Aluno *Ini){
	if(Ini != NULL){
		cout << Ini->Pront << endl;
		Imprime_Aluno(Ini->Prox);
	}
}

Aluno *Inicio;
int main () {
	setlocale (LC_ALL,"Portuguese");
	
	Inicio = Insere_Aluno(Inicio,1);
	Inicio = Insere_Aluno(Inicio,2);
	Inicio = Insere_Aluno(Inicio,3);
	
	/*cout << Inicio->Pront << endl; 
	cout << Inicio->Prox->Pront << endl; 
	cout << Inicio->Prox->Prox->Pront << endl; */
	Imprime_Aluno(Inicio);
	
	return 0;
}
