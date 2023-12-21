#pragma once
#include <iostream>
#include <limits.h>
#include "NodoServidores.h"

#define INF INT_MAX;

using namespace std;

class Grafo{
    private:
    int matriz[299][299];
    public:
    Grafo();
    void agregarConexion(string, string, int);
    void bellmanFord(int);
    void imprimir();
};

Grafo::Grafo(){
    for(int i = 0; i < 299; i++){
        for(int j = 0; j < 299; j++){
            matriz[i][j] = -1;
        }
    }
    for(int i = 0; i < 299; i++){
        matriz[i][i] = 0;
    }
}


void Grafo::agregarConexion(string origen, string destino,int peso){
    int ori = stoi(origen);
    int dest = stoi(destino);
   matriz[1][2] = peso;
}

void Grafo::imprimir(){
    for(int i = 0; i < 299; i++){
        for(int j = 0; j < 299; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}