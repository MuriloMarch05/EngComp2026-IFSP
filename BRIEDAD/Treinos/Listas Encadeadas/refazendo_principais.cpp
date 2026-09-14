/*
Código simples só com as funcoes principais que quase sempre iremos utilizar em listas encadeadas.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

// No caso, vou fazer uma lista de valores inteiros mesmo, igual o professor fez.

struct Item{ // Entao a gente comeca criando um novo tipo de dado, e nele a gente guarda o Item que queremos e um ponteiro do mesmo tipo para guardar o proximo Item. 
    int Valor;
    Item *Prox;
};

struct Lista{ // Depois, a gente cria um header para facilitar a navegaçao. Ele apenas guarda o endereco do primeiro item da lista.
    Item *Inicio;
};

// Agora, a gente começa, de fato, a adicionar as funcoes.

// Primeiro, criamos uma funcao para inicializar a lista, que no caso, começa vazia.

void Inicializar_Lista(Lista *L){ // Precisamos passar o ponteiro da lista pra ela como parâmetro. Pq ai ela altera na lista diretamente.
    L->Inicio = NULL; // Inicialmente ela começa vazia, por isso == NULL.
}

// Depois, vamos criar uma funcao que verifica se a lista esta vazia ou nao.
int Lista_Vazia(Lista *L){
    if(L->Inicio == NULL){
        return 1; // 1 = Verdadeiro (Sim, está vazia)
    }
    return 0;     // 0 = Falso (Não está vazia)

} // com isso a gente pode fazer verificacoes antes de tentar acessar a lista, pq se estiver vazia por exemplo, nem percorremos.

// Após isso, vamos criar uma funçao que cria as listas e inicializa elas, alocando a memoria necessaria com o malloc.

Lista* Criar_Lista(){ // Nao precisamos de parametros aqui. Veja que o tipo da funcao é Lista*, pois retornaremos o endereço da lista criada.
    Lista *L; // Criamos um ponteiro para a lista que será criada.

    L = (Lista*) malloc(sizeof(Lista)); // Alocamos e retornamos o endereço para dentro do ponteiro.

    // Após alocar, vemos se funcionou
    if(L != NULL){
        Inicializar_Lista(L); // Se alocou certinho, a gente puxa a funcao de inicializar.
    }
    return L; // Retornamos o endereço onde a lista foi alocada.
}

// Agora, vamos criar uma funçao que apaga uma lista inteira. 
// Pra que? Para evitar vazamento de memória. Apagamos a lista quando quisermos apagar (se houver a opcao no programa) ou no final da execucao.

void Liberar_Lista(Lista *L){ // Novamente, passamos como parâmetro *L. Lembrando: o asterisco * indica que a variável L guarda o endereço de memória da estrutura de lista.
    Item *Atual; // Ponteiro para percorrer os itens na lista
    Item *Prox; // Como vamos apagar um por um, precisamos desse ponteiro para ir guardando os itens seguintes antes de apagá-los.

    Atual = L->Inicio;

    while (Atual != NULL){
        Prox = Atual->Prox; // Primeiro a gente salva o próximo elemento.
        free(Atual); //  Limpamos o atual.
        Atual = Prox; // E assim passamos pro próximo, que foi salvo acima.
    }
    // Quando o laço acabar, a gente garante que a lista fique vazia:
    L->Inicio = NULL;
}

// Para a última funcao básica de lista, vamos criar uma de Impressão

void Imprimir_Lista(Lista *L){ // Passamos a lista como parametro
    Item *Atual; // fazemos aquele esquema pra navegar

    Atual = L->Inicio; // lembrando, aqui a gente faz o ponteiro Atual receber o começo da lista
    while(Atual != NULL){
        cout << Atual->Valor << " " << endl; // imprimimos
        Atual = Atual->Prox; // vamos passando de item em item
    }
}

// Pronto, a parte básica de listas a gente já fez. Ainda tem outra funcoes que podemos precisar, mas as essenciais sao essas.

// Agora, vamos para a parte dos Itens em si.
// Primeiro, vamos criar uma função de criacao de Itens para nossa lista

Item* Criar_Item(int Valor){ // Assim como fizemos na lista, também faremos na funcao de itens, ela retornará o endereço do item criado. Além disso, passamos o valor que queremos armazenar.
    Item *Elemento; // da mesma forma que fizemos na funcao de criar lista, faremos aqui. Criamos esse ponteiro para armazenar o endereço do valor criado.

    Elemento = (Item*) malloc(sizeof(Item));

    if(Elemento != NULL){
        Elemento->Valor = Valor; // Gravamos o valor no campo valor da struct Item.
        Elemento->Prox = NULL; // Inicializamos o próximo valor da lista como NULL.
    }

    return Elemento; // retornamos o endereço do item criado
}

// Feito isso, faremos a funcao de inserir o item na lista, pois a funcao acima apenas cria o item em si.

void Inserir_Item(Lista *L, int Valor){ // Nesse caso, vamos inserir no começo, pq é mais fácil.
    Item *Novo; // criamos um ponteiro para o Novo item

    Novo = Criar_Item(Valor); // Chamamos a funcao de criar item e gravamos o valor na memoria

    if (Novo != NULL){
        Novo->Prox = L->Inicio; // Salvamos o inicio da lista antes de alterar, para nao perder o nó
        L->Inicio = Novo; // Agora mudamos o valor inicial da lista pro novo valor.
    }
}

// Por fim, vamos fazer uma funcao de remocao de itens de uma lista.
void Remover_Item(Lista *L, int Valor){
    Item *Atual; // ponteiro para percorrer a lista
    Item *Anterior; // ponteiro para salvar o endereço do atual antes de apagar

    Atual = L->Inicio;
    Anterior = NULL; // como começamos no primeiro item da lista, por óbvio, o anterior é nulo

    while (Atual != NULL && Atual->Valor != Valor){ // percorre a lista ate achar ou ate acabar
        Anterior = Atual; // Guardamos o endereco do atual
        Atual = Atual->Prox; // Passamos pro proximo item
    }

    if (Atual == NULL){ // se apos percorrer, n achou o valor, exibe a msg
        cout << "Valor nao encontrado." << endl; 
    }
    // Depois, quando o laço terminar, temos algumas opções
    // 1. O item é o primeiro da lista
    else{
        if(Anterior == NULL){ // Ou seja, se o anterior é null, o atual é o primeiro. Nesse caso, atualizamos o inicio.
            L->Inicio = Atual->Prox; 
        }
        else{ // Se nao é o primeiro, atualiza atualizamos o prox do item anterior para pular o atual.
            Anterior->Prox = Atual->Prox;
        }

        // Depois de remover, precisamos liberar a memoria
        free(Atual);
        cout << "Valor removido com sucesso." << endl;
    }

}

int main() {
    // 1. Criar e inicializar a lista
    Lista *minhaLista = Criar_Lista();

    // 2. Testar se está vazia
    if (Lista_Vazia(minhaLista)) {
        cout << "A lista esta vazia!" << endl;
    }

    // 3. Inserir elementos (como insere no início, a ordem final impressa será invertida)
    Inserir_Item(minhaLista, 10);
    Inserir_Item(minhaLista, 20);
    Inserir_Item(minhaLista, 30);

    cout << "\n--- Conteudo da Lista ---" << endl;
    Imprimir_Lista(minhaLista);

    // 4. Remover um item do meio/início
    cout << "\nRemovendo o valor 20..." << endl;
    Remover_Item(minhaLista, 20);

    cout << "\n--- Conteudo da Lista apos remocao ---" << endl;
    Imprimir_Lista(minhaLista);

    // 5. Testar remoção de valor inexistente
    cout << "\nTentando remover o valor 99..." << endl;
    Remover_Item(minhaLista, 99);

    // 6. Liberar a memória dos nós e do nó descritor
    Liberar_Lista(minhaLista);
    free(minhaLista); // Libera o ponteiro do cabeçalho alocado no Criar_Lista
    minhaLista = NULL;

    cout << "\nMemoria liberada com sucesso!" << endl;

    return 0;
}