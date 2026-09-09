#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Ocorrencia{
	int Codigo;
	char Descricao[20];
	Ocorrencia *prox;
};
//Header
struct Lista{
	Ocorrencia *inicio;
	int Total;
};

//Inicializacao da lista, lista vazia, inserção, busca e remoção;

void inicializar(Lista *L){
	L->inicio = NULL;
	L->Total = 0;
	
}

bool Lista_vazia(Lista *L){
	return (L->inicio == NULL);
	
}
Ocorrencia * Cria_Ocorrencia(int Codigo, const char* Desc){
	Ocorrencia *Ret;
	Ret = (Ocorrencia *) malloc(sizeof(Ocorrencia));
	if (Ret!=NULL){
		Ret->Codigo = Codigo;
		strcpy(Ret->Descricao, Desc);
		Ret->prox = NULL;			
	}
	
	return Ret;
}

void Insere_ocorrencia(Lista *L, int Codigo, const char* Desc){
	Ocorrencia *ptO;
	
	ptO = Cria_Ocorrencia(Codigo, Desc);
	
	if (ptO != NULL){ // insere na cabe�a
		ptO->prox = L->inicio;
		L->inicio = ptO;
		
		++L->Total;
	}
}

void Remover(Lista *L, int Codigo){
	Ocorrencia *ptO, *aux;
	
	if (!Lista_vazia(L)){
		ptO = L->inicio;
		if (L->inicio->Codigo == Codigo){
			// Atualiza o header
			L->inicio = L->inicio->prox;
			free(ptO);
		}
		else{ // Atualiza o meio
			while(ptO->prox != NULL && ptO->prox->Codigo != Codigo){
				ptO = ptO->prox;
			}
			
			if (ptO->prox){ // Atualizar ligações
				aux = ptO->prox;
				ptO->prox = ptO->prox->prox;
				free(aux);
				--L->Total;
			}
		}
	}
}


Ocorrencia * Buscar(Lista *L, int Codigo){
	Ocorrencia *ptO, *Pos=NULL; // Ocorrência não encontrada 
	
	for (ptO = L->inicio; ptO!=NULL && Pos == NULL; ptO = ptO->prox){
		if(ptO->Codigo == Codigo){
			Pos = ptO;
		}
	}
	
	return Pos;
}
void Imprimir(Ocorrencia *V){
	Ocorrencia *ptO;
	
	for (ptO = V; ptO!=NULL; ptO = ptO->prox){
		cout << ptO->Codigo << "(" << ptO->Descricao << ")" << endl;
	}
	
}

int Contar_Elementos(Ocorrencia *V){
	Ocorrencia *ptO;
	int Total = 0;
	
	for(ptO=V; ptO!=NULL; ptO=ptO->prox){
		++Total;
	}
	
	return Total;
}

Lista Lst;
Ocorrencia *ptO;
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	inicializar (&Lst);
	Insere_ocorrencia(&Lst, 1, "Buraco");
	Insere_ocorrencia(&Lst, 2, "Ilumina��o");
	Insere_ocorrencia(&Lst, 3, "Acidente");
	Insere_ocorrencia(&Lst, 4, "Buraco 2");
	Insere_ocorrencia(&Lst, 5, "Ilumina��o 2");
	Insere_ocorrencia(&Lst, 6, "Acidente 2");
	Imprimir(Lst.inicio);
	cout << "\nTotal: " << Lst.Total;
	
	/*ptO = Buscar(&Lst, 4);
	if (ptO){
		cout << endl <<"Ocorrencia: " << ptO->Descricao << " encontrada!";
	}
	else{
		cout << "\nOcorrencia nao encontrada!";
	}*/
	
	Remover(&Lst, 4);
	Imprimir(Lst.inicio);
	
	return 0;
}
