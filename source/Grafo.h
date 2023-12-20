#pragma once
#include <iostream>
#include <limits>


#define INF INT_MAX;

using namespace std;

class Grafo(){
    int matriz[][];
    public:
    Grafo(int);
    void agregarConexion(int, int, int);
    void bellmanFord(int);
};

Grafo::Grafo(int cantServidores){
    this -> matriz[cantServidores][cantServidores];
    for(int i = 0; i < cantServidores; i++){
        for(int j = 0; j < cantServidores; j++){
            matriz[i][j] = INF;
        }
    }

    for(int i = 0; i < cantServidores; i++){
        matriz[i][i] = 0;
    }
}

void agregarConexion(int origen, int destino, int peso){
    matriz[origen][destino] = peso;
}