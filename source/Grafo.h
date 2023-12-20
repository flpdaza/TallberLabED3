#pragma once
#include <iostream>
#include <limits.h>

#define INF INT_MAX;

using namespace std;

class Grafo{
    private:
    int matriz[299][299];
    public:
    Grafo();
    void agregarConexion(int, int, int);
    void bellmanFord(int);
};

Grafo::Grafo(){
    for(int i = 0; i < 299; i++){
        for(int j = 0; j < 299; j++){
            matriz[i][j] = INF;
        }
    }
    for(int i = 0; i < 299; i++){
        matriz[i][i] = 0;
    }
}


void Grafo::agregarConexion(int origen, int destino, int peso){
   matriz[origen][destino] = peso;
}