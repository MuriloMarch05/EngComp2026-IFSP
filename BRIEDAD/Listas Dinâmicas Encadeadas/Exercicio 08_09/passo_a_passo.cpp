/*# Roteiro da atividade — Listas Dinâmicas Encadeadas

## 1 - Criar as estruturas:

### 1.1 - Estrutura para os itens:

* Valor
* Próximo (`Prox`)

### 1.2 - Estrutura para o cabeçalho:

* Início (`Inicio`)

---

## 2 - Funções de inicialização e lista_vazia

### 2.1 - Função de inicialização da lista:

* Receber uma lista como parâmetro.
* Fazer `Inicio` apontar para `NULL`.

### 2.2 - Função para verificar se a lista está vazia:

* Verificar se `Inicio` é igual a `NULL`.
* Retornar:

  * `1` se a lista estiver vazia;
  * `0` se a lista possuir elementos.

---

## 3 - Função Menu

### 3.1 - Mostrar as opções dentro de um loop (`do...while`) com opção de saída.

### 3.2 - Utilizar `switch...case` para executar a operação escolhida.

### 3.3 - As opções do menu devem permitir:

* Inserção;
* Exclusão;
* Impressão;
* Comprimento da lista;
* Contagem de ocorrências;
* Troca de valores;
* Divisão da lista;
* Interseção das listas;
* Saída do programa.

---

## 4 - Função de inserção

### 4.1 - Criar o item na memória e gravar o valor:

* Alocar memória para um novo item;
* Gravar o valor recebido no campo `Valor`;
* Inicializar `Prox` como `NULL`;
* Retornar o ponteiro para o item criado.

### 4.2 - Inserir o item no início da lista.

#### 4.2.1 - `Prox` do novo item aponta para o início atual da lista.

#### 4.2.2 - `Inicio` da lista passa a apontar para o novo item.

---

## 5 - Função de remoção

### 5.1 - Receber como parâmetros:

* Uma lista encadeada;
* Um número inteiro a ser removido.

### 5.2 - Criar os ponteiros necessários para percorrer a lista:

* Ponteiro para o item atual;
* Ponteiro para o item anterior.

### 5.3 - Iniciar o ponteiro atual no primeiro item da lista.

### 5.4 - Iniciar o ponteiro anterior como `NULL`.

### 5.5 - Percorrer a lista procurando o valor que deverá ser removido.

### 5.6 - Quando o valor for encontrado:

#### 5.6.1 - Se o item estiver no início:

* Fazer `Inicio` apontar para o próximo item.

#### 5.6.2 - Se o item estiver no meio ou no final:

* Fazer o `Prox` do item anterior apontar para o próximo item do item que será removido.

### 5.7 - Liberar da memória o item removido.

### 5.8 - Caso o valor não seja encontrado:

* Informar que o valor não existe na lista.

---

## 6 - Função de impressão

### 6.1 - Receber uma lista encadeada como parâmetro.

### 6.2 - Criar um ponteiro para percorrer a lista.

### 6.3 - Iniciar o ponteiro no primeiro item (`Inicio`).

### 6.4 - Percorrer a lista enquanto o ponteiro não for `NULL`.

### 6.5 - Imprimir o campo `Valor` de cada item.

### 6.6 - Avançar para o próximo item através de `Prox`.

---

## 7 - Função para calcular o comprimento da lista

### 7.1 - Receber uma lista encadeada como parâmetro.

### 7.2 - Criar um contador iniciado em `0`.

### 7.3 - Criar um ponteiro para percorrer a lista.

### 7.4 - Iniciar o ponteiro em `Inicio`.

### 7.5 - Percorrer a lista até encontrar `NULL`.

### 7.6 - A cada item encontrado:

* Incrementar o contador.

### 7.7 - Retornar o contador.

---

## 8 - Função para contar ocorrências de um valor

### 8.1 - Receber como parâmetros:

* Uma lista encadeada;
* Um número inteiro `N`.

### 8.2 - Criar um contador iniciado em `0`.

### 8.3 - Percorrer todos os itens da lista.

### 8.4 - Comparar o campo `Valor` de cada item com `N`.

### 8.5 - Se `Valor == N`:

* Incrementar o contador.

### 8.6 - Ao terminar o percurso:

* Retornar a quantidade de ocorrências encontradas.

---

## 9 - Função para trocar valores

### 9.1 - Receber como parâmetros:

* Uma lista encadeada;
* O valor original;
* O novo valor.

### 9.2 - Percorrer todos os itens da lista.

### 9.3 - Comparar o valor de cada item com o valor original.

### 9.4 - Quando encontrar uma ocorrência:

* Substituir o valor original pelo novo valor.

### 9.5 - Continuar percorrendo a lista para trocar todas as ocorrências.

### 9.6 - Após o processamento:

* Imprimir a lista resultante utilizando a função `Imprimir_Lista`.

---

## 10 - Função para dividir uma lista

### 10.1 - Receber como parâmetros:

* Uma lista encadeada;
* Um número inteiro `N`.

### 10.2 - Criar duas novas listas:

* Lista dos elementos maiores que `N`;
* Lista dos elementos menores que `N`.

### 10.3 - Percorrer todos os elementos da lista original.

### 10.4 - Para cada elemento:

#### 10.4.1 - Se `Valor > N`:

* Inserir o elemento na lista dos maiores.

#### 10.4.2 - Se `Valor < N`:

* Inserir o elemento na lista dos menores.

#### 10.4.3 - Se `Valor == N`:

* Não inserir em nenhuma das duas listas.

### 10.5 - Após o processamento:

* Imprimir a lista dos maiores;
* Imprimir a lista dos menores.

### 10.6 - Considerar que a lista original é qualquer lista não ordenada.

---

## 11 - Função para verificar se um valor existe

### 11.1 - Receber como parâmetros:

* Uma lista encadeada;
* Um valor inteiro.

### 11.2 - Percorrer a lista procurando o valor.

### 11.3 - Se encontrar:

* Retornar `1`.

### 11.4 - Se chegar ao final da lista sem encontrar:

* Retornar `0`.

### 11.5 - Essa função pode ser utilizada como função auxiliar para a interseção.

---

## 12 - Função de interseção das listas

### 12.1 - Receber como parâmetros:

* Lista 1;
* Lista 2.

### 12.2 - Criar uma nova lista para armazenar o resultado.

### 12.3 - Percorrer todos os elementos da primeira lista.

### 12.4 - Para cada elemento da primeira lista:

* Verificar se ele também existe na segunda lista.

### 12.5 - Se o elemento existir nas duas listas:

* Inserir o elemento na lista resultado.

### 12.6 - Continuar até percorrer toda a primeira lista.

### 12.7 - Retornar a lista resultante.

### 12.8 - Após o retorno:

* Imprimir a lista de interseção utilizando `Imprimir_Lista`.

### 12.9 - Considerar que as duas listas podem ser quaisquer listas não ordenadas.

---

## 13 - Implementação da função `main`

### 13.1 - Inicializar o programa.

### 13.2 - Criar a Lista 1.

### 13.3 - Inicializar a Lista 1.

### 13.4 - Criar a Lista 2.

### 13.5 - Inicializar a Lista 2.

### 13.6 - Chamar a função `Menu`.

### 13.7 - Encerrar o programa quando o usuário escolher a opção de saída.

---

# Ordem recomendada para implementação

1. Estruturas `Item` e `Lista`;
2. `Ini_Lista`;
3. `Lista_Vazia`;
4. `Criar_Lista`;
5. `Criar_Item`;
6. `Inserir_Item`;
7. `Remover_Item`;
8. `Imprimir_Lista`;
9. `Comprimento_Lista`;
10. `Contar_Valor`;
11. `Trocar_Valor`;
12. `Dividir_Lista`;
13. `Existe_Valor`;
14. `Inter_Lista`;
15. `Menu`;
16. `main`.
*/