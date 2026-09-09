/*
1 - Criar as estruturas:
1.1 - Estrutura para os itens: valor, prox
1.2 - Estrutura pro cabeçalho: início
2 - Funções de inicialização e lista_vazia
3 - Função menu
3.1 - Mostrar as opções dentro de um loop (do..while) com opção de saída
4 - Função de inserção (Exemplo de algoritmo)
4.1 - Criar o item na memória e gravar o valor: retorna o ponteiro pro item
4.2	- Inserir item no início 
4.2.1 - prox do item aponta para o início 
4.2.2 - início aponta pro item
4 - Função de remoção ...	
---------------------------------------------------------------------------------------------------------
LEMBRANDO: "->" é usado para acessar membros de uma estrutura através de um ponteiro, enquanto "." é usado para acessar membros de uma estrutura diretamente.
"->" pode ser entendido como: "pegue o ponteiro, vá para a estrutura que ele aponta e acesse o membro".

Esta atividade trabalha principalmente:

- Ponteiros;
- Endereços de memória;
- Alocação dinâmica;
- `malloc`;
- `free`;
- Estruturas (`struct`);
- Listas encadeadas;
- Nós;
- Ponteiro para o próximo nó;
- Percorrimento de listas;
- Inserção;
- Remoção;
- Busca;
- Criação de novas listas.
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

int Comprimento_Lista(Lista *L){ // Retorna o número de elementos da lista
	Item *Atual;// Ponteiro para percorrer a lista
	int cont = 0;

	Atual = L->Inicio;// Inicializa o ponteiro atual como o início da lista

	while(Atual != NULL){// Percorre a lista até chegar ao final
		cont++;
		Atual = Atual->Prox;// Atualiza o ponteiro atual para o próximo item
	}

	return cont;
}

int Contar_Valor(Lista *L, int N){ // Conta quantas vezes um valor aparece na lista
	Item *Atual; // Ponteiro para percorrer a lista
	int cont=0; 

	Atual = L->Inicio; // Inicializa o ponteiro atual como o início da lista

	while(Atual != NULL){
		if (Atual->Valor == N){ // Se o valor do item atual for igual a N, incrementa o contador
			cont++;
		}
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

void Menu(Lista *L1, Lista *L2){// Função menu para interagir com o usuário
	int Op, Valor;// Variáveis para armazenar a opção do usuário e o valor a ser inserido ou removido
	Lista* L;// Ponteiro para a lista selecionada
	
	do{
		system("cls");
		cout << "----------------- TESTE DE OPERAÇÕES COM LISTAS -----------------" << endl;
		cout << "1 - Inserir na lista (Lista 1 ou Lista 2)"<< endl;
		cout << "2 - Excluir da lista (Lista 1 ou Lista 2)"<< endl;
		cout << "3 - Imprimir"<< endl;
		cout << "4 - Comprimento da lista (Lista 1 ou Lista 2)" << endl;
		cout << "5 - Contar ocorrências (Lista 1 ou Lista 2)" << endl;
		cout << "6-  Trocar valores (Lista 1 ou Lista 2)" << endl;
		cout << "7 - Dividir uma lista em duas (Lista 1 ou Lista 2)"<< endl;
		cout << "8 - Intersecção das listas"<< endl;
		cout << "0 - Sair"<< endl;
		cout << "Opção: ";
		cin >> Op;
		
		switch(Op){
			case 1:
				// system("cls");
				cout << "----------------- INSERÇÃO -----------------" << endl;
				L = Selecionar_Lista(L1, L2);
				cout << "Digite um valor a ser inserido: ";
				cin >> Valor;
				Inserir_Item(L, Valor);
				break;
			case 2:
				// system("cls");
				cout << "----------------- EXCLUSÃO -----------------" << endl;
				L = Selecionar_Lista(L1, L2);
				cout << "Digite um valor a ser excluído: ";
				cin >> Valor;
				Remover_Item(L, Valor);
				break;	
			case 3:
				// system("cls");
				cout << "----------------- IMPRESSÃO -----------------" << endl;							
				cout << "LISTA 1: " ;
				Imprimir_Lista(L1);				
				cout << endl<< "LISTA 2: ";
				Imprimir_Lista(L2);
				
				// system("pause");
				break;
			
			case 4:
				cout << "----------------- COMPRIMENTO -----------------" << endl;
				L = Selecionar_Lista(L1, L2);

				cout << "Comprimento da lista escolhida: "<< Comprimento_Lista(L) << endl;
				break;

			case 5:
				cout << "----------------- CONTAR OCORRÊNCIAS -----------------" << endl;
				L = Selecionar_Lista(L1, L2);
				cout << "Digite um valor para contar as ocorrências: ";
				cin >> Valor;
				cout << "Quantidade de ocorrencias do valor " << Valor << " na lista escolhida: " << Contar_Valor(L, Valor) << endl;

			case 6:


			case 7:
				// system("cls");
				cout << "----------------- DIVISÃO -----------------" << endl;	
				L = Selecionar_Lista(L1, L2);	
				cout << "Digite um valor para dividir a lista em Maiores e Menores: ";
				cin >> Valor;		
							
				//Dividir_Lista(L, Valor);
				
				// system("pause");
				break;
			case 8:	
				//system("cls");
				cout << "----------------- INTERSECÇãO -----------------" << endl;	
				cout << "LISTA 1: " ;
				Imprimir_Lista(L1);				
				cout << endl << "LISTA 2: ";
				Imprimir_Lista(L2);						
				//L = Inter_Lista(L1, L2);
				cout << "Itens comuns: " ;
				Imprimir_Lista(L);
				//system("pause");
				break;									
			case 0:
				cout << endl << "Sair do programa? (0 = Sim, Outra tecla = Não)" << endl;
				cout << "Resposta: ";
				cin >> Op;				
				break;
			default:
				cout << "Opção inválida!!!" << endl;
				//system("pause");
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

	return 0;
}
