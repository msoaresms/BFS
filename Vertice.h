#ifndef BFS_VERTICE_H
#define BFS_VERTICE_H


class Vertice {
    private:
        int numVertice, cor, distancia, predecessor;

    public:
        Vertice() {}
        Vertice(int pNumVertice) { this->setNumVertice(pNumVertice); }

        int getNumVertice() { return this->numVertice; }
        void setNumVertice(int pNumVertice) { this->numVertice = pNumVertice; }
        int getCor() { return this->cor; }
        void setCor(int pCor) { this->cor = pCor; }
        int getDistancia() { return this->distancia; }
        void setDistancia(int pDistancia) { this->distancia = pDistancia; }
        int getPredecessor() { return this->predecessor; }
        void setPredecessor(int pPredecessor) { this->predecessor = pPredecessor; }
    };

#endif //BFS_VERTICE_H
