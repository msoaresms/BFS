#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef int Vertex;

class Vertice {
private:
    pair<int, int> coordenada;
    int numVertice, cor, distancia, predecessor;

public:
    Vertice() {}
    Vertice(int pNumVertice) {
        this->setNumVertice(pNumVertice);
    }
    Vertice(pair<int, int> pCoordenada, int pNumVertice) {
        this->setCoordenada(pCoordenada);
        this->setNumVertice(pNumVertice);
    }

    pair<int, int> getCoordenada() { return this->coordenada; }
    void setCoordenada(pair<int, int> pCoordenada) { this->coordenada = pCoordenada; }
    int getNumVertice() { return this->numVertice; }
    void setNumVertice(int pNumVertice) { this->numVertice = pNumVertice; }
    int getCor() { return this->cor; }
    void setCor(int pCor) { this->cor = pCor; }
    int getDistancia() { return this->distancia; }
    void setDistancia(int pDistancia) { this->distancia = pDistancia; }
    int getPredecessor() { return this->predecessor; }
    void setPredecessor(int pPredecessor) { this->predecessor = pPredecessor; }
};

class Grafo {
private:
    vector<Vertice> vertices;
    vector<Vertex> *adj;
    int ordem, tamanho;
    void destroi();

public:
    Grafo(int pN){ inicializar(pN); }

    void inicializar(int);
    void inserirAresta(Vertex, Vertex);
    void mostrar();
    void BFS(Vertex);

    int getOrdem() { return this->ordem; }
    void setOrdem(int pOrdem) { this->ordem = pOrdem; }
    int getTamanho() { return this->tamanho; }
    void setTamanho(int pTamanho) { this->tamanho = pTamanho; }
};

void Grafo::destroi() {
    delete(this->adj);
    this->setOrdem(0);
    this->setTamanho(0);
}
void Grafo::inicializar(int pN) {
    if (this->getOrdem() != 0) { this->destroi(); }
    this->setOrdem(pN);
    this->setTamanho(0);
    this->adj = new vector<int>[pN+1];

    for (int i = 0; i <=pN; i++){
        Vertice aux(i);
        this->vertices.push_back(aux);
    }
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
        for (int j = 0; j < aux.size(); j++) {
            cout << aux[j] << "  ";
        }
        cout << endl;
    }
}
void Grafo::BFS(Vertex s) {
    for (int i = 1; i < this->vertices.size(); i++){
        vertices[i].setCor(0);
        vertices[i].setDistancia(numeric_limits<int>::max());
        vertices[i].setPredecessor(-1);
    }
    vertices[s].setCor(1);
    vertices[s].setDistancia(0);
    vertices[s].setPredecessor(-1);

    queue<Vertice> fila;
    fila.push(vertices[s]);
    while (fila.size() != 0) {
        Vertice u = fila.front();
        fila.pop();
        vector<Vertex> aux = adj[u.getNumVertice()];
        for (int i = 0; i < aux.size(); i++) {
            if (vertices[aux[i]].getCor() == 0){
                vertices[aux[i]].setCor(1);
                vertices[aux[i]].setDistancia(u.getDistancia()+1);
                vertices[aux[i]].setPredecessor(u.getNumVertice());
                fila.push(vertices[aux[i]]);
            }
        }
        vertices[u.getNumVertice()].setCor(2);
    }
}

int main() {
    Grafo g(5);

    g.inserirAresta(1,2);
    g.inserirAresta(2,3);
    g.inserirAresta(3,4);
    g.inserirAresta(4,5);
    g.inserirAresta(5,1);

    g.BFS(1);

    return 0;
}