// Uma arvore binario é um grafo
//
// Vantagem Pesquisa rápida
//
// feito por raiz, nó e arestas
//
// Quando um nó não possui filho chama-se folha
//
// Cada nó pode ter no maximo dois filhos
//
// Os elementos da subarvore a esquerda são menores que a raiz, e da subarvore a direita
// maior que a raiz
// Não pode haver chave repetida
#include <iostream>

using namespace std;

class Node {
  private:
    Node *left, *right;
    int key;
  public:
    Node( int key ) {
      this->key = key;
      this->left = NULL;
      this->right = NULL;
    }
    int getKey() {
      return this->key;
    }
    Node *getLeft() {
      return this->left;
    }
    Node *getRight() {
      return this->right;
    }

    void setLeft(Node* node)
    {
      this->left = node;
    }
    void setRight(Node* node)
    {
      this->right = node;
    }
};

class Tree {
  private:
    Node *root;
  public:
    Tree() {
      root = NULL;
    }
    void insert(int key) {
      if(root == NULL){
        root = new Node(key);
      }else {
        insertAux(root, key);
      }
    }
    void insertAux(Node *node, int key) {
      if ( key < node->getKey()) {
        if(node->getLeft() == NULL) {
          Node *new_node = new Node(key);
          node->setLeft(new_node);
        } else {
          insertAux(node->getLeft(), key);
        }
      } else if(key > node->getKey()) {
        if(node->getRight() == NULL) {
          Node *new_node = new Node(key);
          node->setRight(new_node);
        }else {
          insertAux(node->getRight(), key);
        }
      }
    }
    Node * getRoot() {
      return root;
    }

    // em ordem

    void in_order(Node *node) {
      if ( node != NULL ) {
        in_order(node->getLeft());
        cout << node->getKey() << endl;
        in_order(node->getRight());
      }
    }
    // em pre ordem
    // centro, esquerda, direita
    void in_be_order(Node*node) {
      if ( node != NULL ) {
        cout << node->getKey() << endl;
        in_order(node->getLeft());
        in_order(node->getRight());
    }
    }
    // pre ordem
    void in_after_order(Node*node) {
      if ( node != NULL ) {
        in_order(node->getRight());
        in_order(node->getLeft());
        cout << node->getKey() << endl;
    }
    }
};


int main(void) {
  Tree tree;

  tree.insert(8);
  tree.insert(10);
  tree.insert(14);
  tree.insert(13);
  tree.insert(3);
  tree.insert(1);
  tree.insert(6);
  tree.insert(4);
  tree.insert(7);

  cout << "Percorrendo em ordem" << endl;
  tree.in_order(tree.getRoot());
  cout << "Percorrendo em PRE ordem" << endl;
  tree.in_be_order(tree.getRoot());
  cout << "Percorrendo em POS ordem" << endl;
  tree.in_after_order(tree.getRoot());

}
