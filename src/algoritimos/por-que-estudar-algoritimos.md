# Por que aprender algoritmos ?

É a base da computação

É usado em hardware rápido, redes, interface gráficas etc.

## O papel dos algoritmos na computação

O a programação não passa de transformar entradas em saídas e algoritmos são
essenciais para está tarefa! A definição de um algoritmo "Qualquer procedimento
que toma um valor ou conjunto de valores como entrada e produz uma valor ou
conjunto de valores como saída"

Exemplo algoritmo de ordenação crescente:

```C
int sort(int size, int *vector) {
  int aux;
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      if (vector[i+1] < vector[i]) {
        aux = vector[i+1];
        vector[i+1] = vector[i];
        vector[i] = aux;
      }
    }
  }
  return 0;
}
```

## É usado em todas as áreas do conhecimento humano.

* Biologia - Genoma Humano.

* Internet

* Comercio Eletrônico

* Industria

##






