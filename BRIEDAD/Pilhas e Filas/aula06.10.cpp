#include <iostream>
#include <string.h>

using namespace std;

//Inicializar, vazia, inserção,
// remoção e impressão
struct Elemento{
	char Item;
	Elemento *Prox;
};

struct Fila{
	Elemento *Inicio;
	Elemento *Fim;
	int Total;
};

struct Pilha{
	Elemento *Topo;
	int Total;
};

void Ini_Fila(Fila *F)
{
	F->Inicio = NULL;
	F->Fim = NULL;
	F->Total = 0;
}

void Ini_Pilha(Pilha *P)
{
	P->Topo = NULL;
	P->Total = 0;
}

bool Fila_Vazia(Fila *F){
	return (F->Inicio == NULL);
}

bool Pilha_Vazia(Pilha *P){
	return (P->Topo == NULL);
}

void Imprimir(Elemento *E){
	Elemento *Aux;
	
	cout << endl << "IMPRESSÃO" << endl;	
	for(Aux = E;Aux!=NULL;Aux = Aux->Prox){
		cout << Aux->Item;
		
		if(Aux->Prox != NULL){
			cout << ", ";
		}
	}
}

Elemento * Criar_Elemento(char C){
	Elemento *Ret;

	Ret = (Elemento *) malloc(sizeof(Elemento));	
	if (Ret !=NULL){
		Ret->Item = C;
		Ret->Prox = NULL;
	}
	
	return Ret;
}

//FIFO - First In, First Out
//Enqueue (Queue = fila!!)
void Enfileirar(Fila *F, char C){
	Elemento *ptE;
	
	ptE = Criar_Elemento(C);
	if (ptE !=NULL){
		if (Fila_Vazia(F)){
			//Atualiza início e fim
			F->Inicio = ptE;			
		}
		else{
			//Atualiza o fim
			F->Fim->Prox = ptE;				
		}
		
		F->Fim = ptE;
		++F->Total;
	}	
}

//Dequeue
Elemento * Desenfileirar(Fila *F){
	Elemento *Ret = NULL;
	
	if (!Fila_Vazia(F)){
		Ret = F->Inicio;
		if (F->Inicio == F->Fim) {
			//1 elemento
			F->Inicio = NULL;
			F->Fim = F->Inicio;
		}
		else{
			//Mais de 1 elemento
			F->Inicio = F->Inicio->Prox;
		}
		--F->Total;			
	}
	
	return Ret;
}

//LIFO - Last In, First Out
//Push (Stack = pilha!!)
void Empilhar(Pilha *P, char C){
	Elemento *ptE;
	
	ptE = Criar_Elemento(C);
	if (ptE !=NULL){
		if (!Pilha_Vazia(P)){		
			//Atualiza o fim
			ptE->Prox = P->Topo;	
		}
				
		P->Topo = ptE;		
		++P->Total;
	}	
}

//Pop
Elemento * Desempilhar(Pilha *P){
	Elemento *Ret = NULL;
	
	if (!Pilha_Vazia(P)){
		Ret = P->Topo;
		P->Topo = P->Topo->Prox;		
		--P->Total;			
	}
	
	return Ret;
}


Fila F;
Pilha P;
Elemento *E;
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	/*A.Item = '1';
	A.Prox = &B;
	B.Item = '8';
	B.Prox = &C;
	C.Item = '-';
	C.Prox = NULL;*/
	/*
	Ini_Fila(&F);
	Enfileirar(&F, '1');
	Enfileirar(&F, '8');
	Enfileirar(&F, '-');
	
	Imprimir(F.Inicio);
	E = Desenfileirar(&F);
	Imprimir(F.Inicio);
	cout << "\nTotal: " << F.Total << " e retirou " << E->Item << endl;
	system("pause");
	E = Desenfileirar(&F);
	Imprimir(F.Inicio);
	cout << "\nTotal: " << F.Total << " e retirou " << E->Item<< endl;
	system("pause");
	E = Desenfileirar(&F);
	Imprimir(F.Inicio);
	cout << "\nTotal: " << F.Total << " e retirou " << E->Item<< endl;
	system("pause");
	E = Desenfileirar(&F);
	Imprimir(F.Inicio);
	cout << "\nTotal: " << F.Total << endl;
	system("pause");*/
	
	Ini_Pilha(&P);
	Empilhar(&P, '1');
	Empilhar(&P, '8');
	Empilhar(&P, '-');
	
	Imprimir(P.Topo);
	
	E = Desempilhar(&P);
	Imprimir(P.Topo);
	cout << "\nTotal: " << P.Total << " e retirou " << E->Item << endl;
	system("pause");
	E = Desempilhar(&P);
	Imprimir(P.Topo);
	cout << "\nTotal: " << P.Total << " e retirou " << E->Item << endl;
	system("pause");
	E = Desempilhar(&P);
	Imprimir(P.Topo);
	cout << "\nTotal: " << P.Total << " e retirou " << E->Item << endl;
	system("pause");
	E = Desempilhar(&P);
	Imprimir(P.Topo);
	cout << "\nTotal: " << P.Total << endl;
	system("pause");
	
	return 0;
}