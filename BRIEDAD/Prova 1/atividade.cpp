/*
Questão Prática: Gestão de Eventos Urbanos

Contexto: Você está desenvolvendo o núcleo de um sistema para uma "Cidade Inteligente". 
O sistema deve armazenar ocorrências (como buracos na via ou vazamentos) em uma lista encadeada dinâmica.

Tarefa:

1. Defina uma `struct Ocorrencia` contendo um `id` (inteiro) e uma `descricao` (string).
2. Defina a `struct No` que formará a lista encadeada.
3. Defina uma `struct Descritor` (o Header da lista) que guarde o ponteiro para o `inicio` e um inteiro total.
4. Implemente a função: `void adicionarOcorrencia(Descritor *lista, int id, string desc)`
  * A função deve alocar dinamicamente um novo nó usando `malloc` ou `new.
  * Deve inserir esse novo nó no **início** da lista.
  * Deve atualizar o ponteiro de início e incrementar o contador `total` no descritor.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Evento{
    int id;
    string descricao;
    Evento *prox;
};

struct Lista{
    Evento *Inicio;
    int total;
};

void inicializar_lista(Lista *L){
        L->Inicio = NULL; // Inicializar a lista vazia
}

int lista_vazia(Lista *L){
    if (L->Inicio == NULL){
        return 1;
    }
    return 0;
}

Lista* Criar_Lista(){
    Lista *L;
    L = (Lista*) malloc(sizeof(Lista));

    if (L != NULL){
        inicializar_lista(L);
    }

    return L;
}

Evento* Criar_Evento(int id, string descricao){
    Evento *E;

    E = (Evento*) malloc(sizeof(Evento));

    if (E != NULL){
        E->id = id;
        E->descricao = descricao;
        E->prox = NULL; 
    }

    return E;
}

void Adicionar_Evento(Lista *L, int id, string descricao){
    Evento *Novo;

    Novo = Criar_Evento(id, descricao);

    if(Novo != NULL){
        Novo->prox = L->Inicio;
        L->Inicio = Novo;
    }

}

void Remover_Evento(Lista *L, int id){
    Evento *Atual;
    Evento *Anterior;

    Atual = L->Inicio;
    Anterior = NULL;

    while(Atual != NULL && Atual->id != id){
        Anterior = Atual;
        Atual = Atual->prox;
    }

    if (Atual == NULL){
        cout << "Evento com ID" << id << " não encontrado." << endl;
    }
    else{
        if(Anterior == NULL){
            L->Inicio = Atual->prox;
        }
        else{
            Anterior->prox = Atual->prox;
        }
        free(Atual);
        cout << "Evento removido." << endl;
    }

}

void imprimir_lista(Lista *L){
    Evento *Atual;
    int cont=0;

    Atual = L->Inicio;

    while (Atual != NULL){
        ++cont;
        cout << "Evento[" << cont << "]" << endl;
        cout << "ID: " << Atual->id << endl;
        cout << "Descrição: " << Atual->descricao << endl;
        cout << "----------" << endl;
        Atual = Atual->prox;
    }

}
int main(){
    setlocale(LC_ALL, "Portuguese");
    int Op, id;
    string descricao;
    Lista *Lista1;

    Lista1 = Criar_Lista();

    do{
        system("clear");
        cout << "[1] - Cadastrar evento" << endl;
        cout << "[2] - Imprimir eventos" << endl;
        cout << "[3] - Remover evento" << endl;
        cout << "[0] - Sair" << endl;
        cout << "Opção: ";
        cin >> Op;
        cin.ignore();

        switch(Op){
            case 1:
                cout << "===== CADASTRAR EVENTO =====" << endl;
                cout << "ID: ";
                cin >> id;
                cin.ignore();
                cout << "Descrição do evento: ";
                getline(cin, descricao);
                Criar_Evento(id, descricao);
                Adicionar_Evento(Lista1,id,descricao);
                cout << "Pressione ENTER...";
                cin.get();
                break;
            case 2:
                cout << "===== EVENTOS =====" << endl;
                imprimir_lista(Lista1);
                cout << "Pressione ENTER...";
                cin.get();
                break;

            case 3:
                cout << "===== REMOVER EVENTO =====" << endl;
                cout << "Digite o id do evento a ser removido: ";
                cin >> id;
                cin.ignore();
                Remover_Evento(Lista1, id);
                cout << "Pressione ENTER...";
                cin.get();

            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }

    }while(Op != 0);

    return 0;
}