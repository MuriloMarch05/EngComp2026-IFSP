/*
Apenas para treinar o básico das listas de novo.
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Evento{
    char Descricao[50];
    int ID;
    int prioridade;
    Evento *Prox;
};

struct Lista{
    Evento *Inicio;
};

void Inicializar_Lista(Lista *L){
    L->Inicio = NULL;
}

int Lista_Vazia(Lista *L){
    if (L->Inicio == NULL){
        return 1; // sim, esta vazia
    }
    return 0; 
}

Lista* Criar_Lista(){
    Lista *L;

    L = (Lista*) malloc(sizeof(Lista));

    if (L != NULL){
        Inicializar_Lista(L);
    }

    return L;
}

Evento* Criar_Evento(int id, const char descricao[], int prioridade){
    Evento *E;

    E = (Evento*) malloc(sizeof(Evento));

    if (E != NULL){
        E->ID = id;
        strcpy(E->Descricao, descricao);
        E->prioridade = prioridade;
        E->Prox = NULL;
    }

    return E;
}

void Inserir_Evento(Lista *L, int id, const char descricao[], int prioridade){
    Evento *Novo;

    Novo = Criar_Evento(id, descricao, prioridade);

    if (Novo != NULL){
        Novo->Prox = L->Inicio;
        L->Inicio = Novo;
    }

}

void Remover_Evento(Lista *L, int id){
    Evento *Atual;
    Evento *Anterior;

    Atual = L->Inicio;
    Anterior = NULL;

    while(Atual != NULL && Atual->ID != id){
        Anterior = Atual;
        Atual = Atual->Prox;
    }

    if (Atual == NULL){
        cout << "Evento nao encontrado." << endl;
    }
    else{
        if (Anterior == NULL){
            L->Inicio = Atual->Prox;
        }
        else{
            Anterior->Prox = Atual->Prox;
        }
        free(Atual);
        cout << "Evento removido." << endl;
    }
}

void Imprimir_Lista(Lista *L){
    Evento *Atual;
    int i=0;
    Atual = L->Inicio;

    while(Atual != NULL){
        ++i;
        cout << "Evento[" << i << "]" <<endl;
        cout << "ID: " << Atual->ID << endl;
        cout << "Descrição: " << Atual->Descricao << endl;
        cout << "Prioridade: " << Atual->prioridade << endl;
        cout << "----------" << endl;
        Atual = Atual->Prox;
    }
}

void Ordenar_Eventos(Lista *L){
    Evento *Atual;
    Evento *Fim;
    int trocou;
    Fim = NULL;
    
    do{
        trocou = 0;
        Atual = L->Inicio;

        while(Atual->Prox != Fim){
            if (Atual->prioridade < Atual->Prox->prioridade){
                swap(Atual->ID, Atual->Prox->ID);
                swap(Atual->Descricao, Atual->Prox->Descricao);
                swap(Atual->prioridade, Atual->Prox->prioridade);
                trocou = 1;
            }

            Atual = Atual->Prox;
        }

        Fim = Atual;

    }while (trocou);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int op;
    int id, prioridade=0;
    char descricao[50];
    Lista *Lista_Eventos;

    Lista_Eventos = Criar_Lista();

    do{
        system("clear");
        cout << "===== CIDADE COM OS BO =====" << endl;
        cout << "[1] - Cadastrar Evento" << endl;
        cout << "[2] - Imprimir lista de eventos" << endl;
        cout << "[3] - Remover evento" << endl;
        cout << "[0] - Sair" << endl;
        cout << "Opção: ";
        cin >> op;
        cin.ignore();

        switch(op){
            case 1:
            cout << "===== CADASTRO DE EVENTOS =====" << endl;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Descrição: ";
            cin.getline(descricao, 50);
            cout << "Prioridade [1-5]: ";
            cin >> prioridade;
            cin.ignore();
            Inserir_Evento(Lista_Eventos, id, descricao, prioridade);
            cout << "Pressione ENTER...";
            cin.get();
            break;

            case 2:
            cout << "===== EVENTOS =====" << endl;
            Ordenar_Eventos(Lista_Eventos);
            Imprimir_Lista(Lista_Eventos);
            cout << "Pressione ENTER...";
            cin.get();
            break;

            case 3:
            cout << "===== REMOÇÃO =====" << endl;
            cout << "Digite o ID do evento a ser removido: ";
            cin >> id;
            cin.ignore();
            Remover_Evento(Lista_Eventos, id);
            cout << "Pressione ENTER...";
            cin.get();
            break;

            case 0:
            cout << "Saindo..." << endl;
            break;
            
            default:
            cout << "Opção inválida." << endl;
            break;
        }

    }while(op != 0);

    return 0;
}