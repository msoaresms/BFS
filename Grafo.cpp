#include "Grafo.h"

void Grafo::destroi() {
    delete this->adj;
    this->setOrdem(0);
    this->setTamanho(0);
}

void Grafo::inicializar(int pN) {
    if (this->getOrdem() != 0) { this->destroi(); }
    this->setOrdem(pN);
    this->setTamanho(0);
    this->adj = new vector<int>[pN+1];
}

void Grafo::inserirAresta(Vertex u, Vertex v) {
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
    this->setTamanho(this->getTamanho()+1);
}

void Grafo::mostrar() {
    for (int i = 1; i <= this->getOrdem(); i++){
        cout << "v[" << i << "] = ";
        vector<int> aux = adj[i];
        for (int x : aux) {
            cout << x << ", ";
        }
        cout << endl;
    }
}