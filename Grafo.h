#ifndef BFS_GRAFO_H
#define BFS_GRAFO_H

#include <iostream>
#include <vector>
using namespace std;

typedef int Vertex;
class Grafo {
private:
    vector<Vertex> * adj;
    int ordem, tamanho;
    void destroi();

public:
    Grafo(int pN){ inicializar(pN); }

    void inicializar(int);
    void inserirAresta(Vertex, Vertex);
    void mostrar();

    int getOrdem() { return this->ordem; }
    void setOrdem(int pOrdem) { this->ordem = pOrdem; }
    int getTamanho() { return this->tamanho; }
    void setTamanho(int pTamanho) { this->tamanho = pTamanho; }
    vector<Vertex> * getAdj() { return this->adj; }
};


#endif //BFS_GRAFO_H
