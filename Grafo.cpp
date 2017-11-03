#include "Grafo.h"

void Grafo::destroi() {
    this->adj.clear();
    this->setOrdem(0);
    this->setTamanho(0);
}

void Grafo::inicializar(int pN) {
    if (this->getOrdem() != 0) { this->destroi(); }
    this->setOrdem(pN);
    this->setTamanho(0);

    for (int i = 0; i <=pN; i++) { this->adj.push_back(Lista<Vertex>()); }
}

void Grafo::inserirAresta(Vertex u, Vertex v) {
    this->adj[u].insere(v);
    this->adj[v].insere(u);
    this->setTamanho(this->getTamanho()+1);
}

void Grafo::mostrar() {
    for (int i = 1; i <= this->getOrdem(); i++) {
        cout << "v[" << i << "] = ";
        Lista<Vertex> aux = adj[i];
        No<Vertex> * aux2 = aux.getFrente()->getProx();
        while (aux2 != nullptr) {
            cout << aux2->getItem() << " ";
            aux2 = aux2->getProx();
        }
        cout << endl;
    }
}