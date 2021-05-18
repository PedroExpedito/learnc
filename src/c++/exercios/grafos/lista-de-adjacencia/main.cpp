// lista de adjacencia
// usa  memoria na proporção do numero de arestas
// é muito fácil saber os vizinhos
// é lento para verificar se um é vizinho do outro
//
// GRAFO SEM PESO NAS ARESTAS

#include <algorithm> // função find
#include <iostream>
#include <list>

using namespace std;

class Grafo {
  int V;          // numero de vetices
  list<int> *adj; // ponteiro para um array contendo as listas de adjacencia
public:
  Grafo(int V);
  void adicionarAresta(int v1, int v2); // adiciona uma aresta ao grafo

  int obterGrauDeSaida(int v);

  bool existeVizinho(int v1, int v2); // verifica se v2 é vizinho de v1
};

Grafo::Grafo(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2) {
  adj[v1].push_back(v2); // adiciona vertice v2 a lista de vertices de v1
}

int Grafo::obterGrauDeSaida(int v) {
  // tamanho da lista quantidade de vizinhos
  return adj[v].size();
}

bool Grafo::existeVizinho(int v1, int v2) {
  if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()){
    return true;
  }
  return false;
}
int main() {
  Grafo grafo(4);

  // adicionar as arestas

  grafo.adicionarAresta(0,1);
  grafo.adicionarAresta(0,3);
  grafo.adicionarAresta(1,2);
  grafo.adicionarAresta(3,1);
  grafo.adicionarAresta(3,2);

  // mostrando os graus de saída
  cout << "Grau de saida do vertice 1: " << grafo.obterGrauDeSaida(1) << endl;
  cout << "Grau de saida do vertice 3: " << grafo.obterGrauDeSaida(3) << endl;
  cout << "O 1 é vizinho do 0 ? " << grafo.existeVizinho(0,2) << endl;

  return 0;
}
