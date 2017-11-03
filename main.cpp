#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#include "Grafo.h"
#include "Vertice.h"
using namespace std;

vector<Vertice> BFS(Grafo g, Vertex s) {
    vector<Vertex> * listaAdj = g.getAdj();
    vector<Vertice> vertices(g.getOrdem()+1);
    for (int i = 0; i <= g.getOrdem(); i++) {
        vertices[i].setNumVertice(i);
        vertices[i].setCor(0);
        vertices[i].setDistancia(numeric_limits<int>::max());
        vertices[i].setPredecessor(-1);
    }
    vertices[s].setCor(1);
    vertices[s].setDistancia(0);
    vertices[s].setPredecessor(-1);

    queue<Vertice> fila;
    fila.push(vertices[s]);
    while (!fila.empty()) {
        Vertice u = fila.front();
        fila.pop();
        vector<Vertex> aux = listaAdj[u.getNumVertice()];
        for (int i : aux) {
            if (vertices[i].getCor() == 0) {
                vertices[i].setCor(1);
                vertices[i].setDistancia(u.getDistancia()+1);
                vertices[i].setPredecessor(u.getNumVertice());
                fila.push(vertices[i]);
            }
        }
        vertices[u.getNumVertice()].setCor(2);
    }
    return vertices;
}

int main() {
    Grafo grafo(5);

    grafo.inserirAresta(1,2);
    grafo.inserirAresta(1,3);
    grafo.inserirAresta(2,5);
    grafo.inserirAresta(3,4);
    grafo.inserirAresta(4,5);

    vector<Vertice> bfsResultado = BFS(grafo, 1);

    return 0;
}