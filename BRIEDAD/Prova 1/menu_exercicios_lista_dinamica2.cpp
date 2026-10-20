/*

Suponha DUAS listas dinâmicas encadeadas de números inteiros NÃO ORDENADAS (elementos podem ser inseridos sem ordenação e, no caso da lista dinâmica, é mais fácil inserir sempre no início). Implemente as seguintes rotinas em C++. 

-Uma função que receba como parâmetros uma lista encadeada e um número inteiro a ser inserido na lista;

-Uma função que receba como parâmetros uma lista encadeada e um número inteiro a ser removido da lista;

-Uma função que receba como parâmetro uma lista encadeada e imprima a lista na tela;
---------------------------------------------------------------------------------------------------------

-Uma função que tenha como valor de retorno o comprimento de uma lista encadeada passada como parâmetro;

-Uma função que receba como parâmetros uma lista encadeada e um número inteiro n e retorne o número de nós da lista que possuem o número inteiro (campo da lista) com valores iguais a n;

-Uma função que receba como parâmetros uma lista encadeada e dois números (original e novo) e troque todas as ocorrências do número original pelo número novo. 
Após o retorno da lista resultante, a mesma deve ser impressa na tela (função Imprimir);

-Uma função que receba como parâmetro uma lista encadeada e um valor inteiro n, e retorne duas listas, 
de tal forma que a primeira lista possua todos os elementos que são maiores que n e a segunda lista possua todos os elementos que são menores do que n. 
Após o processamento da função, as duas listas devem ser impressas na tela (função Imprimir). Considere uma lista qualquer não ordenada;

-Uma função que construa uma nova lista a partir dos números que fazem parte de duas listas passadas como parâmetros. 
Essa função deve receber como parâmetro as duas listas a serem comparadas e retornar a lista resultante com os elementos que fazem parte da interseção. 
Após o retorno da lista resultante, a mesma deve ser impressa na tela (função Imprimir). Considere duas listas quaisquer não ordenadas.

---------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Item{ // Estrutura para os itens
	int Valor;
	Item *Prox;
};

struct Lista{ // Estrutura para o cabeçalho (header)
	Item *Inicio;
};

void Ini_Lista(Lista *L){ // Inicializa a lista, lista vazia
	L->Inicio = NULL;
}

int Lista_Vazia(Lista *L){ //1 - Vazia e 0 - Tem elementos
	int Ret = 1; 
	
	if (L->Inicio != NULL){ // Se o início não for nulo, a lista não está vazia
		Ret = 0;
	}
	
	return Ret;
}

Lista* Criar_Lista(){ // Cria a lista na memória e inicializa
	Lista *L;// Ponteiro para a lista
	
	L = (Lista *) malloc(sizeof(Lista)); // Aloca memória para a lista

	if (L != NULL){ // Se a alocação foi bem-sucedida, inicializa a lista
		Ini_Lista(L);
	}
	
	return L;
}

void Liberar_Lista(Lista *L){
	Item *Atual; // Ponteiro para percorrer a lista
	Item *Prox; // Guarda o próximo antes de liberar o atual

	Atual = L->Inicio;

	while(Atual != NULL){
		Prox = Atual->Prox; // Salva o próximo antes de liberar
		free(Atual); // Libera o nó atual
		Atual = Prox; // Avança para o próximo
	}

	L->Inicio = NULL; // Esvazia a lista

}

Item* Criar_Item(int Valor){ // Cria o item na memória e grava o valor
	Item *Elemento; // Ponteiro para o novo item
	
	Elemento = (Item *) malloc(sizeof(Item)); // Aloca memória para o item

	if (Elemento != NULL){ 
		Elemento->Valor  = Valor; // Grava o valor no item
		Elemento->Prox = NULL; // Inicializa o próximo como NULL
	}
	
	return Elemento;
}

void Inserir_Item(Lista *L, int Valor){ // Insere o item no início da lista
	Item *Novo;// Ponteiro para o novo item

	Novo = Criar_Item(Valor); // Cria o item na memória e grava o valor

	if (Novo != NULL){ 
		Novo->Prox = L->Inicio; // O próximo do novo item aponta para o início da lista
		L->Inicio = Novo;// O início da lista aponta para o novo item
	}

}

void Remover_Item(Lista *L, int Valor){ // Remove o item da lista
	Item *Atual; // Ponteiro para percorrer a lista
	Item *Anterior; // Ponteiro para o item anterior ao atual

	Atual = L->Inicio; // Inicializa o ponteiro atual como o início da lista
	Anterior = NULL; // Inicializa o ponteiro anterior como NULL

	while(Atual != NULL && Atual->Valor != Valor){ // Percorre a lista até encontrar o item ou chegar ao final
		Anterior = Atual; // Atualiza o ponteiro anterior para o atual
		Atual = Atual->Prox; // Atualiza o ponteiro atual para o próximo item
	}

	if (Atual == NULL){ // Se o item não foi encontrado, exibe uma mensagem
		cout << "Valor não encontrado." << endl;
	}
	else{
		if (Anterior == NULL){ // Se o item a ser removido é o primeiro da lista, atualiza o início da lista
			L->Inicio = Atual->Prox;
		}
		else{
			Anterior->Prox = Atual->Prox; // Se o item a ser removido não é o primeiro, atualiza o próximo do item anterior para pular o item atual
		}

		free(Atual); // Libera a memória do item removido
		cout << "Valor removido com sucesso." << endl;
	}
}

int Comprimento_Lista(Lista *L){
	Item *Atual;
	int cont=0;

	Atual = L->Inicio;

	while(Atual != NULL){
		++cont;
		Atual = Atual->Prox;
	}

	return cont;
}

int Contar_Valor(Lista *L, int valor){
	Item *Atual;
	int cont=0;

	Atual = L->Inicio;

	while (Atual != NULL){
		if (Atual->Valor == valor){
			cont++;
		}
		Atual = Atual->Prox;
	}

	return cont;
}

Lista* Selecionar_Lista(Lista *L1, Lista *L2){// Permite ao usuário selecionar uma das duas listas
	int Op;
	Lista *L;// Ponteiro para a lista selecionada
	
	do{
		cout << endl << "Qual lista deseja utilizar? (Lista 1 = [1], Lista 2 [2])" << endl;
		cout << "Resposta: ";                                                                                                                          		
		cin >> Op;
		if (Op!=1 && Op!=2){
			cout << endl << "Lista inválida!!" << endl;
		}
		else{
			if (Op==1){
				L = L1;	
			}
			else{
				L = L2;
			}
		}
	}while (Op!=1 && Op!=2);
	
	return L;
}

void Imprimir_Lista(Lista *L){ // Imprime os elementos da lista
	Item *Atual;// Ponteiro para percorrer a lista
	
	Atual = L->Inicio;// Inicializa o ponteiro atual como o início da lista
	
	while(Atual != NULL){
		cout << Atual->Valor << " ";
		Atual = Atual->Prox;// Atualiza o ponteiro atual para o próximo item
	}
	
	cout << endl;
	
}


void trocar_sentido(Lista *L){
	Item *Atual;

	Atual = L->Inicio;

	while (Atual != NULL){

		Atual = Atual->Prox;
	}
}
void Trocar_Valor(Lista *L, int valor_original, int valor_novo){
	Item *Atual;

	Atual = L->Inicio;

	while(Atual != NULL){

		if(Atual->Valor == valor_original){
			Atual->Valor = valor_novo;
		}

		Atual = Atual->Prox;
	}

	Imprimir_Lista(L);
}

void Dividir_Lista(Lista *L, int valor){
	Lista *Maiores;
	Lista *Menores;
	Item *Atual;

	Maiores = Criar_Lista();
	Menores = Criar_Lista();

	Atual = L->Inicio;

	while(Atual != NULL){
		if(Atual->Valor > valor){
			Inserir_Item(Maiores, Atual->Valor);
		}
		else{
			if(Atual->Valor < valor){
				Inserir_Item(Menores, Atual->Valor);
			}
		}
		Atual = Atual->Prox;
	}
	cout << "Valores maiores que " << valor << ":" << endl;
	Imprimir_Lista(Maiores);
	cout << "\nValores menores que " << valor << ":" << endl;
	Imprimir_Lista(Menores);

	Liberar_Lista(Maiores);
	free(Maiores);
	Liberar_Lista(Menores);
	free(Menores);
}

int Existe_Valor(Lista *L, int valor){
	Item *Atual;

	Atual = L->Inicio;

	while (Atual != NULL){
		if(Atual->Valor == valor){
			return 1; // tem 
		}
		Atual = Atual->Prox;
	}

	return 0;
}

Lista* Inter_Lista(Lista *L1, Lista *L2){
	Item *Atual;
	Lista *Resultante;

	Atual = L1->Inicio;

	while(Atual != NULL){
		if (Existe_Valor(L2, Atual->Valor) && !Existe_Valor(Resultante, Atual->Valor)){
			Inserir_Item(Resultante, Atual->Valor);
		}
		Atual = Atual->Prox;
	}

	return Resultante;
}

void Menu(Lista *L1, Lista *L2){// Função menu para interagir com o usuário
	int Op, Valor, Valor_Novo;// Variáveis para armazenar a opção do usuário e o valor a ser inserido ou removido
	Lista* L;// Ponteiro para a lista selecionada
	Lista *L_Inter; // Guarda o resultado da interseção (pra poder liberar depois)
	do{
		system("clear");
		cout << "----------------- TESTE DE OPERAÇÕES COM LISTAS -----------------" << endl;
		cout << "1 - Inserir na lista (Lista 1 ou Lista 2)"<< endl;
		cout << "2 - Excluir da lista (Lista 1 ou Lista 2)"<< endl;
		cout << "3 - Imprimir"<< endl;
		//cout << "4 - Comprimento da lista" << endl;
		//cout << "5 - Contar ocorrências" << endl;
		//cout << "6 - Trocar valores" << endl;
		//cout << "7 - Dividir uma lista em duas"<< endl;
		//cout << "8 - Intersecção das listas"<< endl;
		cout << "0 - Sair"<< endl;
		cout << "Opção: ";
		cin >> Op;
		
		switch(Op){
			case 1:
				system("clear");
				cout << "----------------- INSERÇÃO -----------------" << endl;
				L = Selecionar_Lista(L1, L2);
				cout << "Digite um valor a ser inserido: ";
				cin >> Valor;
				Inserir_Item(L, Valor);
				break;
			case 2:
				system("clear");
				cout << "----------------- EXCLUSÃO -----------------" << endl;
				L = Selecionar_Lista(L1, L2);
				cout << "Digite um valor a ser excluído: ";
				cin >> Valor;
				Remover_Item(L, Valor);
				break;	
			case 3:
				system("clear");
				cout << "----------------- IMPRESSÃO -----------------" << endl;							
				cout << "LISTA 1: " ;
				Imprimir_Lista(L1);				
				cout << endl<< "LISTA 2: ";
				Imprimir_Lista(L2);
				
				cout << endl << "Pressione ENTER para continuar...";
				cin.ignore();   // limpa o \n deixado pelo cin anterior
				cin.get();      // espera ENTER
				break;
			
			case 4:
				system("clear");
				cout << "----------------- COMPRIMENTO -----------------" << endl;
				L = Selecionar_Lista(L1, L2);

				cout << "Comprimento da lista escolhida: "<< Comprimento_Lista(L) << endl;
				
				cout << endl << "Pressione ENTER para continuar...";
				cin.ignore();   // limpa o \n deixado pelo cin anterior
				cin.get();      // espera ENTER
				break;

			case 5:
				system("clear");
				cout << "----------------- CONTAR OCORRÊNCIAS -----------------" << endl;
				L = Selecionar_Lista(L1, L2);
				cout << "Digite um valor para contar as ocorrências: ";
				cin >> Valor;
				cout << "Quantidade de ocorrencias do valor " << Valor << " na lista escolhida: " << Contar_Valor(L, Valor) << endl;
				
				cout << endl << "Pressione ENTER para continuar...";
				cin.ignore();   // limpa o \n deixado pelo cin anterior
				cin.get();      // espera ENTER
				break;
			case 6:
				system("clear");
				cout << "----------------- TROCAR VALORES -----------------" << endl;
				L= Selecionar_Lista(L1, L2);
				cout << "Digite o valor a ser trocado: ";
				cin >> Valor;
				cout << "Valor novo: ";
				cin >> Valor_Novo;
				cout << "Lista após troca: " << endl;
				Trocar_Valor(L, Valor, Valor_Novo);

				cout << endl << "Pressione ENTER para continuar...";
				cin.ignore();   // limpa o \n deixado pelo cin anterior
				cin.get();      // espera ENTER
				break;


			case 7:
				system("clear");
				cout << "----------------- DIVISÃO -----------------" << endl;	
				L = Selecionar_Lista(L1, L2);	
				cout << "Digite um valor para dividir a lista em Maiores e Menores: ";
				cin >> Valor;					
				Dividir_Lista(L, Valor);
				
				cout << endl << "Pressione ENTER para continuar...";
				cin.ignore();   // limpa o \n deixado pelo cin anterior
				cin.get();      // espera ENTER
				break;

			case 8:	
				system("clear");
				cout << "----------------- INTERSECÇãO -----------------" << endl;	
				cout << "LISTA 1: " ;
				Imprimir_Lista(L1);				
				cout << endl << "LISTA 2: ";
				Imprimir_Lista(L2);						
				L_Inter = Inter_Lista(L1, L2);
				cout << "Itens comuns: " ;
				Imprimir_Lista(L_Inter);

				Liberar_Lista(L_Inter); //  Libera os nós da interseção
				free(L_Inter); // Libera a struct Lista

				cout << endl << "Pressione ENTER para continuar...";
				cin.ignore();   // limpa o \n deixado pelo cin anterior
				cin.get();      // espera ENTER
				break;								
			case 0:
				system("clear");
				cout << endl << "Sair do programa? (0 = Sim, Outra tecla = Não)" << endl;
				cout << "Resposta: ";
				cin >> Op;				
				break;
			default:
				cout << "Opção inválida!!!" << endl;

				cout << endl << "Pressione ENTER para continuar...";
				cin.ignore();   // limpa o \n deixado pelo cin anterior
				cin.get();      // espera ENTER
		}
		
	}while (Op != 0);
}

Lista *L1, *L2;// Ponteiros para as duas listas
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	L1 = Criar_Lista(); // Cria a Lista 1 na memória
	Ini_Lista(L1); // Inicializa a Lista 1
	
	L2 = Criar_Lista(); // Cria a Lista 2 na memória
	Ini_Lista(L2);// Inicializa a Lista 2
	
	Menu(L1, L2); // Chama a função menu para interagir com o usuário

	Liberar_Lista(L1); // Libera os nós da lista 1
	free(L1); // Libera a struct Lista 1
	Liberar_Lista(L2); // Libera os nós da lista 2
	free(L2); // Libera a struct Lista 2

	return 0;
}
