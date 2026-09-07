#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Ocorrencia{
	int Codigo;
	char Descricao[20];
};

/*int Funcao(){
	static int X=0;
	
	++X;
	
	cout << X << endl;
	
	return X;	
}*/

Ocorrencia * Cria_Ocorrencia(int Codigo, const char* Desc){
	Ocorrencia *Ret;
	Ret = (Ocorrencia *) malloc(sizeof(Ocorrencia));
	if (Ret!=NULL){
		Ret->Codigo = Codigo;
		strcpy(Ret->Descricao, Desc);			
	}
	
	return Ret;
}


//int X=10, V[5];
int *pX;
Ocorrencia VOc[10], *Oc;
int main(){
	setlocale(LC_ALL, "Portuguese");

	/*Funcao();
	Funcao();
	Funcao();*/
	//cout << ((float) 5)/3; //conversão de tipos (cast)
	
	/*pX = (int *) malloc(4);
	*pX = 10;
	
	cout << *pX;*/
	
	//Ponteiro acessando vetor estático
	//Oc = (Ocorrencia *) malloc(10*sizeof(Ocorrencia));
	/*Oc = VOc+1;
	(*Oc).Codigo = 10;
	strcpy(Oc->Descricao, "Buraco");
	
	cout << (Oc+1)->Codigo << " - " << VOc[1].Descricao;*/
	
	//alocando e acessando o vetor dinâmico
	
	
/*	Oc = (Ocorrencia *) calloc(10,sizeof(Ocorrencia));
	if (Oc!=NULL){
		(*Oc).Codigo = 20;
		strcpy(Oc->Descricao, "Buraco calloc");
		
		cout << (Oc)->Codigo << " - " << Oc[0].Descricao << endl;
	}
	
	free(Oc);
	cout << (Oc)->Codigo << " - " << Oc[0].Descricao << endl;*/
	
	Oc =  Cria_Ocorrencia(10, "Buraco");
	cout << Oc->Codigo << " - " << Oc->Descricao << endl;		

	return 0;
}
