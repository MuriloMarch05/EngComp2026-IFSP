#include <iostream>
#include <stdlib.h> // Necessário para malloc e free
#include <string>

using namespace std;

// 1. Definição do Dado (Tipo Estruturado)
struct Evento {
    int id;
    string descricao;
};

// 2. Definição do Nó da Lista Encadeada
struct No {
    Evento dado;
    struct No *prox; // Ponteiro para o próximo "elo" da corrente
};

// Função para inserir um novo evento no início da lista
void inserirNoInicio(No* &inicio, int id, string desc) {
    // Alocação dinâmica de um novo nó usando malloc
    // sizeof(No) garante que pedimos o espaço exato para a estrutura
    No* novoNo = (No*) malloc(sizeof(No)); 

    if (novoNo == NULL) { // Verifica se a memória foi alocada com sucesso
        cout << "Erro ao alocar memória!" << endl;
        return;
    }

    // Preenchendo os dados do nó
    novoNo->dado.id = id;
    novoNo->dado.descricao = desc;

    // Fazendo o novo nó apontar para o antigo início da lista
    novoNo->prox = inicio;

    // Atualizando o ponteiro de início para este novo nó
    inicio = novoNo;
    cout << "Evento '" << desc << "' inserido com sucesso!" << endl;
}

// Função para percorrer e exibir a lista (Acesso Sequencial)
void exibirLista(No* inicio) {
    No* atual = inicio; // Ponteiro auxiliar para não perder o início da lista
    
    cout << "\n--- LISTA DE EVENTOS NA CIDADE ---" << endl;
    if (atual == NULL) {
        cout << "Lista vazia." << endl;
        return;
    }

    // Percorre a lista até encontrar o NULL (fim da sequência)
    while (atual != NULL) {
        cout << "ID: " << atual->dado.id << " | Descricao: " << atual->dado.descricao << endl;
        atual = atual->prox; // Pula para o próximo endereço de memória
    }
}

// Função para liberar toda a memória alocada (Limpeza)
void liberarMemoria(No* &inicio) {
    No* atual = inicio;
    while (atual != NULL) {
        No* proximo = atual->prox; // Salva o endereço do próximo antes de apagar o atual
        free(atual); // Devolve a memória ao sistema
        atual = proximo;
    }
    inicio = NULL;
    cout << "\nMemoria da lista liberada com sucesso." << endl;
}

int main() {
    // Ponteiro que indica o início da lista, inicialmente vazio
    No* listaCidIn = NULL;

    // Inserindo eventos dinamicamente
    inserirNoInicio(listaCidIn, 1, "Buraco na via");
    inserirNoInicio(listaCidIn, 2, "Vazamento de esgoto");
    inserirNoInicio(listaCidIn, 3, "Iluminacao publica queimada");

    // Exibindo os dados
    exibirLista(listaCidIn);

    // Sempre liberar a memória alocada com malloc ao finalizar
    liberarMemoria(listaCidIn);

    return 0;
}