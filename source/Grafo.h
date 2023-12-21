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
    ~Grafo();
    void agregarConexion(string, string, double);
    void mostrarCamino(string, string, double);
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

Grafo::~Grafo(){}
//Funcion que muestra el camino mas corto entre dos servidores
void Grafo::mostrarCamino(string origen, string destino, double partes){
    int ori = stoi(origen);
    int dest = stoi(destino);
    double tiempo = matriz[ori][dest];
    double tiempoTotal;
    cout<<endl;
    for(int i = 0; i < partes; i++){
        cout<<"Parte "<<i+1<<": "<<ori<<" -> " <<dest<<" Tiempo: "<<tiempo<<" segundos"<<endl;
        tiempoTotal += tiempo;
    }
    cout<<endl;
    cout<<"El tiempo total fue: "<<tiempoTotal<<" segundos"<<endl;
    cout<<endl;
}
//Funcion que agrega una conexion entre dos servidores
void Grafo::agregarConexion(string origen, string destino,double peso){
    int ori = stoi(origen);
    int dest = stoi(destino);
    matriz[ori][dest] = peso;
}
//Funcion que imprime la matriz de adyacencia
void Grafo::imprimir(){
    for(int i = 0; i < 299; i++){
        for(int j = 0; j < 299; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}