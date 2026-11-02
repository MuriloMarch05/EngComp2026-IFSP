#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct expre {
	char carac;
	expre* prox;
};

struct Fila {
	expre *Inicio;
	expre *Fim;
};

struct Pilha {
	expre *Topo;
};

void Inicializar_Fila(Fila *f) {
	f->Inicio = NULL;
	f->Fim = NULL;
}

expre *Criar_Elemento(char C) {
	expre *ret;
	ret = (expre*)malloc(sizeof(expre));
	if (ret != NULL) {
		ret->carac = C;
		ret->prox = NULL;
	}
	return ret;
}

bool Fila_Vazia(Fila *f) {
	return (f->Inicio == NULL);
}

void Enqueue(char C, Fila *f) {
	expre *Elemento;
	Elemento = Criar_Elemento(C);
	if (Elemento != NULL) {
		if (Fila_Vazia(f)) {
			f->Inicio = Elemento;
		}
		else {
			f->Fim->prox = Elemento;
		}
		f->Fim = Elemento;
	}
}

void Ini_Pilha(Pilha *p) {
	p->Topo = NULL;
}

bool Pilha_Vazia(Pilha *p) {
	return (p->Topo == NULL);
}

void Empilhar(char C, Pilha *p) {
	expre* Elemento;
	Elemento = Criar_Elemento(C);
	if (Elemento != NULL) {
		if (!Pilha_Vazia(p)) {
			Elemento->prox = p->Topo;
		}
		p->Topo = Elemento;
	}
}

void Desempilhar(Pilha *P) {
	expre *Ret = NULL;
	
	if (!Pilha_Vazia(P)) {
		Ret = P->Topo;
		P->Topo = P->Topo->prox;				
		free(Ret); // Libera a memória do nó removido
	}
}

bool Validar_Parenteses(Fila *f) {
	Pilha p;
	Ini_Pilha(&p);

	bool valido = true; // Variável de controle para ter apenas um return
	expre *pto;

	for (pto = f->Inicio; pto != NULL && valido; pto = pto->prox) {
		if (pto->carac == '(') {
			Empilhar('(', &p);
		}
		else{
            if(pto->carac == ')'){
                if(Pilha_Vazia(&p)){
                    valido = false;
                }
            }
            else{
                Desempilhar(&p);
            }
        }
    }
	// Válido se não houve erros E a pilha terminou vazia (sem sobras)
	return (valido && Pilha_Vazia(&p));
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	string Expressao;
	Fila f;
	
	Inicializar_Fila(&f);
	
	cout << "Digite uma expressao numerica: ";
	getline(cin, Expressao);
	
	// Enfileirando a expressão caractere por caractere
	for (int i = 0; i < (int)Expressao.size(); i++) {
		Enqueue(Expressao[i], &f);
	}
	
	// Apenas valida e exibe o resultado
	if (Validar_Parenteses(&f)) {
		cout << "\nA expressao e valida\n";
	}
	else {
		cout << "\nA expressao e invalida\n";
	}
	
	return 0;
}